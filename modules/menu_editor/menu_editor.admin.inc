<?php



/**
 * Form for editing an entire menu tree at once.
 *
 * Shows for one menu the menu items accessible to the current user and
 * relevant operations.
 */
function menu_editor_overview_form(&$form_state, $menu) {
  global $menu_admin, $language;
  $sql = "
    SELECT
      m.load_functions, m.to_arg_functions, m.access_callback, m.access_arguments,
      m.page_callback, m.page_arguments, m.title, m.title_callback, m.title_arguments,
      m.type, m.description, ml.*
    FROM {menu_links} ml LEFT JOIN {menu_router} m ON m.path = ml.router_path
    WHERE ml.menu_name = '%s'
    ORDER BY p1 ASC, p2 ASC, p3 ASC, p4 ASC, p5 ASC, p6 ASC, p7 ASC, p8 ASC, p9 ASC";
  $result = db_query($sql, $menu['menu_name']);
  $tree = menu_tree_data($result);
  $node_links = array();
  menu_tree_collect_node_links($tree, $node_links);
  // We indicate that a menu administrator is running the menu access check. 
  $menu_admin = TRUE;
  menu_tree_check_access($tree, $node_links);
  $menu_admin = FALSE;
  
  $form = array('#tree' => TRUE);
  if (module_exists('i18nmenu')) {
    $language_options = array('' => t('All languages')) + locale_language_list('name');
    $form['#_language_options'] = $language_options;
  }
  _menu_editor_overview_tree_form($form, $tree, $language_options);
  
  // default values for all new menu items..
  $default_values = array(
    'link_title' => '',
    'link_path' => '<front>',
    'hidden' => true,
    'expanded' => false,
    'weight' => 0,
    // 'mlid' => NULL,  // this is different for every single one
    'plid' => 0,
    'language' => $language->language,
  );
  
  foreach (module_invoke_all('menu_editor_placeholders') as $placeholder_code => $placeholder_path) {
    // take the first placeholder as default link path instead of <front>
    $default_values['link_path'] = $placeholder_code;
    break;
  }
  
  
  for ($i=0; $i<8; ++$i) {
    // new menu item
  	$default_values['mlid'] = 'new' . $i;
    $item_key = 'mlid:new'.$i;
  	$form[$item_key] = _menu_editor_overview_tree_form_item('new'.$i, $default_values, $language_options);
  	$form[$item_key]['#item'] = array();
  	$form[$item_key]['#attributes'] = array('class' => 'menu-new');
  	$form[$item_key]['drag']['#value'] = t('New menu item');
  }
  
  $form['#menu'] =  $menu;
  if (element_children($form)) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    );
  }
  else {
    $form['empty_menu'] = array('#value' => t('There are no menu items yet.'));
  }
  return $form;
}


/**
 * Recursive helper function for menu_overview_form().
 */
function _menu_editor_overview_tree_form(&$form, $tree, $language_options) {
  foreach ($tree as $data) {
    $title = '';
    $item = $data['link'];
    // Don't show callbacks; these have $item['hidden'] < 0.
    if ($item && $item['hidden'] >= 0) {
      $item_key = 'mlid:'. $item['mlid'];
      
      $default_values = array(
        'link_title' => $item['link_title'],
        'link_path' => $item['link_path'],
        'hidden'   => !$item['hidden'],
        'expanded' => $item['expanded'],
        'weight'   => isset($form_state[$item_key]['weight']) ? $form_state[$item_key]['weight'] : $item['weight'],
        'plid'     => isset($form_state[$item_key]['plid']) ? $form_state[$item_key]['plid'] : $item['plid'],
        'language' => '' . @$item['options']['langcode'],
      );
      
      $form[$item_key] = _menu_editor_overview_tree_form_item($item['mlid'], $default_values, $language_options);
      
      $form[$item_key]['#item'] = $item;
      $form[$item_key]['#attributes'] = $item['hidden'] ? array('class' => 'menu-disabled') : array('class' => 'menu-enabled');
      $form[$item_key]['drag']['#value'] = l($item['title'], $item['href'], $item['localized_options']) . ($item['hidden'] ? ' ('. t('disabled') .')' : '');
      
      // Only items created by the menu module can be deleted.
      if ($item['module'] == 'menu' || $item['updated'] == 1) { 
        $form[$item_key]['delete'] = array(
          '#type' => 'checkbox',
          '#title' => t('delete'),
          '#default_value' => false,
        );
      }
    }
    
    // process child elements
    if ($data['below']) {
      _menu_editor_overview_tree_form($form, $data['below'], $language_options);
    }
  }
  return $form;
}

