<?php
// $Id: admin.inc,v 1.1.2.5 2009/11/14 15:58:44 markuspetrux Exp $

/**
 * @file
 * Administrative interface for the Field Permissions module.
 */

/**
 * Implementation of hook_menu().
 */
function _field_permissions_menu() {
  $items = array();
  $items['admin/content/types/field_permissions'] = array(
    'title' => 'Permissions',
    'page callback' => 'field_permissions_overview',
    'access arguments' => array('administer field permissions'),
    'file' => 'includes/admin.inc',
    'type' => MENU_LOCAL_TASK,
    'weight' => 5,
  );
  $items['admin/content/types/field_permissions/overview'] = array(
    'title' => 'Overview',
    'type' => MENU_DEFAULT_LOCAL_TASK,
    'weight' => -10,
  );
  $items['admin/content/types/field_permissions/troubleshooting'] = array(
    'title' => 'Troubleshooting',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('field_permissions_troubleshooting_form'),
    'access arguments' => array('administer field permissions'),
    'file' => 'includes/admin.inc',
    'type' => MENU_LOCAL_TASK,
    'weight' => 10,
  );
  $items['field_permissions/autocomplete'] = array(
    'title' => 'Field permissions autocomplete',
    'page callback' => 'field_permissions_autocomplete',
    'access arguments' => array('administer field permissions'),
    'file' => 'includes/admin.inc',
    'type' => MENU_CALLBACK,
  );
  return $items;
}

/**
 * Obtain the list of field permissions.
 */
function field_permissions_list($field_label = '') {
  return array(
    'create' => array(
      'label' => t('Create field'),
      'description' => t('Create @field (edit on node creation).', array('@field' => $field_label)),
    ),
    'edit' => array(
      'label' => t('Edit field'),
      'description' => t('Edit @field, regardless of node author.', array('@field' => $field_label)),
    ),
    'edit own' => array(
      'label' => t('Edit own field'),
      'description' => t('Edit own @field on node created by the user.', array('@field' => $field_label)),
    ),
    'view' => array(
      'label' => t('View field'),
      'description' => t('View @field, regardless of node author.', array('@field' => $field_label)),
    ),
    'view own' => array(
      'label' => t('View own field'),
      'description' => t('View own @field on node created by the user.', array('@field' => $field_label)),
    ),
  );
}

/**
 * Implementation of hook_perm().
 */
function _field_permissions_perm() {
  $perms = array('administer field permissions');
  foreach (content_fields() as $field_name => $field) {
    if (!empty($field['field_permissions'])) {
      foreach (array_keys(field_permissions_list()) as $permission_type) {
        if (!empty($field['field_permissions'][$permission_type])) {
          $perms[] = $permission_type .' '. $field_name;
        }
      }
    }
  }
  return $perms;
}

/**
 * Implementation of hook_field_settings_alter().
 */
function _field_permissions_field_settings_alter(&$settings, $op, $field) {
  switch ($op) {
    case 'form':
      $field_permissions = array();
      foreach (field_permissions_list($field['widget']['label']) as $permission_type => $permission_info) {
        $field_permissions[$permission_type] = $permission_info['description'];
      }
      $settings['field_permissions'] = array(
        '#title' => t('Field permissions'),
        '#type' => 'checkboxes',
        '#checkall' => TRUE,
        '#options' => $field_permissions,
        '#default_value' => (isset($field['field_permissions']) && is_array($field['field_permissions']) ? array_filter($field['field_permissions']) : array()),
        '#description' => t('Use these options to enable role based permissions for this field.
When permissions are enabled, access to this field is denied by default and explicit permissions should be granted to the proper user roles from the <a href="@admin-permissions">permissions administration</a> page.
On the other hand, when these options are disabled, field permissions are inherited from node view and/or edit permissions. In example, users allowed to view a particular node will also be able to view this field, and so on.', array(
          '@admin-permissions' => url('admin/user/permissions'),
        )),
        '#weight' => -1,
      );
      // Hide the option to non-privileged users.
      if (!user_access('administer field permissions')) {
        $settings['field_permissions']['#type'] = 'value';
        $settings['field_permissions']['#value'] = $settings['field_permissions']['#default_value'];
      }
      break;

    case 'save':
      $settings[] = 'field_permissions';
      break;
  }
}

/**
 * Menu callback; Field permissions overview.
 */
