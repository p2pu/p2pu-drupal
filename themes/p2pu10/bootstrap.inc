<?php



/**
 * If the theme key is not defined yet, we're on the theme settings page
 * and need to switch to whatever theme is being set up
 */
global $theme_key;
if (!$theme_key){
  $theme_key = arg(4);
  init_theme();
}

/**
 * Sets up default theme settings if required
 */
if (is_null(theme_get_setting('settings'))){
  
  include_once('theme-settings.php');
  
  // Save default theme settings.
  variable_set(
    str_replace('/', '_', 'theme_'.$theme_key.'_settings'),
    _defaults()
  );
  
  // Force refresh of Drupal internals.
  theme_get_setting('', TRUE);
}