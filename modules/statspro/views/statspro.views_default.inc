<?php
// $Id: statspro.views_default.inc,v 1.1 2008/12/31 19:53:29 mr3dblond Exp $

/**
 * @file
 *   Default views for statistics pro module
 *
 */

// Declare all the .view files in the views subdir that end in .view
function statspro_views_default_views() {

  $files = file_scan_directory(drupal_get_path('module', 'statspro') .'/views/defaults', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    $views[$view->name] = $view;
  }

  return $views;
}
