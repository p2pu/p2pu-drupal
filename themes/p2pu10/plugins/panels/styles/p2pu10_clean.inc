<?php
// $Id: naked.inc,v 1.1.2.2 2010/01/13 06:25:15 merlinofchaos Exp $

/**
 * @file
 * Definition of the 'naked' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('P2PU: No markup, except for title'),
  'description' => t('Display the pane with no markup, but DO include the title.'),
  'render pane' => 'p2pu10_panels_clean_style_render_pane',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_p2pu10_panels_clean_style_render_pane($content, $pane, $display) {
  if (!empty($content->title) && $content->content != '') {
      $output = '<h2 class="pane-title">' . $content->title . '</h2>';
  }
  if (!empty($content->content)) {
      $output .= $content->content;
  }
  return $output;
}

