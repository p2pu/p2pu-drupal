<?php

/**
 * Implementation of hook_content_default_fields().
 */
function tf_team_members_content_default_fields() {
  module_load_include('inc', 'tf_team_members', 'tf_team_members.defaults');
  return _tf_team_members_content_default_fields();
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function tf_team_members_imagecache_default_presets() {
  module_load_include('inc', 'tf_team_members', 'tf_team_members.defaults');
  return _tf_team_members_imagecache_default_presets();
}

/**
 * Implementation of hook_menu_default_items().
 */
function tf_team_members_menu_default_items() {
  module_load_include('inc', 'tf_team_members', 'tf_team_members.defaults');
  return _tf_team_members_menu_default_items();
}

/**
 * Implementation of hook_node_info().
 */
function tf_team_members_node_info() {
  module_load_include('inc', 'tf_team_members', 'tf_team_members.defaults');
  return _tf_team_members_node_info();
}

/**
 * Implementation of hook_views_default_views().
 */
function tf_team_members_views_default_views() {
  module_load_include('inc', 'tf_team_members', 'tf_team_members.defaults');
  return _tf_team_members_views_default_views();
}
