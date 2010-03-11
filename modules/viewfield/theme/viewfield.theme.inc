<?php
// $Id: viewfield.theme.inc,v 1.6 2009/12/02 23:53:56 darrenoh Exp $

/**
 * @file
 * Theme functions.
 */

/**
 * Return a themed view avoiding viewfield recursion.
 */
function theme_viewfield_formatter_default($element) {
  global $_viewfield_stack;
  // For safety's sake, we can only display 2 levels of viewfields.
  if (count($_viewfield_stack) <= 2) {
    list($view_name, $display) = explode('|', $element['#item']['vname'], 2);
    $view_args = _viewfield_get_view_args($element['#item']['token_enabled'], $element['#item']['vargs'], $element['#node']);
    $node = $element['#node'];
    // Need to prevent recursive views and node building, but don't need to do
    // it on new node previews.
    if ($node->nid) {
      _viewfield_nodestack_push($node->nid);
    }
    array_unshift($view_args, $view_name, $display);
    $output = call_user_func_array('views_embed_view', $view_args);
    // This node is "safe" again.
    if ($node->nid) {
      _viewfield_nodestack_pop();
    }
    return $output;
  }
}

/**
 * Perform argument replacement
 */
function _viewfield_get_view_args($token_enabled, $vargs, $node) {
  $args = array();
  // Prevent token_replace() from running this function a second time
  // before it completes the first time.
  static $tokens = TRUE;
  if ($tokens && !empty($vargs)) {
    $pos = 0;
    while ($pos < strlen($vargs)) {
      $found = FALSE;
      // If string starts with a quote, start after quote and get everything
      // before next quote.
      if (strpos($vargs, '"', $pos) === $pos) {
        if (($quote = strpos($vargs, '"', ++$pos)) !== FALSE) {
          // Skip pairs of quotes.
          while (!(($ql = strspn($vargs, '"', $quote)) & 1)) {
            $quote = strpos($vargs, '"', $quote + $ql);
          }
          $args[] = str_replace('""', '"', substr($vargs, $pos, $quote + $ql - $pos - 1));
          $pos = $quote + $ql + 1;
          $found = TRUE;
        }
      }
      elseif (($comma = strpos($vargs, ',', $pos)) !== FALSE) {
        // Otherwise, get everything before next comma.
        $args[] = substr($vargs, $pos, $comma - $pos);
        // Skip to after comma and repeat
        $pos = $comma + 1;
        $found = TRUE;
      }
      if (!$found) {
        $args[] = substr($vargs, $pos);
        $pos = strlen($vargs);
      }
    }
    if ($token_enabled) {
      $tokens = FALSE;
      // If the view field is being loaded as a "view field" of "view row",
      // instead of a simple "node field", the node object is not fully populated:
      // we need a full node to perform a correct replacement.
      $node_values = node_load($node->nid);
      $args = token_replace($args, 'node', $node_values);
      $tokens = TRUE;
    }
    // For backwards compatibility, we scan for %nid, etc.
    global $user;
    foreach ($args as $key => $a) {
      $args[$key] = strtr($a, array('%nid' => $node->nid, '%author' => $node_values->uid, '%viewer' => $user->uid));
    }
  }
  return $args;
}

/**
 * Function for adding a node ID to the global stack of node IDs. This prevents
 * us from recursively building a node, with a view, with the node, with the
 * view...
 */
function _viewfield_nodestack_push($nid) {
  global $_viewfield_stack;
  if (!isset($_viewfield_stack)) {
    $_viewfield_stack = array();
  }
  $_viewfield_stack[] = $nid;
}

/**
 * Function for removing a node ID from the global stack of node IDs when there
 * is no longer a danger of building a node, with a view, with the node, with
 * the view...
 */
function _viewfield_nodestack_pop() {
  global $_viewfield_stack;
  return array_pop($_viewfield_stack);
}

function theme_viewfield_select($element) {
  if (!empty($element['#children'])) {
    $field = $element['#field_info'][$element['#field_name']];
    if ($field['multiple'] && $element['#delta'] == 0) {
      // This is needed only for multiple viewfields.
      drupal_add_css(drupal_get_path('module', 'viewfield') .'/theme/viewfield.css');
    }
    return '<div class="viewfield-select">'. $element['#children'] .'</div>';
  }
}
