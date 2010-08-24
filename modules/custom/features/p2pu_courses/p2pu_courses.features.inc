<?php

/**
 * Implementation of hook_content_default_fields().
 */
function p2pu_courses_content_default_fields() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function p2pu_courses_ctools_plugin_api() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function p2pu_courses_imagecache_default_presets() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function p2pu_courses_node_info() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.features.node');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_node_info', $args);
}

/**
 * Implementation of hook_default_page_manager_handlers().
 */
function p2pu_courses_default_page_manager_handlers() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_default_page_manager_handlers', $args);
}

/**
 * Implementation of hook_default_page_manager_pages().
 */
function p2pu_courses_default_page_manager_pages() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_default_page_manager_pages', $args);
}

/**
 * Implementation of hook_default_panels_mini().
 */
function p2pu_courses_default_panels_mini() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_default_panels_mini', $args);
}

/**
 * Implementation of hook_rules_defaults().
 */
function p2pu_courses_rules_defaults() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_rules_defaults', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function p2pu_courses_user_default_permissions() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.defaults');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function p2pu_courses_views_default_views() {
  module_load_include('inc', 'p2pu_courses', 'p2pu_courses.features.views');
  $args = func_get_args();
  return call_user_func_array('_p2pu_courses_views_default_views', $args);
}
