<?php

/**
 * Implementation of hook_views_default_views().
 */
function tf_admin_views_default_views() {
  module_load_include('inc', 'tf_admin', 'tf_admin.defaults');
  return _tf_admin_views_default_views();
}
