<?php
// $Id: og_abt_domain.admin.inc,v 1.1.2.2 2008/07/12 18:02:26 jrbeeman Exp $

/**
 * @file
 * Admin settings for Organic Groups Audience By Type Domain module
 */


/**
 * Menu callback
 */
function og_abt_domain_settings() {
  $form = array();

  $options = array(0 => '');
  $vocabs = taxonomy_get_vocabularies();
  foreach ($vocabs as $vid => $vocab) {
    $options[$vid] = $vocab->name;
  }

  $form['og_abt_domain_vid'] = array(
    '#type' => 'select',
    '#title' => t('Domain vocabulary'),
    '#description' => t('The vocabulary used to define domains.'),
    '#options' => $options,
    '#default_value' => variable_get('og_abt_domain_vid', 0),
  );

  $form['og_abt_domain_property'] = array(
    '#type' => 'select',
    '#title' => t('Domain term property'),
    '#description' => t('The property of each term that defines the domain.'),
    '#options' => array(
      'name' => t('Name'),
      'description' => t('Description'),
    ),
    '#default_value' => variable_get('og_abt_domain_property', 'name'),
  );

  $form['og_abt_domain_strict'] = array(
    '#type' => 'checkbox',
    '#title' => t('Strict domain checking'),
    '#description' => t('If a domain is not set for a group, do <em>not</em> show it in the audience selection list.'),
    '#default_value' => variable_get('og_abt_domain_strict', 0),
  );

  return system_settings_form($form);
}