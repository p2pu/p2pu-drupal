<?php
// $Id: viewfield.views.inc,v 1.1 2009/04/07 18:42:31 darrenoh Exp $

/**
 * @file
 * Views functions.
 */

/**
 * Implementation of hook_views_query_alter().
 *
 * Prevent views from loading the node containing the view.
 */
function viewfield_views_query_alter(&$view, &$query) {
  global $_viewfield_stack;
  if ((!empty($_viewfield_stack)) && (in_array('node', $query->table_queue))) {
    $placeholders = array_fill(0, count($_viewfield_stack), '%d');
    $query->add_where(0, 'node.nid NOT IN ('. implode(',', $placeholders) .')', $_viewfield_stack);
  }
}
