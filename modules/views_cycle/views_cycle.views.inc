<?php
// $Id: views_cycle.views.inc,v 1.1 2009/03/20 21:47:24 crell Exp $

/**
 * Implementation of hook_views_plugins()
 */
function views_cycle_views_plugins() {
  return array(
    'style' => array(
      'cycle' => array(
        'title'           => t('Cycle'),
        'help'            => t('Display the results using the jQuery cycle plugin'),
        'handler'         => 'views_cycle_plugin_style_cycle',
        'theme'           => 'views_cycle',
        'uses options'    => TRUE,
        'uses row plugin' => TRUE,
        'uses fields'     => TRUE,
        'uses grouping'   => FALSE,
        'type'            => 'normal',
        'parent'          => 'list',
        'theme file'      => 'views_cycle.theme.inc',
      ),
    ),
  );
}

