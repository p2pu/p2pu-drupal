<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function tf_members_imagecache_default_presets() {
  module_load_include('inc', 'tf_members', 'tf_members.defaults');
  return _tf_members_imagecache_default_presets();
}

/**
 * Implementation of hook_menu_default_items().
 */
function tf_members_menu_default_items() {
  module_load_include('inc', 'tf_members', 'tf_members.defaults');
  return _tf_members_menu_default_items();
}

/**
 * Implementation of hook_views_default_views().
 */
function tf_members_views_default_views() {
  module_load_include('inc', 'tf_members', 'tf_members.defaults');
  return _tf_members_views_default_views();
}
