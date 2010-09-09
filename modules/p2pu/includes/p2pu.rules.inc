<?php

/**
 * @file
 * Rules integration for the p2pu module.
 */

/**
* Implementation of hook_action_info().
*
* Provide custom P2PU actions to be triggered by rules.
* 
*/
function p2pu_rules_action_info() {
  return array(
    'p2pu_rules_action_create_course_syllabus' => array(
			'label' => t('Create empty course syllabus document and link to course.'),
      'arguments' => array(
        'group' => array(
          'type' => 'node',
          'label' => t('Node that the syllabus will be linked to'),
        ),
			),
      'configurable' => FALSE,
      'hooks' => array(
        'nodeapi' => array('insert'),
        ),
			'module' => 'P2PU',
      ),
    'p2pu_rules_action_subscribe_user_to_course_comments' => array(
			'label' => t('Subscribe a user to notifications on course node comments.'),			
      'arguments' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('User who will be subscribed'),
        ),
        'group' => array(
          'type' => 'node',
          'label' => t('Group node that user will be subscribed to notifications of'),
        ),
      ),
      'configurable' => FALSE,
      'module' => 'P2PU',
      ),
    'p2pu_rules_action_unsubscribe_user_from_course_comments' => array(
			'label' => t('Unsubscribe a user from a course node comments notifications.'),			
      'arguments' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('User who will be unsubscribed'),
        ),
        'group' => array(
          'type' => 'node',
          'label' => t('Group node that user will be unsubscribed from'),
        ),
      ),
      'configurable' => FALSE,
      'module' => 'P2PU',
      ),
  );
}

/**
* Implementation of a Drupal action.
* Blocks the current user.
*/
function p2pu_rules_action_create_course_syllabus($object) {
  global $user;
  $document = new StdClass();
	$document->type = "document";
	$document->status = 1;
	$document->sticky = 1;
	$document->uid = $user->uid;
	$document->name = $user->name;
	$document->title = "Syllabus for " . $object->title;
	$body_text = t("This is the Syllabus for your Course. Any course participant is allowed to edit this page. Be the first to edit the page by clicking on 'Edit' next to the name of the page (in the Course Material block on the left).");
  $document->field_document_body[0]['value'] = $body_text;
  $document->body = $body_text;
  $document->og_initial_groups[0][$object->nid];
	$document->og_groups[0] = $object->nid;
	$document->og_public = 1;
	$document->og_groups_names[0] = $object->title;
  $group_node = og_determine_context_get_group($object);
  og_set_group_context($group_node);
	if ($document = node_submit($document)) {
	  node_save($document);
    $document->og_groups = array($object->nid);
    og_save_ancestry($document);        
    $syllabus_url = l('course syllabus', 'node/' . $document->nid);
    $message = t('Automatically created !syllabus for %course_name.', array('!syllabus' => $syllabus_url, '%course_name' => check_plain($object->title)));
    // Now add the nid of the document as a node reference
    $object->field_refers_to_syllabus[0]['nid'] = $document->nid;
    watchdog('action', $message);
    drupal_set_message($message);
		return array('node' => $object); // Ensure our syllabus is saved to the group node
  }
  else {
    $message = t('Could not creat course syllabus for %course_name.', array('%course_name' => check_plain($object->title)));
    watchdog('action', $message);
    drupal_set_message($message);
  }
}
/**
* Implementation of a Drupal action.
* Subscribe a user to notifications on course node comments.
*/
function p2pu_rules_action_subscribe_user_to_course_comments($user, $node) {
	$type = 'thread';
	$event_type = 'node';
	$field = 'nid';
	$value = $node->nid;
	// if user is not already subscribed
	$subscription = array(
      'uid' => $user->uid,
      'type' => $type,
      'event_type' => $event_type,
      'fields' => array($field => $value),
    );
	notifications_save_subscription($subscription); // This function handles duplicate subscriptions
	drupal_set_message(t('User was subscribed to the course home page comments.'));
}

/**
* Implementation of a Drupal action.
* Unsubscribe a user from course node comments.
*/
function p2pu_rules_action_unsubscribe_user_from_course_comments($user, $node) {
	$type = 'thread';
	$event_type = 'node';
	$field = 'nid';
	$value = $node->nid;
	// if user is not already subscribed	
	$subscriptions =  notifications_user_get_subscriptions($user->uid, $event_type, $value, $node);
	if (!empty($subscriptions)) {
		$sid_array = array_keys($subscriptions);
		notifications_delete_subscription($sid_array[0]);
		drupal_set_message(t('User was unsubscribed from the course home page comments.'));
	}
}