function field_permissions_overview() {
  drupal_add_css(drupal_get_path('module', 'field_permissions') .'/css/field_permissions.admin.css');

  $headers = array(t('Field name'), t('Field type'), t('Used in'));
  foreach (field_permissions_list() as $permission_type => $permission_info) {
    $headers[] = array('data' => $permission_info['label'], 'class' => 'field-permissions-header');
  }

  // Load list of fields and types in the system.
  $content_fields = content_fields();
  uasort($content_fields, '_field_permissions_sort_fields');
  $field_types = _content_field_types();
  $destination = drupal_get_destination();

  $rows = array();
  foreach ($content_fields as $field_name => $field) {
    $row = array(
      ($field['locked'] ? t('@field (Locked)', array('@field' => $field['widget']['label'])) : check_plain($field['widget']['label'])),
      $field_types[$field['type']]['label'],
    );

    $types = array();
    $result = db_query("SELECT nt.name, nt.type FROM {". content_instance_tablename() ."} nfi ".
    "LEFT JOIN {node_type} nt ON nt.type = nfi.type_name ".
    "WHERE nfi.field_name = '%s' ".
    // Keep disabled modules out of table.
    "AND nfi.widget_active = 1 ".
    "ORDER BY nt.name ASC", $field_name);
    while ($type = db_fetch_array($result)) {
      $content_type = content_types($type['type']);
      if ($field['locked']) {
        $types[] = check_plain($type['name']);
      }
      else {
        $types[] = l($type['name'], 'admin/content/node-type/'. $content_type['url_str'] .'/fields/'. $field_name, array('query' => $destination));
      }
    }
    $row[] = implode(', ', $types);

    $field_permissions = (isset($field['field_permissions']) && is_array($field['field_permissions']) ? array_filter($field['field_permissions']) : array());
    foreach (array_keys(field_permissions_list()) as $permission_type) {
      if (!empty($field_permissions[$permission_type])) {
        $status = 'on';
        $title = t('Enabled');
      }
      else {
        $status = 'off';
        $title = t('Disabled');
      }
      $row[] = array('data' => '<span class="field-permissions-status field-permissions-status-'. $status .'" title="'. check_plain($title) .'"></span>', 'class' => 'field-permissions-cell');
    }

    $rows[] = array('data' => $row, 'class' => ($field['locked'] ? 'menu-disabled' : ''));
  }

  // Allow external modules alter the table headers and rows.
  foreach (module_implements('field_permissions_overview_alter') as $module) {
    $function = $module .'_field_permissions_overview_alter';
    $function($headers, $rows);
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => t('No fields have been defined for any content type yet.'), 'colspan' => count($headers), 'class' => 'field-permissions-cell'));
  }

  return theme('table', $headers, $rows);
}

/**
 * Function used by uasort to sort structured arrays by title.
 */
function _field_permissions_sort_fields($a, $b) {
  $a_text = (is_array($a) && isset($a['widget']['label'])) ? $a['widget']['label'] : '';
  $b_text = (is_array($b) && isset($b['widget']['label'])) ? $b['widget']['label'] : '';
  return strcasecmp($a_text, $b_text);
}

/**
 * Menu callback; Field permissions autocomplete.
 */
function field_permissions_autocomplete($type = '', $string = '') {
  $matches = array();
  if (!empty($string)) {
    if ($type == 'nodes') {
      $result = db_query_range(db_rewrite_sql("SELECT n.nid, n.title FROM {node} n WHERE LOWER(n.title) LIKE LOWER('%%%s%%') ORDER BY n.title"), $string, 0, 10);
      while ($row = db_fetch_object($result)) {
        $matches[$row->title ." [nid:$row->nid]"] = '<div class="reference-autocomplete">'. check_plain($row->title) . '</div>';
      }
    }
    elseif ($type == 'users') {
      $result = db_query_range("SELECT name FROM {users} WHERE LOWER(name) LIKE LOWER('%%%s%%') AND uid <> 0 ORDER BY name", $string, 0, 10);
      while ($row = db_fetch_object($result)) {
        $matches[$row->name] = check_plain($row->name);
      }
    }
  }
  drupal_json($matches);
}

/**
 * Menu callback; Field permissions troubleshooting form.
 */