function _menu_editor_overview_tree_form_item($item_mlid, $default_values, $language_options = NULL) {
  
  static $placeholders;
  if (!isset($placeholders)) {
    $placeholders = module_invoke_all('menu_editor_placeholders');
  }
  
  foreach ($placeholders as $code => $path) {
    if (str_replace('%mlid', $item_mlid, $path) == $default_values['link_path']) {
      $default_values['link_path'] = $code;
    }
  }
  
  $element = array();
  $element['link_title'] = array(
    '#type' => 'textfield',
    '#size' => 25,
  );
  $element['link_path'] = array(
    '#type' => 'textfield',
    '#size' => 25,
  );
  $element['hidden'] = array(
    '#type' => 'checkbox',
  );
  $element['expanded'] = array(
    '#type' => 'checkbox',
  );
  $element['weight'] = array(
    '#type' => 'weight',
    '#delta' => 50,
  );
  $element['mlid'] = array(
    '#type' => 'hidden',
    '#value' => $item_mlid,
  );
  $element['plid'] = array(
    '#type' => 'textfield',
    '#size' => 6,
  );
  if ($language_options) {
    $element['language'] = array(
      '#type' => 'select',
      '#options' => $language_options,
    );
  }
  foreach ($default_values as $key => $value) {
    if (isset($element[$key])) {
      $element[$key]['#default_value'] = $value;
    }
  }
  return $element;
}


function menu_editor_overview_form_validate($form, &$form_state) {
  // allow new items to be dynamically added via javascript,
  // that have not been in the form originally.
  foreach ($form['#post'] as $item_key => $item) {
    if (preg_match('/^mlid:new\d+$/', $item_key)) {
      if (menu_editor_overview_form_validate_new_item($item)) {
        $form_state['values'][$item_key] = $item;
      }
    }
  }
}


/**
 * validate a menu item that was dynamically added through javascript
 * 
 * @param unknown_type $item
 */
function menu_editor_overview_form_validate_new_item($item) {
  // TODO: add some sanity checks
  return true;
}


/**
 * Submit handler for the menu overview form.
 *
 * This function takes great care in saving parent items first, then items
 * underneath them. Saving items in the incorrect order can break the menu tree.
 *
 * @see menu_overview_form()
 */
function menu_editor_overview_form_submit($form, &$form_state) {
  
  $multilanguage = module_exists('i18nmenu');
  // When dealing with saving menu items, the order in which these items are
  // saved is critical. If a changed child item is saved before its parent,
  // the child item could be saved with an invalid path past its immediate
  // parent. To prevent this, save items in the form in the same order they
  // are sent by $_POST, ensuring parents are saved first, then their children.
  // See http://drupal.org/node/181126#comment-632270
  $item_keys = array_flip(array_keys($form['#post'])); // Get the $_POST order.
  $form_values = array_merge($item_keys, $form_state['values']); // Update our original form with the new order.
  
  $menu_name = $form['#menu']['menu_name'];
  
  $updated_items = array();
  $fields = array('expanded', 'weight', 'plid', 'link_title', 'link_path');
  foreach ($form_values as $item_key => $v) {
    if (isset($form[$item_key]['#item'])) {
      $element = $form[$item_key];
      if (!is_numeric($v['mlid'])) {
        // add new item
        unset($v['mlid']);
        if (!is_string($v['link_title']) || empty($v['link_title'])) {
          continue;
        }
        if (!is_string($v['link_path']) || empty($v['link_path'])) {
          continue;
        }
        $element['#item']['menu_name'] = $menu_name;
        // Set all fields in this menu item.
        foreach ($fields as $field) {
          $element['#item'][$field] = $v[$field];
        }
        $updated_items[$item_key] = $element['#item'];
      } else if ($v['delete']) {
        // delete existing item
        if (is_numeric($v['mlid'])) {
          menu_link_delete($v['mlid']);
        }
        continue;
      } else {
        // update existing item
        // Update any fields that have changed in this menu item.
        foreach ($fields as $field) {
          if ($v[$field] != $element[$field]['#default_value']) {
            $element['#item'][$field] = $v[$field];
            $updated_items[$item_key] = $element['#item'];
          }
        }
      }
      // Hidden is a special case, the value needs to be reversed.
      if ($v['hidden'] != $element['hidden']['#default_value']) {
        $element['#item']['hidden'] = !$v['hidden'];
        $updated_items[$item_key] = $element['#item'];
      }
      // langcode is a special case as well
      if ($form['#_language_options']) {
        if ($v['language'] != $element['language']['#default_value']) {
          $element['#item']['options']['langcode'] = $v['language'];
          $updated_items[$item_key] = $element['#item'];
        }
      }
    }
  }
  
  // placeholders to change the link path
  $placeholders = module_invoke_all('menu_editor_placeholders');
  
  // Save all our changed items to the database.
  $errors = array();
  $mlids = array();
  foreach ($updated_items as $item_key => $item) {
    $item['customized'] = 1;
    
    // check the link path
    $link_path = &$item['link_path'];
    
    $link_path_placeholder = NULL;
    
    // placeholders
    if (isset($placeholders[$link_path])) {
      if (is_numeric($item['mlid'])) {
        $link_path = str_replace('%mlid', $item['mlid'], $placeholders[$link_path]);
      }
      else {
        $link_path_placeholder = $placeholders[$link_path];
        // use a dummy link path,
        // until we know the correct mlid.
        $link_path = '<front>';
      }
    }
    
    // clean the link path
    if (isset($link_path)) {
      $link_path = drupal_get_normal_path($link_path);
      if (!menu_path_is_external($link_path)) {
        $parsed_link = parse_url($link_path);
        if (isset($parsed_link['query'])) {
          $item['options']['query'] = $parsed_link['query'];
        }
        if (isset($parsed_link['fragment'])) {
          $item['options']['fragment'] = $parsed_link['fragment'];
        }
        if ($link_path != $parsed_link['path']) {
          $link_path = $parsed_link['path'];
        }
      }
      if (!trim($link_path) || !menu_valid_path($item)) {
        // invalid link path, discard this item
        continue;
      }
    }
    
    // drupal_set_message('<pre>' . print_r($item, true) . '</pre>');
    if ($item['plid'] && !is_numeric($item['plid'])) {
      if (isset($mlids["mlid:$item[plid]"])) {
        $item['plid'] = $mlids["mlid:$item[plid]"];
      }
      else {
        unset($item['plid']);
      }
    }
    $mlid = menu_link_save($item);
    if (is_numeric($mlid)) {
      // remember as a plid for child items
      $mlids[$item_key] = $mlid;
      if (isset($link_path_placeholder)) {
        // overwrite the dummy link path
        $link_path = str_replace('%mlid', $item['mlid'], $link_path_placeholder);
        menu_link_save($item);
      }
    }
    else {
      $errors[] = $item_key;
    }
  }
  
  if (!empty($errors)) {
    drupal_set_message(t('There were errors saving the following menu links:<br/>' . implode('<br/>', $errors)), 'error');
  }
}





