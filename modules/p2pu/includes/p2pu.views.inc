<?php
// $Id$

/**
 * Implementation of hook_views_pre_build().
 */
function p2pu_views_pre_build(&$view) {
  // When OG public nodes are in play it is (very) possible to get
  // duplicate rows because of the node_access() JOIN and WHERE
  // combination. This is a rather brute force method of making
  // sure this doesn't affect our Views without going through every
  // default view and setting the distinct flag.
  global $user;
  if ($user->uid != 0 && !user_access('administer nodes') && in_array($view->base_table, array('node', 'comments'), TRUE)) {
    $view->display_handler->set_option('distinct', 1);
  }
}


/**
 * Implementation of hook_views_handlers().
 */
function p2pu_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'p2pu') .'/includes',
    ),
    'handlers' => array(
      'p2pu_handler_field_activity' => array(
        'parent' => 'views_handler_field',
      ),
      'p2pu_handler_field_activity_timestamp' => array(
        'parent' => 'p2pu_handler_field_activity',
      ),
      'p2pu_handler_field_activity_upload' => array(
        'parent' => 'p2pu_handler_field_activity',
      ),
    ),
  );
}


/**
 * Implementation of hook_views_data().
 */
function p2pu_views_data() {
  $data = array();
  $data['comments']['p2pu_activity'] = array(
    'real field' => 'cid',
    'title' => t('Activity'),
    'help' => t("Poor man's activity field."),
    'field' => array('handler' => 'p2pu_handler_field_activity'),
  );
  $data['comments']['p2pu_activity_timestamp'] = array(
    'real field' => 'cid',
    'title' => t('Activity timestamp'),
    'help' => t("Timestamp for poor man's activity field."),
    'field' => array('handler' => 'p2pu_handler_field_activity_timestamp'),
  );
  $data['comments']['p2pu_activity_upload'] = array(
    'real field' => 'cid',
    'title' => t('Activity upload'),
    'help' => t("Upload for poor man's activity field."),
    'field' => array('handler' => 'p2pu_handler_field_activity_upload'),
  );
  return $data;
}



/**
 * Implementation of hook_views_query_alter().
 */
function p2pu_views_query_alter(&$view, &$query) {
  if (!empty($view->p2pu_activity)) {
    // Skip Views' query execution - we will do it ourselves.
    $view->executed = TRUE;

    $main = drupal_clone($query);
    $subquery = drupal_clone($query);
    $args = $query->get_where_args();

    // Subquery: Retrieves node posts & updates.
    // NULL any fields that reference the comments table and remove the join completely.
    foreach ($subquery->fields AS $key => $field) {
      if ($field['table'] === 'comments') {
        $subquery->fields[$key]['table'] = NULL;
        $subquery->fields[$key]['field'] = "NULL";
      }
    }
    if (isset($subquery->tables['node']['comments'])) {
      unset($subquery->tables['node']['comments']);
    }
    if (isset($subquery->table_queue['comments'])) {
      unset($subquery->table_queue['comments']);
    }
    $subquery = strtr($subquery->query(), array('***P2PU_ACTIVITY_TIMESTAMP***' => 'node.changed'));

    // Main: Retrieve "only" comments.

    // Because of the node_access change introduced in Drupal 6.14, distinct
    // has been added to most queries to prevent duplicate rows from appearing.
    // For this query, which pulls comments, we need to remove DISTINCT from
    // nid and add one to cid. But since cid has been pushed into the middle of
    // the field stack (and it is not easy to reorder fields), we use a
    // GROUP BY cid instead.
    $main->distinct = FALSE;
    if (isset($main->fields['comments_cid'])) {
      $main->add_groupby($main->fields['comments_cid']['alias']);
    }

    // Switch LEFT to INNER JOIN against comments table.
    if (isset($main->table_queue['comments']['join'])) {
      $main->table_queue['comments']['join']->type = 'INNER';
    }
    // Move node and comment to the beginning of the stack to ensure that any
    // joins we switch further on in the stack have access to comments table.
    $queue = array(
      'node' => $main->table_queue['node'],
      'comments' => $main->table_queue['comments'],
    );
    foreach ($main->table_queue as $k => $v) {
      if (($k !== 'node') && ($k !== 'comments')) {
        $queue[$k] = $v;
      }
    }
    $main->table_queue = $queue;
    // Alter join to the user table to go through comments,
    if (isset($main->table_queue['users']['join'])) {
      $main->table_queue['users']['join']->left_table = 'comments';
    }
    // Alter joins to the upload, files tables to go through comment_upload instead.
    if (isset($main->table_queue['upload']['join'])) {
      $main->table_queue['upload']['join']->left_table = 'comments';
      $main->table_queue['upload']['join']->left_field= 'cid';
      $main->table_queue['upload']['join']->field= 'cid';
      $main->table_queue['upload']['join']->table = 'comment_upload';
    }
    $main = strtr($main->query(), array('***P2PU_ACTIVITY_TIMESTAMP***' => 'comments.timestamp'));

    // SQL rewrite.
    $subquery = db_rewrite_sql($subquery, $view->base_table, $view->base_field, array('view' => &$view));
    $main     = db_rewrite_sql($main, $view->base_table, $view->base_field, array('view' => &$view));

    // Views query token replacements.
    $replacements = module_invoke_all('views_query_substitutions', $view);
    $subquery = str_replace(array_keys($replacements), $replacements, $subquery);
    $main     = str_replace(array_keys($replacements), $replacements, $main);
    if (is_array($args)) {
      foreach ($args as $id => $arg) {
        $args[$id] = str_replace(array_keys($replacements), $replacements, $arg);
      }
    }

    // UNION. We use UNION ALL (as opposed to the implied UNION DISTINCT)
    // since our two queries above should have no common rows.
    // See: http://www.mysqlperformanceblog.com/2007/10/05/union-vs-union-all-performance
    $main = str_replace('ORDER BY', " UNION ALL ({$subquery}) ORDER BY", $main);

    // Execute query and build result set.
    $count_query = "SELECT COUNT(*) FROM ($main) AS count";
    $result = pager_query($main, $view->pager['items_per_page'], 0, $count_query, array_merge($args, $args));
    while ($row = db_fetch_object($result)) {
      $view->result[] = $row;
    }
  }
}
