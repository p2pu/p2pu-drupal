<?php
// $Id: views_cycle.theme.inc,v 1.1.2.8 2010/01/13 20:20:42 crell Exp $

/**
 * Preprocess function to build the cycle style plugin.
 */
function template_preprocess_views_cycle(&$vars, $hook) {
  // Inherit the theming from the parent style.  Mostly this just gives us
  // Nice CSS classes for each row.
  template_preprocess_views_view_list($vars);

  // Some nice aliases to make the code easier to read.
  $view     = $vars['view'];
  $options  = $view->style_plugin->options;
  $handler  = $view->style_plugin;
  $fields   = &$view->field;
  $rows     = &$vars['rows'];

  // Generate a unique ID for this cycle instance that we can pass to JS.
  $vars['cycle_id'] = 'views-cycle-'. $view->name .'-'. $view->style_plugin->display->id;

  // The $settings array is passed forward to Javascript to inform the code how
  // to build the cycle slideshow.  We'll convert this to full Drupal.settings
  // format below.
  $settings = array(
    'params' => $options['params'],
  );

  // Javascript, or at least the cycle plugin, gets very cranky if you pass it
  // a string version of a number.  We therefore have to force all numeric
  // values to actually be numeric data types so that they are passed as such
  // to Javascript.  Fortunately we know that all of the numeric values that
  // cycle takes are integers.
  foreach ($settings['params'] as $key => $value) {
    if (is_numeric($value)) {
      $settings['params'][$key] = (int)$value;
    }
  }

  // If there are thumbnails, we need to build that list as well as fully rendered
  // HTML and pass it to Javascript.  Technically the JS needs to "generate" the
  // HTML for the thumbnails for the cycle plugin to work, but we'll pre-theme
  // that server side and then just look it up on demand in the browser.
  if ($options['thumbnail_field']) {
    // This is just a temporary hack.  See the note below.
    $keys = array_keys($view->field);

    // Grab each result row and add it to the thumbs list
    foreach ($view->result as $num => $row) {
      $classes = array();
      if ($num == 0) {
        $classes[] = 'view-cycle-first';
      }
      if ($num == (count($rows)-1)) {
        $classes[] = 'view-cycle-last';
      }
      $classes[] = ($num % 2) ? "view-cycle-odd" : "view-cycle-even";

      $classes[] = "view-cycle-thumb-{$num}";

      $classes = implode(' ', $classes);

      // Append to the list items, which will later output in a single hidden list near the cycler.
      $vars['thumbs_data'] .= "<li class='{$classes}' >". $handler->rendered_fields[$num][$options['thumbnail_field']] ."</li>";
    }

    $settings['params']['pager']      = '#'. $vars['cycle_id'] .'-nav';
    $settings['use_pager_callback']   = 1;
    $settings['params']['pagerEvent'] = $options['pager']['event'];
    $settings['params']['pagerLocation'] = $options['skin_info']['pager_location'];
    $settings['params']['height'] = $options['height'];
    $settings['verticalPadding'] = $options['verticalPadding'];
  }

  // Enqueue any stylesheets set for the skin on this view are added.
  drupal_add_css(drupal_get_path('module', 'views_cycle') .'/views_cycle.css');
  $skin_path = drupal_get_path('module', $options['skin_info']['module']);
  if ($options['skin_info']['path']) {
    $skin_path .= '/'. $options['skin_info']['path'];
  }
  foreach ($options['skin_info']['stylesheets'] as $stylesheet) {
    drupal_add_css($skin_path .'/'. $stylesheet);
  }

  // Set up the necessary JS.
  drupal_add_js(drupal_get_path('module', 'views_cycle') .'/jquery.cycle.js', 'module', 'footer');
  drupal_add_js(drupal_get_path('module', 'views_cycle') .'/views_cycle.js', 'module', 'footer');

  // Key the settings for each instance of the cycle plugin by its cycle id.
  drupal_add_js(array('views_cycle' => array($vars['cycle_id'] => $settings)), 'setting', 'footer');

}

