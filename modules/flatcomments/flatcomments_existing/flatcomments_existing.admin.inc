<?php
// $Id: flatcomments_existing.admin.inc,v 1.1.2.2 2009/05/18 02:55:05 dragonwize Exp $

/**
 * @file
 *  Administrative callbacks to provide the functionality of flattening
 *  previously existing comments.
 */

/**
 * This is a multi-pass form, the confirmation being second pass.
 */
function flatcomments_existing_form($form_state) {
  if (empty($form_state['storage']['types'])) {
    // First pass: Fresh form to select content types
    $form['types'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Flatten existing comments for content types'),
      '#options' => node_get_types('names'),
      '#description' => t('To remove all threading information from already existing comments, select content types you wish to process, and click "Execute". <strong>Warning: This operation breaks any previously existing threads into separate comments permanently, so there\'s no way to revert existing discussions back to threads afterwards.</strong>'),
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Execute'),
    );
    $form['#submit'] = array('flatcomments_existing_form_submit_1');
  }
  else {
    // Second pass: Confirmation screen
    $form['types'] = array(
      '#type' => 'value',
      '#value' => $form_state['storage']['types'], // Keep the selection from first pass
    );
    $form['#submit'] = array('flatcomments_existing_form_submit_2');
    $form = confirm_form($form,
      t('Are you sure you want to remove threading from these comments?'),
      'admin/content/comment/flatten',
      t('<strong>Warning: This operation is permanent and can NOT be undone. All comments of the selected content types will be flattened.</strong>'),
      t('Flatten comments'),
      t('Cancel')
    );
  }

  return $form;
}

/**
 * Form validation; checks that node type(s) are selected, and all valid.
 * The checks are executed on both passes of the form.
 */
function flatcomments_existing_form_validate($form, &$form_state) {
  $content_types = node_get_types('names');
  $is_selected = FALSE;
  $is_valid = TRUE;

  foreach ($form_state['values']['types'] as $type => $value) {
    if (!empty($value)) {
      $is_selected = TRUE;
      if (!isset($content_types[$type])) {
        $is_valid = FALSE;
      }
    }
  }

  if (!$is_selected || !$is_valid) {
    form_set_error('types', t('You must choose at least one valid content type.'));
  }
}

/**
 * Form submit handler - first pass. Triggers second pass for confirmation.
 */
function flatcomments_existing_form_submit_1($form, &$form_state) {
  // Pass the submitted selection of content types to the second pass.
  // The existence of $form_state['storage'] triggers the second pass
  // of the form being rendered in our code, as well as in the FAPI.
  $form_state['storage']['types'] = $form_state['values']['types'];
}

/**
 * Form submit handler - second pass. Starts a batch of required operations.
 */
function flatcomments_existing_form_submit_2($form, &$form_state) {
  // Reset the form to show first pass when finished.
  $form_state['storage'] = NULL;

  $content_types = node_get_types('names');
  $processed_types = array();
  $batch = array('file' => __FILE__);

  // Add operations to the batch
  foreach ($form_state['values']['types'] as $type => $value) {
    if (!empty($value)) {
      $processed_types[$type] = $content_types[$type];
      $nodes = db_query("SELECT DISTINCT c.nid FROM {comments} c INNER JOIN {node} n ON c.nid = n.nid WHERE n.type = '%s'", $type);
      while ($node = db_fetch_array($nodes)) {
        $batch['operations'][] = array('flatcomments_existing_one', array($node['nid']));
      }
    }
  }

  // This is a replacement for 'finished' callback, so that we can pass $processed_types
  $batch['operations'][] = array('flatcomments_existing_finished', array($processed_types));

  // Execute the batch.
  batch_set($batch);
  // batch_process() is not needed here, because we're inside a form
  // submit handler.
}

/**
 * Flatten comments for single node. This is a batch operation.
 */
function flatcomments_existing_one($nid, &$context) {
  // Collect all comment ID's for the given node (published or not), ordering
  // by cid to get the comments in the order they were created (the same order
  // as flat display uses).
  $cids = db_query('SELECT cid FROM {comments} WHERE nid = %d ORDER BY cid', $nid);

  // Iterate through the comments, and set each one to be start of a new thread,
  // by clearing the parent ID, and setting the 'thread' vancode equal to the
  // order in flat list (with no descendants). This is done as php loop rather than
  // database query, to ensure the vancodes are consistent with comment module,
  // and to avoid possible MySQL/PgSQL/whatever compatibility issues.
  $order = 1;
  while ($cid = db_fetch_array($cids)) {
    $cid = $cid['cid'];
    $thread = int2vancode($order++) .'/';
    db_query("UPDATE {comments} SET pid = 0, thread = '%s' WHERE cid = %d", $thread, $cid);
  }
}

/**
 * Print message when finished. This is a batch operation.
 */
function flatcomments_existing_finished($processed_types, &$context) {
  $types = implode(', ', $processed_types);

  drupal_set_message(t('Threading information was successfully removed from comments on %types content type(s).', array('%types' => $types)));
  watchdog('content', 'Removed threading information from comments on %types content type(s).', array('%types' => $types));

}
