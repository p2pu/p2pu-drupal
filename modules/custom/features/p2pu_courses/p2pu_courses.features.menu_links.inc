<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function p2pu_courses_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-webcraft:<front>
  $menu_links['menu-webcraft:<front>'] = array(
    'menu_name' => 'menu-webcraft',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'P2PU Home',
    'options' => array(
      'purl' => 'disabled',
      'attributes' => array(
        'title' => 'P2PU home page',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-webcraft:course-listing
  $menu_links['menu-webcraft:course-listing'] = array(
    'menu_name' => 'menu-webcraft',
    'link_path' => 'course-listing',
    'router_path' => 'course-listing',
    'link_title' => 'Webcraft Courses',
    'options' => array(
      'attributes' => array(
        'title' => 'Webcraft course listing',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-webcraft:http://www.drumbeat.org/p2pu-webcraft
  $menu_links['menu-webcraft:http://www.drumbeat.org/p2pu-webcraft'] = array(
    'menu_name' => 'menu-webcraft',
    'link_path' => 'http://www.drumbeat.org/p2pu-webcraft',
    'router_path' => '',
    'link_title' => 'Drumbeat',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'purl' => 'disabled',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Drumbeat');
  t('P2PU Home');
  t('Webcraft Courses');


  return $menu_links;
}
