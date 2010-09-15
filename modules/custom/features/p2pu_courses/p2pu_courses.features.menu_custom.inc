<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function p2pu_courses_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-webcraft
  $menus['menu-webcraft'] = array(
    'menu_name' => 'menu-webcraft',
    'title' => 'webcraft',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('webcraft');


  return $menus;
}
