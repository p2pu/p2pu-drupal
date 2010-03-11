<?php
// $Id: statspro.drush.inc,v 1.1 2009/04/19 10:15:13 mr3dblond Exp $

/**
 * @file
 *   Drush include file for statuspro
 *
 */


 /**
 * Implementation of hook_drush_help().
 */
function statspro_drush_help($section) {
  switch ($section) {
    case 'drush:statspro':
      return dt('Usage: drush [options] statspro <aliases> <comments> <modules> <nodes> <node_types> <sessions> <url_aliases> <users>.');
  }
}

/**
 * Implementation of hook_drush_command().
 *
 * @return array
 */
function statspro_drush_command() {

  $items = array();

  $items['statspro'] = array(
    'callback' => 'statspro_drush_run',
    'description' => 'statspro drush commands'
  );

  return $items;
}

/**
 * Run drush command for specified mode
 *
 */
function statspro_drush_run() {

  $modes = func_get_args();

  if (empty($modes)) {
    drush_die('Missing mode: use drush help statspro for more information');
  }

  require_once drupal_get_path('module', 'statspro') .'/statspro.inc';

  $statspro = new statspro();

  drush_print(t('Statistics pro information'));

  $rc = $statspro->get_aggregate_stat($modes[0]);

  if (is_array($rc)) {
      drush_print($rc['subject'] .': '. $rc['amount']);
  }
  else {
      drush_die('Unknown mode');
  }
}
