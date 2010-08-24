<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _p2pu_courses_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'module' => 'features',
      'description' => t('Announcements for a course'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'assignment' => array(
      'name' => t('Assignment'),
      'module' => 'features',
      'description' => t('Assignments for a course'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'course' => array(
      'name' => t('Course'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name (max 30 characters)'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'document' => array(
      'name' => t('Document'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('<br />
'),
    ),
    'event' => array(
      'name' => t('Event'),
      'module' => 'features',
      'description' => t('An event associated with a course'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'submission' => array(
      'name' => t('Assignment Submission'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