function field_permissions_troubleshooting_form(&$form_state, $nid = NULL, $field_name = NULL, $uid = NULL) {
  $form = array();
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Report options'),
  );
  $node = (!empty($nid) ? node_load($nid) : NULL);
  $form['options']['node'] = array(
    '#type' => 'textfield',
    '#title' => t('Node'),
    '#default_value' => (!empty($node->nid) ? $node->title ." [nid:$node->nid]" : ''),
    '#autocomplete_path' => 'field_permissions/autocomplete/nodes',
    '#required' => TRUE,
    '#description' => t('Select the node that you want to check access to.'),
  );
  if (!empty($node->nid)) {
    $form['#node'] = $node;
  }

  if (empty($node->type)) {
    $form['options']['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
    );
    return $form;
  }

  $content_type = content_types($node->type);
  $content_fields = $content_type['fields'];
  uasort($content_fields, '_field_permissions_sort_fields');
  $fields = array('' => '-- '. t('Select field') .' --');
  foreach ($content_fields as $field) {
    $fields[$field['field_name']] = t('@field-label (@field-name)', array('@field-label' => $field['widget']['label'], '@field-name' => $field['field_name']));
  }
  $field = (!empty($field_name) && !empty($content_fields[$field_name]) ? $content_fields[$field_name] : NULL);
  $form['options']['field'] = array(
    '#type' => 'select',
    '#title' => t('Field'),
    '#options' => $fields,
    '#default_value' => (!empty($field) ? $field_name : NULL),
    '#description' => t('Emulate access to the given node.'),
    '#description' => t('Select the field on the selected node that you want to check access to.'),
  );
  $form['#field'] = $field;

  $account = (!empty($uid) ? user_load($uid) : ($uid == 0 ? drupal_anonymous_user() : NULL));
  $form['options']['user'] = array(
    '#type' => 'textfield',
    '#title' => t('User'),
    '#size' => 30,
    '#maxlength' => 60,
    '#default_value' => (!empty($account->name) ? $account->name : ''),
    '#autocomplete_path' => 'field_permissions/autocomplete/users',
    '#description' => t('Select the user that you want to check. Access to the specified node will be checked using all different roles assigned to this user. Leave blank to check for %anonymous.', array('%anonymous' => variable_get('anonymous', t('Anonymous')))),
  );
  $form['#account'] = (!empty($account->uid) ? $account : NULL);

  if (!empty($form['#field'])) {
    $form['options']['#collapsible'] = $form['options']['#collapsed'] = TRUE;
  }
  $form['options']['node']['#disabled'] = TRUE;
  $form['options']['node']['#value'] = $form['options']['node']['#default_value'];

  $form['options']['check'] = array(
    '#type' => 'submit',
    '#value' => t('Check'),
  );
  $form['options']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
  );

  if (!empty($form['#field'])) {
    if (!isset($account->uid)) {
      $account = drupal_anonymous_user();
      $account->name = variable_get('anonymous', t('Anonymous'));
    }
    if ($node->uid == $account->uid) {
      $node_author = $account->name;
    }
    else {
      $node_account = user_load($node->uid);
      $node_author = $node_account->name;
    }
    $nodetype_name = node_get_types('name', $node->type);
    if (module_exists('i18ncontent')) {
      $nodetype_name = tt("nodetype:type:$node->type:name", $nodetype_name);
    }
    $form['report'] = array(
      '#type' => 'fieldset',
      '#title' => t('Report'),
      '#description' => t('This report simulates different operations to access the field %field-label in the node %node-title (nid: @node-nid), created by %node-author (uid: @node-uid), or creation of nodes of type %node-type, for each role assigned to user %user-name (uid: @uid). Move the mouse over each status icon to review detailed information about each test.', array(
        '%field-label' => (!empty($field['widget']['label']) ? $field['widget']['label'] : $field['field_name']),
        '%node-title' => $node->title,
        '@node-nid' => $node->nid,
        '%node-author' => $node_author,
        '@node-uid' => $node->uid,
        '%node-type' => $nodetype_name,
        '%user-name' => $account->name,
        '@uid' => $account->uid,
      )),
    );
  }

  return $form;
}

/**
 * Validate callback for the Field permissions troubleshooting form.
 */
function field_permissions_troubleshooting_form_validate($form, &$form_state) {
  if ($form_state['values']['op'] == t('Reset')) {
    return;
  }

  // Validate the node.
  $value = $form_state['values']['node'];
  preg_match('`^(?:\s*|(.*) )?\[\s*nid\s*:\s*([0-9]+)\s*\]\s*$`', $value, $matches);
  if (empty($matches)) {
    // No explicit nid.
    if (!($node = node_load(array('title' => $value)))) {
      form_set_error('node', t('Node: found no valid post with that title.'));
      return;
    }
  }
  else {
    // Explicit [nid:n].
    list(, $title, $nid) = $matches;
    if (($node = node_load($nid)) && !empty($title) && trim($title) != trim($node->title)) {
      form_set_error('node', t('Node: title mismatch. Please check your selection.'));
      return;
    }
    elseif (empty($node->nid)) {
      form_set_error('node', t('Node: found no valid post with that title.'));
      return;
    }
  }
  $form_state['values']['nid'] = $node->nid;

  // Validate the field against the node type.
  if (!empty($form['options']['field'])) {
    if (empty($form_state['values']['field'])) {
      form_set_error('field', t('Field: please, select a field.'));
      return;
    }
    else {
      $content_type = content_types($node->type);
      if (empty($content_type['fields'][$form_state['values']['field']])) {
        form_set_error('field', t('Field: %field does not exist in the selected node type.', array('%field' => $form['options']['field']['#options'][$form_state['values']['field']])));
        return;
      }
    }
  }

  // Validate the user.
  if (!empty($form_state['values']['user'])) {
    if (!($account = user_load(array('name' => $form_state['values']['user'])))) {
      form_set_error('user', t('User: user %name cannot be found.', array('%name' => $form_state['values']['user'])));
      return;
    }
    $form_state['values']['uid'] = $account->uid;
  }
}

