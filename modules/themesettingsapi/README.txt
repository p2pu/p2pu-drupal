THEME SETTINGS API

  This module simply extends the Custom Theme Settings API documented in the
  Theme Developer's Handbook: http://drupal.org/node/177868

    In the Drupal administration section, each theme has its own settings page
    at admin/build/themes/settings/themeName where you can configure standard
    settings like "Logo image settings" and "Shortcut icon settings."

    You can make your theme customizable by adding additional settings to that
    form using the Custom Theme Settings API.

  Currently, this modules only adds the optional ability to switch to the theme
  whose settings are being edited. Once this module is installed, see the
  admin/settings/admin page.

  Improvements to the Custom Theme Settings API are slated for the 6.x-2.0
  version of this module.

ABOUT THE PROJECT

  In Drupal 4.7 and 5, it was impossible for themes (like PHPtemplate-based
  ones) to add settings to the theme settings page without coding a module.
  There needed to be an API to facilitate that. No one had successfully
  implemented this (See issues 54990, 56713 and 57676.)

  The Theme Settings API project created a fully functioning implementation of
  a custom theme settings API for Drupal. This API should reside in core and
  this project successfully championed the addition of an updated API into
  Drupal 6 (see issue 57676 at http://drupal.org/node/57676.)

  The new goal of the project is to continue to improve the API and get those
  improvements into Drupal 7.
