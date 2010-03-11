<?php
// $Id: themesettingsapi.admin.inc,v 1.2 2008/04/03 19:14:09 johnalbin Exp $

/**
 * @file
 * Extends the custom theme settings API in Drupal 6.
 *
 * @author John Albin Wilkins (JohnAlbin) <john at albin dot net>
 * @link http://www.albin.net
 */

/**
 * Implementation of hook_form_alter().
 *
 * @param &array $form
 * @param array $form_state
 * @param string $form_id
 * @return void
 */
function themesettingsapi_form_alter(&$form, $form_state, $form_id) {
  switch ($form_id) {
    case 'system_theme_settings':
      // Grab the specific name of the theme settings form
      $key = $form['var']['#value'];
      $key = ($key == 'theme_settings') ? '' : preg_replace('/(^theme_|_settings$)/', '', $key);

      // Since we are allowing more settings, make logo and favicon collapsible
      if (empty($key)) {
        // Fix for small bug in Drupal core
        $form['theme_settings']['#prefix'] = '<div class="clear-block">'. $form['theme_settings']['#prefix'];
        $form['node_info']['#suffix'] = $form['node_info']['#suffix'] .'</div>';
        if (isset($form['logo'])) {
          unset($form['logo']['#attributes']['class']);
        }
      }
      if (isset($form['logo'])) {
        $form['logo']['#collapsible'] = TRUE;
        $form['logo']['#collapsed'] = $key ? TRUE : FALSE;
      }
      if (isset($form['favicon'])) {
        $form['favicon']['#collapsible'] = TRUE;
        $form['favicon']['#collapsed'] = $key ? TRUE : FALSE;
      }

      // If the administration theme is not used, switch themes when displaying the theme settings.
      if ($key and (variable_get('admin_theme', '0') == '0' or variable_get('theme_settings_admin_theme', '1') == '0')) {
        global $custom_theme;
        $custom_theme = $key;
        init_theme();
      }
      break;

    case 'system_admin_theme_settings':
      // Add a setting to allow theme switching even with an admin theme
      $form['theme_settings_admin_theme'] = array(
        '#type' => 'checkbox',
        '#title' => t('Use administration theme when configuring theme settings'),
        '#description' => t('If this setting is disabled or if using the "System default" theme, the theme settings pages will be switched to the theme being configured.'),
        '#default_value' => variable_get('theme_settings_admin_theme', '1'),
      );

      // Move submit buttons to bottom
      $form['buttons']['#weight'] = 1;
      break;
  }
}
