<?php
// $Id:



/* ---- Content loaders ---- */



function _popup_text($attributes){

  return
    _popup_element(
      $attributes['title'] ? $attributes['title'] : 'Text',
      $attributes['text'],
      $attributes,
      _classes($attributes)
    );

}



function _popup_node($attributes){

  $node = node_load($attributes['node']);
  $body = node_view($node, $attributes['teaser'] == TRUE, $attributes['page'] == TRUE, $attributes['links'] == TRUE);

  return
    _popup_element(
      $attributes['title'] ? $attributes['title'] : $node->title,
      $body,
      $attributes,
      _classes($attributes)
    );

}



function _popup_block($attributes){

  // Get the block from a module
  if ($attributes['module'] && isset($attributes['delta'])){

    $block = module_invoke($attributes['module'], 'block', 'view', $attributes['delta']);
    $title = $attributes['title'] ?  $attributes['title'] : $block['subject'];
    $body = $block['content'];

  // or from the block module
  } else {

    $block_box = block_box_get($attributes['block']);
    $title = $attributes['title'] ?  $attributes['title'] : $block_box['info'];
    $body = $block_box['body'];
  }

  return
    _popup_element(
      $title,
      $body,
      $attributes,
      _classes($attributes)
    );

}



function _popup_form($attributes){

  $title = $attributes['title'] ?  $attributes['title'] : 'form';
  $body = drupal_get_form($attributes['form']);

  return
    _popup_element(
      $title,
      $body,
      $attributes,
      _classes($attributes)
    );

}



function _popup_view($attributes){

  if (module_exists('views')){

    $view = views_get_view($attributes['view']);
    $display = $attributes['display'] ? $attributes['display'] : 'default';
    $args = isset($attributes['args'])
      ? explode(',', $attributes['args'])
      : array();

    if ($view){
      $view->set_arguments($args);
      $view->set_display($display);
//      $view->pager['items_per_page'] = 0;
      $body = $view->execute_display();

      $computed_title = $view->get_title();
      $title = $attributes['title']
        ? $attributes['title']
        : ($computed_title
            ? $computed_title
            : $view->display[$display]->display_options['title']
          );

    }

  } else {
    $body = false;
  }

  $title = $title ? $title : 'View';

  return
    _popup_element(
      $title,
      $body,
      $attributes,
      _classes($attributes)
    );

}



function _popup_php($attributes){

  return
    _popup_element(
      $attributes['title'] ? $attributes['title'] : 'PHP',
      eval($attributes['php']),
      $attributes,
      _classes($attributes)
    );

}



function _popup_menu($attributes, $item = FALSE, $level = 0, $position = array()){

  if (variable_get('popup-css-only', FALSE)) return;

  global $user;
  $body = '';

  if ($item){

    $title = $item['link']['title'];
    $link_path = str_replace('%', $user->uid, $item['link']['link_path']);
    $children = $item['link']['has_children'] ? $item['below'] : FALSE;

  } else {

    if ($attributes['title']){
      $title = $attributes['title'];
    } else {
      $menu = menu_load($attributes['menu']);
      $attributes['title'] = $menu['title'];
    }

    $title = $attributes['title'] ? $attributes['title'] : $attributes['menu'];
    $link_path = $attributes['link'];
    $children = menu_tree_all_data($attributes['menu']);
  }

  $children = $children ? array_filter($children, '_popup_prune') : FALSE;
  $link_path = drupal_get_path_alias(str_ireplace('<front>', '/', $link_path));

  if ($children) {

    // Make sure opacity, flat and inline does not compound
    $child_attributes = $attributes;
    if ($level == 1 || $level == 0 && !$attributes['flat']){
      unset($child_attributes['opacity']);
      unset($child_attributes['inline']);
    }
    unset($child_attributes['flat']);

    $index = 0;
    $count = count($children);

    foreach($children as $child){
      if (!$child['link']['hidden']){

        $list_position = array();
        if ($index == 0){
          $list_position[] = 'first';
        }
        if ($index == $count - 1){
          $list_position[] = 'last';
        }

        $body .= _popup_menu($child_attributes, $child, $level + 1, $list_position);

        $index++;
      }
    }

  }

  if ($level == 0 && !$attributes['flat']){
    $position = array('first', 'last');
  }

  if ($attributes['activate'] == 'hover' || !$children){
    $attributes['link'] = $link_path;
  }

  $classes = _classes($attributes, $body != FALSE);
  if ($attributes['menu']){
    $classes = _menu_classes($classes, $attributes, $children, $level, $position);
  }

  if ($level == 0 && $attributes['flat']){
    return _popup_element(FALSE, $body, $attributes, $classes, TRUE);
  } else {
    return _popup_element($title, $body, $attributes, $classes, TRUE);
  }
}



/* ---- HTML generators ---- */



function _popup_element($title, $body, $attributes, $classes, $display_empty = FALSE){

  // No use displaying a popup with an empty body or title, unless intended
  if ($body && $title || $display_empty){

    $classes = _collapse_classes($classes);

    $variables = array(
      'title' => $title ? theme('popup_element_title', $title) : FALSE,
      'href' => ($attributes['link'] ? ' href="'.base_path().ltrim($attributes['link'], '/').'"' : ''),
      'classes' => $classes,
      'id' => ($attributes['id'] ? $attributes['id'] : _popup_id()),
    );

    if ($body){
      $variables['body'] = array(
        'content' => ($body ? theme('popup_element_body', $body) : FALSE),
        'prefix' => ($title && $body ? '<div class="'.$classes['origin'].'"><div class="'.$classes['expand'].'">' : ''),
        'suffix' => ($title && $body ? '</div></div>' : ''),
      );
    }

    $style_path = variable_get('popup-style', drupal_get_path('module', 'popup').'/styles/Default');

    // Render the popup element html
    extract($variables, EXTR_OVERWRITE);
    ob_start();
    include($style_path.'/popup-element.tpl.php');
    $element = ob_get_contents();
    ob_end_clean();

    return theme('popup_element', $element);

  }

}



