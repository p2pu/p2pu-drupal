<?php
// $Id: statspro.views.inc,v 1.2 2009/01/01 18:38:15 mr3dblond Exp $

/**
 * @file
 *   Views support for statistcs pro module
 *
 */

/**
 * Implementation of hook_views_data().
 *
 * @return array
 */
function statspro_views_data() {

  require_once drupal_get_path('module', 'statspro') .'/statspro.inc';

  // ----------------------------------------------------------------

  $data['statspro']['table']['group']       = t('Statistics pro');
  $data['statspro_term']['table']['group']  = t('Statistics pro');

  // Advertise this table as a possible base table
  $data['statspro']['table']['base'] = array(
    'field' => 'day',
    'title' => t('Statistics pro'),
    'help' => t('Stores site statistics.'),
    'weight' => 10,
  );

  // For other base tables, explain how we join
  $data['statspro_term']['table']['join'] = array(
    'term_data' => array(
      'field' => 'tid',
      'left_field' => 'tid',
      ),
  );

  // timestamp
  $data['statspro']['day'] = array(
    'title' => t('Date'),
    'help' => t('Date of statistics.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // term amounts
  $data['statspro_term']['ncount'] = array(
    'title' => t('Amount nodes'),
    'help' => t('Amount of nodes for term.'),
    'field' => array(
      'handler' => 'stastspro_views_handler_field_graph',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  // all data fields
  $statspro = new statspro();
  $data_fields = $statspro->get_fields();
  foreach ($data_fields AS $field => $field_desc) {
    $data['statspro'][$field] = array(
      'title' => strip_tags($field_desc),
      'help' => $field_desc,
      'field' => array(
        'handler' => 'stastspro_views_handler_field_graph_trend',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
    );
  }

  return $data;
}

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 *
 * @return array
 */
function statspro_views_handlers() {

  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'statspro') .'/views',
    ),
    'handlers' => array(
        'stastspro_views_handler_field_graph' => array(
          'parent' => 'views_handler_field_numeric',
        ),
        'stastspro_views_handler_field_graph_trend' => array(
          'parent' => 'views_handler_field_numeric',
        ),
    ),
  );
}