/**
 * Theme the menu overview form into a table.
 *
 * @ingroup themeable
 */
function theme_menu_editor_overview_form($form) {
  drupal_add_css(drupal_get_path('module', 'menu_editor') .'/menu_editor.css');
  global $language;
  $multilanguage = module_exists('i18nmenu');
  drupal_add_tabledrag('menu-overview', 'match', 'parent', 'menu-plid', 'menu-plid', 'menu-mlid', TRUE, MENU_MAX_DEPTH - 1);
  drupal_add_tabledrag('menu-overview', 'order', 'sibling', 'menu-weight');

  $header = array(
    t('Menu item'),
    t('Title'),
    t('Path'),
    array('data' => t('Enabled'), 'class' => 'checkbox'),
    array('data' => t('Expanded'), 'class' => 'checkbox'),
    t('Weight')
  );
  if ($multilanguage) {
    $header[] = t('Language');
  }
  $header[] = t('Delete');

  $rows = array();
  foreach (element_children($form['sections']) as $section_key) {
    foreach (element_children($form['sections'][$section_key]) as $item_key) {
      $element = $form['sections'][$item_key];
    }
  }
  foreach (element_children($form) as $item_key) {
    if (isset($form[$item_key]['hidden'])) {
      $element = &$form[$item_key];
      // Build a list of operations.
      $operations = array();
      foreach (element_children($element['operations']) as $op) {
        $operations[] = drupal_render($element['operations'][$op]);
      }
      while (count($operations) < 2) {
        $operations[] = '';
      }

      // Add special classes to be used for tabledrag.js.
      $element['plid']['#attributes']['class'] = 'menu-plid';
      $element['mlid']['#attributes']['class'] = 'menu-mlid';
      $element['weight']['#attributes']['class'] = 'menu-weight';

      // Change the parent field to a hidden. This allows any value but hides the field.
      $element['plid']['#type'] = 'hidden';
      
      // Adjust tab index to allow vertical tabbing
      foreach (array('link_title', 'link_path', 'hidden', 'expanded') as $i => $key) {
        $element[$key]['#attributes']['tabindex'] = $i+2;
      }

      $row = array();
      $row[] = theme('indentation', $element['#item']['depth'] - 1) . drupal_render($element['drag']);
      $row[] = array('data' => drupal_render($element['link_title']), 'class' => 'title-edit');
      $row[] = array('data' => drupal_render($element['link_path']), 'class' => 'path-edit');
      $row[] = array('data' => drupal_render($element['hidden']), 'class' => 'checkbox');
      $row[] = array('data' => drupal_render($element['expanded']), 'class' => 'checkbox');
      $row[] = drupal_render($element['weight']) . drupal_render($element['plid']) . drupal_render($element['mlid']);
      if ($multilanguage) {
        $row[] = array('data' => drupal_render($element['language']), 'class' => 'select');
      }
      $row[] = array('data' => drupal_render($element['delete']), 'class' => 'checkbox delete-checkbox');
      
      $row = array_merge(array('data' => $row), $element['#attributes']);
      $row['class'] = !empty($row['class']) ? $row['class'] .' draggable' : 'draggable';
      if ($multilanguage) {
        $langcode = $element['language']['#default_value'];
        $row['class'] .= ($langcode) ? ' langcode-'.$langcode : ' all-languages';
        $row['class'] .= ($langcode == $language->language) ? ' active-language' : '';
      }
      $rows[] = $row;
    }
  }
  $output = '';
  if ($rows) {
    $output .= theme('table', $header, $rows, array('id' => 'menu-overview'));
  }
  $output .= drupal_render($form);
  return $output;
}

