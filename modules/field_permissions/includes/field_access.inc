<?php
// $Id: field_access.inc,v 1.1.2.2 2009/11/09 23:20:17 markuspetrux Exp $

/**
 * @file
 * Implementation of helper functions related to hook_field_access().
 */

/**
 * Implementation of hook_field_access('view').
 */
function _field_permissions_field_view_access($field_name, $field_permissions, $account, $node) {
  // Check if user has access to view this field in any node.
  if (!empty($field_permissions['view']) && user_access('view '. $field_name, $account)) {
    return TRUE;
  }

  // If 'view own' permission has been enabled for this field, then we can
  // check if the user has the right permission, and ownership of the node.
  if (!empty($field_permissions['view own']) && user_access('view own '. $field_name, $account)) {

    // When content_access('view') is invoked, it may or may not provide a
    // node object. It will, almost always, except when this function is
    // invoked as a field access callback from Views, where it is used to
    // evaluate if the field can be included in the query itself. In this
    // case we should grant access. Views will invoke content_access('view')
    // again, indirectly, when rendering the fields using content_format(),
    // and this time it will provide a pseudo node object that includes the
    // uid of the node author, so here is where we have the chance to
    // evaluate ownership to check for 'view own <field>' permission.
    if (!isset($node)) {
      return TRUE;
    }

    // Try to get the uid of the node author from the node object itself.
    // When invoked by Views to render a field, we may not have the uid of the
    // node, so we need to retrieve it from the node or node revisions table.
    if (isset($node->uid)) {
      $node_uid = $node->uid;
    }
    elseif (!empty($node->vid)) {
      $node_uid = db_result(db_query('SELECT uid FROM {node_revisions} WHERE vid = %d', $node->vid));
    }
    elseif (!empty($node->nid)) {
      $node_uid = db_result(db_query('SELECT uid FROM {node} WHERE nid = %d', $node->nid));
    }
    else {
      // Deny access to view the field if we have not been able to get the uid
      // of the node author.
      return FALSE;
    }

    // Finally, we can now check if ownership of the node matches.
    return (is_numeric($node_uid) && $node_uid == $account->uid);
  }

  return FALSE;
}

/**
 * Implementation of hook_field_access('edit').
 */
function _field_permissions_field_edit_access($field_name, $field_permissions, $account, $node) {
  // Check if user has access to edit this field on node creation.
  if (empty($node->nid) && !empty($field_permissions['create'])) {
    return user_access('create '. $field_name, $account);
  }

  // Check if user has access to edit this field in any node.
  if (!empty($field_permissions['edit']) && user_access('edit '. $field_name, $account)) {
    return TRUE;
  }

  // If 'edit own' permission has been enabled for this field, then we can
  // check if the user has the right permission, and ownership of the node.
  if (!empty($field_permissions['edit own']) && user_access('edit own '. $field_name, $account) && $node->uid == $account->uid) {
    return TRUE;
  }

  return FALSE;
}
