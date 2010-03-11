<?php
// $Id: views_cycle.drush.inc,v 1.1.2.1 2009/08/25 23:03:31 crell Exp $

/**
 * Implementation of hook_drush_command().
 *
 * @See drush_parse_command() for a list of recognized keys.
 * @return
 *   An associative array describing your command(s).
 */
function views_cycle_drush_command() {
  $items = array();

  $items['views_cycle post-install'] = array(
    'callback' => 'views_cycle_install',
    'description' => dt('Finish installation of views_cycle.'),
    'examples' => array(
      'drush views_cycle install' => dt('Finish installation of views_cycle.'),
    ),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 * @return
 *   A string with the help text for your command.
 */
function views_cycle_drush_help($section) {
  switch ($section) {
    case 'drush:views_cycle post-install':
      return dt("Download the jQuery Cycle plugin required by views_cycle and place it in the correct location.");
  }
}

function views_cycle_install() {

  // The path to download FROM.
  $remote_file = "http://www.malsup.com/jquery/cycle/jquery.cycle.all.min.js";

  // The filename we want to download TO.
  $destination_file = "jquery.cycle.js";
  $destination_filename = drupal_get_path('module', 'views_cycle') ."/{$destination_file}";

  // This part is standard for all modules using this pattern.
  $remote_file_local = basename($remote_file);

  if (file_exists($destination_filename)) {
    drush_log(dt("{$destination_file} Already Exists!"));
  }

  // Download it.
  if (!drush_shell_exec("wget " . $remote_file)) {
    drush_shell_exec("curl -O " . $remote_file);
  }

  if(!drush_shell_exec("cp {$remote_file_local} " . $destination_filename)) {
    drush_shell_exec("rm -rf $remote_file_local");
    return drush_set_error('DRUSH_PM_DOWNLOAD_FAILED', dt("Unable to download {$remote_file} to {$destination_filename}"));
  }

  if (file_exists($destination_filename)) {
    drush_shell_exec("rm -rf {$remote_file_local}");
    drush_log("Successfully downloaded {$remote_file} to {$destination_filename}.", 'ok');
  }
  else {
    return drush_set_error('DRUSH_PM_DOWNLOAD_FAILED', dt("Unable to download {$remote_file} to {$destination_filename}"));
  }

  return TRUE;
}

