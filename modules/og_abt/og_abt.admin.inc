<?php
// $Id: og_abt.admin.inc,v 1.1.2.2 2008/07/12 18:02:26 jrbeeman Exp $

/**
 * @file
 * Admin settings for Organic Groups Audience By Type module
 */


/**
 * Menu callback
 *
 * Provide settings for each group node type.
 */
function og_abt_admin_settings_og(&$form_state, $type) {
  $form = array();
  $options = array();
  $types = node_get_types();
  foreach ($types as $_type) {
    $options[$_type->type] = t($_type->name);
  }

  // save this for og_node_types
  $all_node_type_options = $options;

  // hide node types which are already serving as a group node
  foreach (og_get_types('group') as $val) {
    unset($options[$val]);
  }
  $non_group_type_options = $options;

  $form['types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content type settings'),
    '#description' => t('For each content type, choose how the audience targeting system will behave.'),
    '#tree' => TRUE,
  );
  foreach ($non_group_type_options as $type_key => $type_name) {
    if (variable_get('og_content_type_usage_'. $type_key, NULL) != 'omitted') {
      $defaults = variable_get('og_abt_'. $type .'-'. $type_key, og_abt_defaults());
      $form['types'][$type_key] = array(
        '#type' => 'fieldset',
        '#title' => t($type_name),
      );
      $form['types'][$type_key]['omit'] = array(
        '#type' => 'checkbox',
        '#title' => t('Omit from the audience targeting system'),
        '#default_value' => $defaults['omit'],
        '#description' => t('If selected, groups of the type %group_type will <em>not</em> appear in the audience targeting system for the nodes of the type %type.', array('%group_type' => $types[$type]->name, '%type' => t($type_name))),
      );
      $form['types'][$type_key]['force_single'] = array(
        '#type' => 'checkbox',
        '#title' => t('Force single'),
        '#default_value' => $defaults['force_single'],
        '#description' => t('Only allow a single group of this type to be selected in the audience targeting system. If this type has been omitted from the audience targeting system, this setting will be ignored.'),
      );
      $form['types'][$type_key]['required'] = array(
        '#type' => 'checkbox',
        '#title' => t('Require'),
        '#description' => t('Require the user to select a group of this type when submitting a %type.', array('%type' => $type_name)),
        '#default_value' => $defaults['required'],
      );
      $form['types'][$type_key]['admin_roles'] = array(
        '#type' => 'select',
        '#title' => t('Administrator roles'),
        '#multiple' => TRUE,
        '#description' => t('Users with the selected roles will be allowed to post into a group of this type regardless of whether they are a member of the group.'),
        '#options' => user_roles(TRUE),
        '#default_value' => $defaults['admin_roles'],
      );

    }
  }

  $form['type'] = array('#type' => 'value', '#value' => $type);
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Save configuration'),
  '#weight' => 10,
  );

  return $form;
}


/**
 * Submit handler for og_abt_admin_og_abt_settings()
 */
function og_abt_admin_settings_og_submit($form, &$form_state) {
  $type = $form_state['values']['type'];
  foreach ($form_state['values']['types'] as $key => $value) {
    variable_set('og_abt_'. $type .'-'. $key, $value);
  }
  drupal_set_message('Your changes have been saved.');
}


/**
 * Menu callback
 *
 * Provide settings for non-group node types
 */
function og_abt_admin_settings_nonog(&$form_state, $type) {
  $form = array();

  $role_options = user_roles(TRUE);
  $form['public_access'] = array(
    '#type' => (count($role_options) > 10) ? 'select' : 'checkboxes',
    '#multiple' => TRUE,
    '#title' => t('Public publishing access'),
    '#description' => t('Restrict access to the <em>Public</em> checkbox for this type to the selected roles.  If no roles are selected, the behavior of the checkbox will remain unaffected.'),
    '#options' => $role_options,
    '#default_value' => variable_get('og_abt_'. $type .'_public_access', array()),
  );

  $form['type'] = array('#type' => 'value', '#value' => $type);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#weight' => 10,
  );

  return $form;
}


/**
 * Submit handler for og_abt_admin_og_settings()
 */
function og_abt_admin_settings_nonog_submit($form, &$form_state) {
  $type = $form_state['values']['type'];
  variable_set('og_abt_'. $type .'_public_access', array_filter($form_state['values']['public_access']));
  drupal_set_message('Your changes have been saved.');
}