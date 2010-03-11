<?php
// $Id: statspro.reports.inc,v 1.1 2008/12/31 19:53:29 mr3dblond Exp $

require_once drupal_get_path('module', 'statspro') .'/statspro.inc';

/**
 * @file
 *   Include file for statistics report page
 *
 */

/**
 * Callback function for overview page
 */
function statspro_overview() {

  $statspro = new statspro();

  $last_run = variable_get('statspro_last_run', 0);
  if ($last_run) $updated = format_date($last_run);
  else           $updated = t('never');

  $output  = t('Last statistics update: !updated', array('!updated' => $updated));

  // add settings form
  $output .= drupal_get_form('statspro_settings_form');

  if ($last_run) {

    $periods    = statspro_get_period_items();
    $period     = variable_get('statspro_period', 'today');
    $start_date = variable_get('statspro_start_date', date('d.m.Y', strtotime('-1 week')));
    $end_date   = variable_get('statspro_end_date', date('d.m.Y'));

    ////////////////////////
    // common
    $output .= theme('statspro_content',
                      t('Content common') .' - '. $periods[$period],
                      $statspro->get_stats( $period,
                                            $start_date,
                                            $end_date,
                                            NULL,
                                            $statspro->absolute_amounts));

    ////////////////////////
    // pi, error and warnings
    $output .= theme('statspro_log',
                    t('PIs, errors and warnings') .' - '. $periods[$period],
                    $statspro->get_stats( $period,
                                          $start_date,
                                          $end_date,
                                          $statspro->absolute_amounts));
  }

  return $output;
}

function theme_statspro_content($title, $data) {

  $output = '<div id="content-area" style="margin-bottom: 30px">';

  if (is_array($data)) {

    // get overview chart
    $output .= statspro_chart_summery($title, $data);

    // theme the table
    $header = array(t('Name'), t('Value'));
    $output .= theme('table', $header, $data);
  }
  else {
    $output .= t('No content data available for specified period.');
  }

  $output .= '</div>';

  return $output;
}

function theme_statspro_log($title, $data) {

  $output = '<div id="content-area">';

  if (is_array($data)) {
    // get overview chart
    $output .= statspro_chart_summery($title, $data);

    // theme the table
    $header = array(t('Name'), t('Value'));
    $output .= theme('table', $header, $data);
  }
  else {
    $output .= t('No access and log files available for specified period.');
  }

  $output .= '</div>';

  return $output;
}

function statspro_chart_summery($title, $stats) {

  $data = array();

  foreach ($stats AS $result) {
    $data[] = array(
      '#value'  => $result[1],
      '#label'  => strip_tags($result[0]) .': '. $result[1]
    );
  }

  if (!empty($data)) {
    $chart    = array();
    $chart[0] = $data;
    $chart['#title']    = $title;
    $chart['#type']     = 'pie2D';
    $chart['#width']    = 480;
    $chart['#height']   = 200;

    return '<div align="center">'. charts_chart($chart) .'</div>';
  }

  return '';
}
