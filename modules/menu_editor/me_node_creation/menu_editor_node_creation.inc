<?php


function menu_editor_node_creation_create_node($type, $mlid) {
  
  // store the values
  menu_editor_node_creation_create_node_values($type, $mlid);

  global $user;
  if (is_array($mlid)) {
    $mlid = $mlid['mlid'];
  }
  $mlid = (int)$mlid;
  
  $types = node_get_types();
  // Initialize settings:
  $node = array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => $type,
    'language' => ''
  );

  drupal_set_title(t('Create @name', array('@name' => $types[$type]->name)));
  
  require_once drupal_get_path('module', 'node') . '/node.pages.inc';
  $form = menu_editor_build_form($type . '_node_form', $node);
  
  return drupal_render($form);
}


function menu_editor_node_creation_create_node_values($type = NULL, $mlid = NULL) {
  static $_type, $_mlid;
  if (isset($type) && isset($mlid)) {
    $_type = $type;
    $_mlid = $mlid;
  }
  return isset($_type) ? array($_type, $_mlid) : array();
}


function menu_editor_node_creation_form_alter(&$form, &$form_state) {
  if($form['#id'] != 'node-form') {
    return;
  }
  
  list($type, $mlid) = menu_editor_node_creation_create_node_values();
  if (!isset($type) || !isset($mlid)) {
    return;
  }
  
  $q = db_query("SELECT * FROM {menu_links} WHERE mlid = %d", $mlid);
  $menu_item = db_fetch_object($q);
  if (!$menu_item) {
    return;
  }
  
  $form['menu'] = array(
    '#type' => 'markup',
    '#value' => t('The created node will be associated with the chosen menu item (@mlid).', array('@mlid' => $mlid)),
  );
  
  $form['title']['#default_value'] = $menu_item->link_title;
  $form['menu_editor_mlid'] = array(
    '#type' => 'hidden',
    '#default_value' => $mlid,
  );
  $form['buttons']['submit']['#submit'][] = 'menu_editor_node_creation_node_form_submit';
}


function menu_editor_node_creation_node_form_submit($form, &$form_state) {
  $mlid = $form_state['values']['menu_editor_mlid'];
  $nid = $form_state['nid'];
  $type = $form['#node']->type;
  if (!$mlid || (int)$mlid != $mlid)  {
    return;
  }
  if (!$nid || (int)$nid != $nid)  {
    return;
  }
  $q = db_query("SELECT * FROM {menu_links} WHERE mlid = %d", $mlid);
  if ($menu_item = db_fetch_array($q)) {
    if (
      $menu_item['link_path'] == "node/add/$type/mlid/$mlid" ||
      $menu_item['link_path'] == "mlid/$mlid/under-construction"
    ) {
      $menu_item['link_path'] = "node/$nid";
      $menu_item['router_path'] = "node/%";
      $menu_item['options'] = array();
      menu_link_save($menu_item);
    }
  }
}


/**
 * Does the same as drupal_get_form(),
 * but does not render it.
 * 
 * (In D7 this will be no longer needed)
 *
 * @param $form_id
 *   The unique string identifying the desired form. If a function
 *   with that name exists, it is called to build the form array.
 *   Modules that need to generate the same form (or very similar forms)
 *   using different $form_ids can implement hook_forms(), which maps
 *   different $form_id values to the proper form constructor function. Examples
 *   may be found in node_forms(), search_forms(), and user_forms().
 * @param ...
 *   Any additional arguments are passed on to the functions called by
 *   drupal_get_form(), including the unique form constructor function.
 *   For example, the node_edit form requires that a node object be passed
 *   in here when it is called.
 * @return
 *   The complete form array.
 */
function menu_editor_build_form($form_id) {
  $form_state = array('storage' => NULL, 'submitted' => FALSE);

  $args = func_get_args();
  $cacheable = FALSE;

  if (isset($_SESSION['batch_form_state'])) {
    $form_state = $_SESSION['batch_form_state'];
    unset($_SESSION['batch_form_state']);
  }
  else {
    if (isset($_POST['form_id']) && $_POST['form_id'] == $form_id &&
      !empty($_POST['form_build_id'])
    ) {
      $form = form_get_cache($_POST['form_build_id'], $form_state);
    }
    
    if (!isset($form)) {
      $form_state['post'] = $_POST;
      
      $args_temp = $args;
      $args_temp[0] = &$form_state;
      array_unshift($args_temp, $form_id);

      $form = call_user_func_array('drupal_retrieve_form', $args_temp);
      $form_build_id = 'form-'. md5(uniqid(mt_rand(), true));
      $form['#build_id'] = $form_build_id;
      drupal_prepare_form($form_id, $form, $form_state);
      
      $original_form = $form;
      $cacheable = TRUE;
      unset($form_state['post']);
    }
    $form['#post'] = $_POST;

    drupal_process_form($form_id, $form, $form_state);
    if ($cacheable && !empty($form['#cache'])) {
      form_set_cache($form_build_id, $original_form, $form_state);
    }
  }

  if ((!empty($form_state['storage']) || !empty($form_state['rebuild'])) &&
    !empty($form_state['submitted']) && !form_get_errors()
  ) {
    $form = drupal_rebuild_form($form_id, $form_state, $args);
  }

  // If we haven't redirected to a new location by now, we want to
  // render whatever form array is currently in hand.
  return $form;
}