/**
 * Submit callback for the Field permissions troubleshooting form.
 */
function field_permissions_troubleshooting_form_submit($form, &$form_state) {
  $url = 'admin/content/types/field_permissions/troubleshooting';
  if ($form_state['values']['op'] != t('Reset')) {
    $url .= '/'. $form_state['values']['nid'] .'/'. $form_state['values']['field'];
    if (!empty($form_state['values']['uid'])) {
      $url .= '/'. $form_state['values']['uid'];
    }
  }
  $form_state['redirect'] = $url;
}

/**
 * Render the Field permissions troubleshooting form.
 */
function theme_field_permissions_troubleshooting_form($form) {
  // Stop rendering if form has errors or no options have been supplied.
  if (form_get_errors() || empty($form['#node']) || empty($form['#field'])) {
    return drupal_render($form);
  }

  // Send javascript and stylesheets used for the troubleshooting report.
  $module_path = drupal_get_path('module', 'field_permissions');
  drupal_add_css($module_path .'/css/field_permissions.admin.css');
  drupal_add_js($module_path .'/js/field_permissions.tooltip.js');

  // Check access to the given field in the given node by the selected user.
  $base_node = &$form['#node'];
  $field = &$form['#field'];

  $base_account = (!empty($form['#account']) ? $form['#account'] : drupal_anonymous_user());
  $modules = module_implements('field_access');
  $permissions_list = field_permissions_list();
  $user_roles = ($base_account->uid == 1 ? array(-1 => t('site administrator (uid: 1)')) : $base_account->roles);

  $headers = array(t('User role'));
  foreach ($permissions_list as $permission_type => $permission_info) {
    $headers[] = array('data' => $permission_info['label'], 'class' => 'field-permissions-header');
  }
  $rows = array();
  foreach ($user_roles as $rid => $role_name) {
    $row = array(check_plain($role_name));
    foreach ($permissions_list as $permission_type => $permission_info) {
      // Prepare the user account.
      if ($rid == DRUPAL_ANONYMOUS_RID) {
        $testing_account = drupal_anonymous_user();
        $testing_account->name = variable_get('anonymous', t('Anonymous'));
      }
      else {
        $testing_account = drupal_clone($base_account);
        $testing_account->roles = array(DRUPAL_AUTHENTICATED_RID => $testing_account->roles[DRUPAL_AUTHENTICATED_RID]);
        if ($testing_account->uid != 1 && $rid != DRUPAL_AUTHENTICATED_RID) {
          $testing_account->roles[$rid] = $role_name;
        }
      }
      // Reset the static storage in user_access().
      user_access('access content', $testing_account, TRUE);

      // Prepare the node.
      $testing_node = drupal_clone($base_node);

      // Prepare the results.
      $results = array();
      $result = TRUE;

      if ($permission_type == 'view' || $permission_type == 'view own') {
        $op = 'view';
        $result = $results['node_access(view)'] = node_access('view', $testing_node, $testing_account);
      }
      else {
        $op = 'edit';
        if ($permission_type == 'create') {
          unset($testing_node->nid);
          $result = $results['node_access(create)'] = node_access('create', $testing_node->type, $testing_account);
        }
        else {
          $result = $results['node_access(update)'] = node_access('update', $testing_node, $testing_account);
        }
      }

      // Check access to field only when node access is granted.
      if ($result !== FALSE) {
        foreach ($modules as $module) {
          $key = $module .'_field_access('. $op .')';
          $results[$key] = module_invoke($module, 'field_access', $op, $field, $testing_account, $testing_node);
          if ($results[$key] === FALSE) {
            $result = FALSE;
          }
        }
      }

      if ($result !== FALSE) {
        $status = 'on';
        $title = t('Access allowed');
      }
      else {
        $status = 'off';
        $title = t('Access denied');
      }
      $icon = '<span class="field-permissions-status field-permissions-status-'. $status .'" title="'. check_plain($title) .'"></span>';
      $items = array();
      foreach ($results as $key => $result) {
        $items[] = $key .':&nbsp;'. check_plain(strtoupper(var_export($result, TRUE)));
      }
      $items = (!empty($items) ? '<div class="field-permissions-tooltip">'. theme('item_list', $items, t('Detailed results for %role -vs- %operation', array('%role' => $role_name, '%operation' => $permission_info['label']))) .'</div>' : '');
      $row[] = array('data' => $icon . $items, 'class' => 'field-permissions-cell');
    }
    $rows[] = $row;
  }

  $form['report']['table'] = array(
    '#type' => 'markup',
    '#value' => theme('table', $headers, $rows),
  );
  $output = drupal_render($form);

  return $output;
}
