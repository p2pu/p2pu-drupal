<?php
// $Id: statspro.tools.inc,v 1.1 2008/12/31 19:53:29 mr3dblond Exp $

/**
 * @file
 *   Include file for tools page
 *
 */

function statspro_tools() {

  $form['intro_cron'] = array('#type' => 'markup',
                              '#value' => '<div>'. t('Here you can manually run cron job to generate the latest date for statistics.') .'</div>');
  $form['cron_call'] = array('#type' => 'submit', '#value' => t('Manual cron call'));

  $form['intro'] = array('#type' => 'markup',
                          '#value' => '<br /><br /><div>'. t('On this page you find useful tools for Statistics maintenance.') .'</div>');

  $form['reset_stats']     = array('#type' => 'submit', '#value' => t('Reset Statistics pro data'));


  return $form;
}

function statspro_tools_submit($form, &$form_state) {

  switch ($form_state['values']['op']) {

    case t('Manual cron call'):
      drupal_set_message(t('Cron manually executed.'));
      drupal_goto('admin/reports/status/run-cron');
      break;

    case t('Reset Statistics pro data'):
      drupal_set_message(t('Statistics pro reseted.'));
      statspro_reset_stats();
      break;
  }
}