/* ---- Class utilities ---- */



/**
 * Generates classes for any popup element
 */
function _classes($attributes, $has_body = TRUE){

  $activate = ($attributes['activate'] ? $attributes['activate'] : 'hover').'-activate';

  $classes = array(
    'title' => array('popup-title'),
    'title-container' => array('popup-title-container'),
    'body' => array('popup-body'),
  );

  if ($has_body){
    $classes['element'] = array('popup-element', 'popup-'.$activate.'-element');
    $classes['origin'] = array('popup-origin', 'popup-'.($attributes['origin'] ? $attributes['origin'] : 'bottom-left').'-origin');
    $classes['expand'] = array('popup-expand', 'popup-'.($attributes['expand'] ? $attributes['expand'] : 'bottom-right').'-expand');
    $classes['body'][] = 'popup-body-'.$activate;
  }

  if ($attributes['class']){
    $classes['element'][] = $attributes['class'];
    $classes['title'][] = $attributes['class'].'-title';
    $classes['title-container'][] = $attributes['class'].'-title-container';
    $classes['body'][] = $attributes['class'].'-body';
  }

  if ($attributes['link']){
    $classes['title'][] = 'popup-link-title';
    $classes['title-container'][] = 'popup-link-title-container';
  }

  if ($attributes['effect']){
    $classes['body'][] = 'popup-'.$attributes['effect'].'-effect';
  }

  if ($attributes['opacity']){
    $classes['body'][] = 'popup-opacity-'.$attributes['opacity'];
  }

  if ($attributes['close-button']){
    $classes['body'][] = 'popup-close-button';
  }

  return $classes;
}



/**
 * Generates additional classes for popup menu elements
 */
function _menu_classes($classes, $attributes, $has_children, $level, $position = array()){

  $classes['element'][] = 'popup-menu-element';
  $classes['body'][] = 'popup-menu-body';
  $classes['title'][] = 'popup-menu-title';

  if ($has_children){
    $classes['element'][] = 'popup-menu-parent-element';
    $classes['title'][] = 'popup-menu-parent-title';
    $classes['title-container'][] = 'popup-menu-parent-title-container';
  } else {
    $classes['element'][] = 'popup-menu-leaf-item';
    $classes['title'][] = 'popup-menu-leaf-title';
    $classes['title-container'][] = 'popup-menu-leaf-title-container';
  }

  foreach($position as $position_string){
    $classes['element'][] = 'popup-menu-'.$position_string.'-element';
    $classes['title'][] = 'popup-menu-'.$position_string.'-title';
    $classes['title-container'][] = 'popup-menu-'.$position_string.'-container';
  }

  if ($attributes['flat']){
    $classes['element'][] = 'popup-menu-flat-element';
    $classes['title'][] = 'popup-menu-flat-title';
    $classes['title-container'][] = 'popup-menu-flat-container';
    if ($level == 0){
      $classes['body'][] = 'popup-menu-flat-body';
      $classes['body-wrapper'][] = 'popup-menu-flat-body-wrapper';
    }
  }

  if ($attributes['inline']){
    $classes['element'][] = 'popup-menu-inline-element';
    $classes['title'][] = 'popup-menu-inline-title';
    $classes['title-container'][] = 'popup-menu-inline-title-container';
    $classes['origin'][] = 'popup-menu-inline-origin';
    $classes['body'][] = 'popup-menu-inline-body';
  } else if ($level == 0 && !$attributes['flat']) {
    $classes['element'][] = 'popup-menu-block-element';
    $classes['title'][] = 'popup-menu-block-title';
    $classes['title-container'][] = 'popup-menu-block-title-container';
    $classes['origin'][] = 'popup-menu-block-origin';
    $classes['body'][] = 'popup-menu-block-body';
  }

  return $classes;
}



function _collapse_classes($classes){

  foreach($classes as $name=>$array){
    $classes[$name] = implode(' ', $array);
  }

  return $classes;
}



/* ---- Utility ---- */



function _popup_prune($item){
  return !$item['link']['hidden'];
}



function _popup_id(){
  static $popup_index = 0;
  return 'popup-element-'.$popup_index++;
}



function _popup_tag_attributes($tag){

  $attributes = array();
  $inner = ereg_replace('\ ?\=\ ?', '=', trim(substr($tag, 6, strlen($tag) - 7))).' ';

  $attribPattern =
    '/'.
    '(?:\s?[^\s=]+\s)|'.             // xx-_.01
    '(?:[^\s]*="[^"]+")|'.           // xx-_.01="..."
    '(?:[^\s]*=[\'][^\']+[\'])|'.    // xx-_.01='...'
    '(?:[^\s]*=[^\s]*)'.             // xx-_.01=xx-_.01
    '/';

  $found = array();
  preg_match_all($attribPattern, $inner, $found);

  foreach($found[0] as $attribute){
    $parts = split('=', $attribute);
    $value = preg_replace('/(^[\'\"]{1})|([\'\"]{1}$)/', '', trim($parts[1]));

    $attributes[trim($parts[0])] = strlen($value)
      ? $value
      : TRUE;
  }

  return $attributes;
}





