<?php

/**
 * Implementation of hook_content_default_fields().
 */
function tf_site_news_content_default_fields() {
  module_load_include('inc', 'tf_site_news', 'tf_site_news.defaults');
  return _tf_site_news_content_default_fields();
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function tf_site_news_imagecache_default_presets() {
  module_load_include('inc', 'tf_site_news', 'tf_site_news.defaults');
  return _tf_site_news_imagecache_default_presets();
}

/**
 * Implementation of hook_node_info().
 */
function tf_site_news_node_info() {
  module_load_include('inc', 'tf_site_news', 'tf_site_news.defaults');
  return _tf_site_news_node_info();
}

/**
 * Implementation of hook_views_default_views().
 */
function tf_site_news_views_default_views() {
  module_load_include('inc', 'tf_site_news', 'tf_site_news.defaults');
  return _tf_site_news_views_default_views();
}
