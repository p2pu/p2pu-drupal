<?php
// $Id: views_cycle.api.php,v 1.1.2.1 2009/10/08 22:43:21 crell Exp $

/**
 * Registry-style hook to define skins for the views_cycle plugin.
 *
 * This hook should return a keyed array of skin definition arrays.  The key
 * of each item is the internal name of the skin.  The value is a definition
 * array.  The definition array consists of:
 *
 *   title
 *     The translated user-facing name of the skin.  This value will be shown
 *     in the administrative screens.
 *   pager_location
 *     Text position of the pager element if it exists. Options: before, after, and none.
 *   stylesheets
 *     An array of stylesheets that are part of this skin.  Do not include a path,
 *     only the name of the CSS file itself.
 *   path (optional)
 *     A path *relative to the module directory* where the stylesheet files are
 *     stored.  Generally this will not be needed unless you want to put the
 *     skin's CSS files in a subdirectory of the module.  Do not include leading
 *     or trailing /.
 *
 * @return
 *   An array of skin definitions.
 */
function hook_views_cycle_skins() {
  $skins['default'] = array(
    'title' => t('A fancy skin'),
    'pager_location' => 'before',
    'stylesheets' => array(
      'fancy.css',
    ),
  );

  return $skins;
}
