<?php
include_once('bootstrap.inc');



/**
 * Gets Curacao default settings
 *
 * @return 
 *  A keyed array of default settings
 */
function _defaults(){
  return array(
    'settings' => TRUE,
  );
}



/**
 * Gets the Curacao settings form
 *
 * @param $settings
 *   a keyed array of theme settings
 * @return
 *   a keyed array representing the settings form
 */
function p2pu10_settings($settings){
  
  // Reload settings if we've set up default values 
  if (is_null($settings['settings'])){
    global $theme_key;
    $settings = theme_get_settings($theme_key);
  }

  drupal_add_css(path_to_theme().'/style/theme-settings.css');
  drupal_add_js(path_to_theme().'/theme-settings.js');

  $form = array(
    'settings' => array(
      '#type' => 'hidden',
      '#value' => 'TRUE',
    ),
  );
  
  _add_display_options($form, $settings);
  _add_themeing_options($form, $settings);
  
  return $form;
}



/**
 * Adds element display options to the settings form
 */
function _add_display_options(&$form, $settings){
  $form['show-breadcrumb'] = array(
    '#default_value' => $settings['show-breadcrumb'],
    '#title' => t('Show breadcrumb in header'),
    '#type' => 'checkbox',
  ); 
}



/**
 * Adds body class options to the settings form
 */
function _add_themeing_options(&$form, $settings){
  $form['path-class'] = array(
    '#default_value' => $settings['path-class'],
    '#description' => t('Adds the first argument of the path as a class to the body tag to enable page specific themeing.'),
    '#prefix' => '<hr/>',
    '#title' => t('Path based body class'),
    '#type' => 'checkbox',
  ); 

  $form['alias-class'] = array(
    '#default_value' => $settings['alias-class'],
    '#description' => t('Adds the first argument of the path alias as a class to the body tag to enable page specific themeing.'),
    '#title' => t('Alias based body class'),
    '#type' => 'checkbox',
  ); 
}


