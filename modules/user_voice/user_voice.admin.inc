<?php
// $Id: user_voice.admin.inc,v 1.1 2009/09/15 17:22:31 eastabrook Exp $

/**
 * @file
 * Admin functions used by User Voice integration module
 */

/**
 * FAPI definition for the user voice admin setting form.
 *
 * @ingroup forms
 */
function user_voice_admin_settings() {
  $options_alignment = array(
    'right' => t('Right'),
    'left' => t('Left'),
  );    
  $options_text_color = array(
    'white' => t('White'),
    'black' => t('Black'),
  ); 
  $options_lang = array(
    'en' => t('English'),
    'de' => t('German'),
    'nl' => t('Dutch'),
    'es' => t('Spanish'),
    'fr' => t('French'),
  );
  
  $form['user_voice_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Key'),
    '#description' => t('Your User Voice key'),
    '#default_value' => variable_get('user_voice_key', ''),
  );  
  $form['user_voice_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Host'),
    '#description' => t('Your User Voice host'),
    '#default_value' => variable_get('user_voice_host', ''),
  );
  $form['user_voice_general'] = array(
    '#type' => 'textfield',
    '#title' => t('Forum'),
    '#description' => t('The forum you wish to point User Voice to'),
    '#default_value' => variable_get('user_voice_general', ''),
  );
  $form['user_voice_alignment'] = array(
    '#type' => 'select',
    '#title' => t('Alignment'),
    '#description' => t('Alignment of the tab button'),
    '#options' => $options_alignment,
    '#default_value' => variable_get('user_voice_alignment', 'right'),
  );
  $form['user_voice_background_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Background colour'),
    '#description' => t('The background colour of the tab'),
    '#default_value' => variable_get('user_voice_background_color', '#F00'),
  );  
  $form['user_voice_text_color'] = array(
    '#type' => 'select',
    '#title' => t('Text Colour'),
    '#description' => t('The text colour on the word Feedback'),
    '#options' => $options_text_color,
    '#default_value' => variable_get('user_voice_text_color', 'white'),
  );
  $form['user_voice_hover_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Hover colour'),
    '#description' => t('The hover colour of the tab'),
    '#default_value' => variable_get('user_voice_hover_color', '#06C'),
  );  
  $form['user_voice_lang'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#description' => t('The language of User Voice'),
    '#options' => $options_lang,
    '#default_value' => variable_get('user_voice_lang', 'en'),
  );
  
  return system_settings_form($form);
}