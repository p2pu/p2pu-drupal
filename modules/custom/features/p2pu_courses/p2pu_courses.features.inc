<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function p2pu_courses_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function p2pu_courses_imagecache_default_presets() {
  $items = array(
    'course_photo' => array(
      'presetname' => 'course_photo',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache_coloractions',
          'action' => 'imagecache_alpha',
          'data' => array(
            'RGB' => array(
              'HEX' => 'ffffff',
            ),
            'flatten' => TRUE,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '20',
            'independent_corners_set' => array(
              'independent_corners' => 0,
              'radii' => array(
                'tl' => '',
                'tr' => '',
                'bl' => '',
                'br' => '',
              ),
            ),
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '292',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function p2pu_courses_node_info() {
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

/**
 * Implementation of hook_rules_defaults().
 */
function p2pu_courses_rules_defaults() {
  return array(
    'rules' => array(
      'p2pu_courses_2' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Mail administrators when a course is created and create empty syllabus document',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'course',
          '1' => 'p2pu_courses',
          'p2pu_courses' => 'p2pu_courses',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'course' => 'course',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Created content is Course',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to all users of a role',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_users_of_role',
            '#settings' => array(
              'recipients' => array(
                '0' => 4,
              ),
              'from' => '',
              'subject' => 'New course created ([node:title])',
              'message' => 'A new course has been created by [node:author-name].

Please review this at [node:site-url]/node/[node:nid]
',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'node',
                  ),
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'severity' => '6',
              'type' => 'rules',
              'message' => 'Webmasters notified of new course created ([node:title])',
              'link' => '',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_watchdog',
            '#info' => array(
              'label' => 'Log to watchdog',
              'module' => 'System',
              'eval input' => array(
                '0' => 'type',
                '1' => 'message',
                '2' => 'link',
              ),
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Create empty course syllabus document and link to course.',
              'arguments' => array(
                'group' => array(
                  'type' => 'node',
                  'label' => 'Group node that user will be subscribed to notifications of',
                ),
              ),
              'configurable' => FALSE,
              'hooks' => array(
                'nodeapi' => array(
                  '0' => 'insert',
                ),
              ),
              'module' => 'P2PU',
            ),
            '#name' => 'p2pu_rules_action_create_course_syllabus',
            '#settings' => array(
              '#argument map' => array(
                'group' => 'node',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'p2pu_courses_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Mail the Course creator when their course is approved',
        '#active' => 0,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'course',
          '1' => 'p2pu_courses',
          'p2pu_courses' => 'p2pu_courses',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'course' => 'course',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Course',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node_unchanged',
              ),
            ),
            '#weight' => 0,
            '#type' => 'condition',
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'Unchanged content was published',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#negate' => 1,
          ),
          '2' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'Updated content is published',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Log to watchdog',
              'module' => 'System',
              'eval input' => array(
                '0' => 'type',
                '1' => 'message',
                '2' => 'link',
              ),
            ),
            '#name' => 'rules_action_watchdog',
            '#settings' => array(
              'severity' => '6',
              'type' => 'rules',
              'message' => 'The course creator has been notified of their course approval ([node:title])',
              'link' => '',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'from' => '',
              'subject' => 'Your course [node:title] has been approved.',
              'message' => 'Your course has been approved. Other user instructions to be included here.',
              '#argument map' => array(
                'user' => 'author',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'p2pu_courses_3' => array(
        '#type' => 'rule',
        '#set' => 'event_og_user_delete',
        '#label' => 'User removed from course: Delete course node comment notification subscription',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'p2pu_courses',
          'p2pu_courses' => 'p2pu_courses',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              '#argument map' => array(
                'user' => 'account',
                'group' => 'group',
              ),
            ),
            '#name' => 'p2pu_rules_action_unsubscribe_user_from_course_comments',
            '#info' => array(
              'label' => 'Unsubscribe a user from a course node comments notifications.',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User who will be subscribed',
                ),
                'group' => array(
                  'type' => 'node',
                  'label' => 'Group node that user will be unsubscribed from',
                ),
              ),
              'configurable' => FALSE,
              'module' => 'P2PU',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'p2pu_courses_4' => array(
        '#type' => 'rule',
        '#set' => 'event_og_user_approved',
        '#label' => 'User accepted to join a course: Subscribe them to the course node comment notifications',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'p2pu_courses',
          'p2pu_courses' => 'p2pu_courses',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Subscribe a user to notifications on course node comments.',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User who will be subscribed',
                ),
                'group' => array(
                  'type' => 'node',
                  'label' => 'Group node that user will be subscribed to notifications of',
                ),
              ),
              'configurable' => FALSE,
              'module' => 'P2PU',
            ),
            '#name' => 'p2pu_rules_action_subscribe_user_to_course_comments',
            '#settings' => array(
              '#argument map' => array(
                'user' => 'account',
                'group' => 'group',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function p2pu_courses_views_api() {
  return array(
    'api' => '2',
  );
}
