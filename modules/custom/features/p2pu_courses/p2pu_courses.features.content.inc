<?php

/**
 * Implementation of hook_content_default_fields().
 */
function p2pu_courses_content_default_fields() {
  $fields = array();

  // Exported field: field_announcement_detail
  $fields['announcement-field_announcement_detail'] = array(
    'field_name' => 'field_announcement_detail',
    'type_name' => 'announcement',
    'display_settings' => array(
      'weight' => '32',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '2500',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_announcement_detail][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Detail',
      'weight' => '32',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_assignment_attachments
  $fields['assignment-field_assignment_attachments'] = array(
    'field_name' => 'field_assignment_attachments',
    'type_name' => 'assignment',
    'display_settings' => array(
      'weight' => '8',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'file_extensions' => '',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Attachments',
      'weight' => '8',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_assignment_detail
  $fields['assignment-field_assignment_detail'] = array(
    'field_name' => 'field_assignment_detail',
    'type_name' => 'assignment',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_assignment_detail][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Detail',
      'weight' => '4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_assignment_due_date
  $fields['assignment-field_assignment_due_date'] = array(
    'field_name' => 'field_assignment_due_date',
    'type_name' => 'assignment',
    'display_settings' => array(
      'weight' => '6',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'short',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-0:+3',
      'label_position' => 'above',
      'label' => 'Due Date',
      'weight' => '6',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_assignment_sub_list
  $fields['assignment-field_assignment_sub_list'] = array(
    'field_name' => 'field_assignment_sub_list',
    'type_name' => 'assignment',
    'display_settings' => array(
      'weight' => '9',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'viewfield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'viewfield',
    'active' => '1',
    'allowed_views' => array(
      'assignment_submission' => 'assignment_submission',
      'profile_info' => 0,
      'profile_recommendations' => 0,
      'profile_announcements' => 0,
      'profile_events' => 0,
      'profile_course_participation' => 0,
      'profile_course_contribution' => 0,
      'course_template_assignments' => 0,
      'course_template_syllabus' => 0,
      'og_members_block' => 0,
      'og_ghp_ron' => 0,
      'og_my' => 0,
      'course_assignments' => 0,
      'course_syllabus' => 0,
      'course_announcements' => 0,
      'tf_team_members' => 0,
      'course_events' => 0,
      'course_list' => 0,
      'course_template_list' => 0,
      'admin_course_proposal' => 0,
      'secondary_menu_lists' => 0,
      'comments_recent' => 0,
      'tracker' => 0,
      'frontpage' => 0,
      'glossary' => 0,
      'archive' => 0,
      'backlinks' => 0,
      'taxonomy_term' => 0,
      'date_browser' => 0,
      'posts_by_term' => 0,
      'og_members' => 0,
      'og_members_faces' => 0,
      'og_search' => 0,
      'og' => 0,
      'og_files' => 0,
      'og_unread' => 0,
      'og_recent_type_term' => 0,
      'og_tracker' => 0,
      'og_mytracker' => 0,
      'tf_admin_content' => 0,
      'tf_admin_users' => 0,
      'tf_site_news' => 0,
      'tf_site_news_arg' => 0,
      'calendar' => 0,
    ),
    'super_default' => 0,
    'token_enabled' => 0,
    'super_default_widget' => array(
      'vname' => 'assignment_submission|page_1',
      'vargs' => '%nid',
    ),
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'force_default' => 1,
      'label' => 'Submissions',
      'weight' => '9',
      'description' => '',
      'type' => 'viewfield_select',
      'module' => 'viewfield',
    ),
  );

  // Exported field: field_course_dates
  $fields['course-field_course_dates'] = array(
    'field_name' => 'field_course_dates',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '19',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => 'required',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'short',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-0:+3',
      'label_position' => 'above',
      'label' => 'Course Dates',
      'weight' => '19',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_course_facilitator_about
  $fields['course-field_course_facilitator_about'] = array(
    'field_name' => 'field_course_facilitator_about',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '17',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_course_facilitator_about][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'About the Course Organiser',
      'weight' => '17',
      'description' => 'A little bit about yourself and your background/motives for running this course.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_course_no_of_seats
  $fields['course-field_course_no_of_seats'] = array(
    'field_name' => 'field_course_no_of_seats',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '15',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_course_no_of_seats][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'No of Seats',
      'weight' => '15',
      'description' => 'How many people would you like to have in the course? You can always accept more or fewer later if you get very few or very many excellent sign-ups. ',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_course_opening_date
  $fields['course-field_course_opening_date'] = array(
    'field_name' => 'field_course_opening_date',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '18',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'short',
    'field_permissions' => array(
      'edit' => 'edit',
      'create' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y - m - d',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Opening Date',
      'weight' => '18',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_course_photo
  $fields['course-field_course_photo'] = array(
    'field_name' => 'field_course_photo',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '16',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'course_photo_default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '[title-raw] course photo',
      'custom_alt' => 0,
      'title' => '[title-raw]',
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Course Photo',
      'weight' => '16',
      'description' => 'Upload a photo that will be displayed on your course home page.',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_course_prerequisites
  $fields['course-field_course_prerequisites'] = array(
    'field_name' => 'field_course_prerequisites',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '13',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_course_prerequisites][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Prerequisites',
      'weight' => '13',
      'description' => 'What is the main audience for this course and what prerequisites should they have?',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_course_short_desc
  $fields['course-field_course_short_desc'] = array(
    'field_name' => 'field_course_short_desc',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '11',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '140',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_course_short_desc][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Short description',
      'weight' => '11',
      'description' => 'Think of this as a tweet describing the course. This field is limited to 140 characters. It\'s best framed as a question!',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_course_sign_up_req
  $fields['course-field_course_sign_up_req'] = array(
    'field_name' => 'field_course_sign_up_req',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '14',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '5000',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_course_sign_up_req][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sign-up task',
      'weight' => '14',
      'description' => 'Please outline a short assignment that users have to complete when they sign-up for your course. This should give an indication of the work load required in the course - and the types of things users will be doing. Don\'t make it too easy - but don\'t make it too hard either. ',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_course_status
  $fields['course-field_course_status'] = array(
    'field_name' => 'field_course_status',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '20',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '00_draft|Draft
10_open|Open for registration
20_running|Running
30_complete|Complete
40_archived|Archived',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '00_draft',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Course Status',
      'weight' => '20',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_course_summary
  $fields['course-field_course_summary'] = array(
    'field_name' => 'field_course_summary',
    'type_name' => 'course',
    'display_settings' => array(
      'weight' => '12',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_course_summary][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Summary',
      'weight' => '12',
      'description' => 'Provide  an overview of what you plan to cover, mention a few of the key  questions, maybe some of the main thinkers and authors you plan to use,  and anything about the structure and collaboration that might be  interesting to potential participants.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_refers_to_syllabus
  $fields['course-field_refers_to_syllabus'] = array(
    'field_name' => 'field_refers_to_syllabus',
    'type_name' => 'course',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'document' => 'document',
      'announcement' => 0,
      'assignment' => 0,
      'submission' => 0,
      'book' => 0,
      'course' => 0,
      'course_application' => 0,
      'discussion' => 0,
      'event' => 0,
      'faq' => 0,
      'forum' => 0,
      'site_news' => 0,
      'php_page' => 0,
      'page' => 0,
      'profile' => 0,
      'recommendation' => 0,
      'report_card' => 0,
      'shout_box' => 0,
      'team_member' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_refers_to_syllabus][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Syllabus document',
      'weight' => '21',
      'description' => 'The course syllabus is automatically linked to the course, so this field is currently hidden for all but admin users (system and webmaster roles) using form_alter in p2pu.module.',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_document_attachment
  $fields['document-field_document_attachment'] = array(
    'field_name' => 'field_document_attachment',
    'type_name' => 'document',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'file_extensions' => '',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Attachment',
      'weight' => '4',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_document_body
  $fields['document-field_document_body'] = array(
    'field_name' => 'field_document_body',
    'type_name' => 'document',
    'display_settings' => array(
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '10',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_document_body][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Document body',
      'weight' => '3',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_event_date
  $fields['event-field_event_date'] = array(
    'field_name' => 'field_event_date',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datetime',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'user',
    'todate' => 'optional',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-0:+3',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => '3',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_event_detail
  $fields['event-field_event_detail'] = array(
    'field_name' => 'field_event_detail',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '2500',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '3',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_event_detail][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Detail',
      'weight' => '4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_content_attachments
  $fields['submission-field_content_attachments'] = array(
    'field_name' => 'field_content_attachments',
    'type_name' => 'submission',
    'display_settings' => array(
      'weight' => '7',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'file_extensions' => '',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Attachments',
      'weight' => '7',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_submission_assignment
  $fields['submission-field_submission_assignment'] = array(
    'field_name' => 'field_submission_assignment',
    'type_name' => 'submission',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'assignment' => 'assignment',
      'announcement' => 0,
      'submission' => 0,
      'assignment_template' => 0,
      'book' => 0,
      'course' => 0,
      'course_application' => 0,
      'course_proposal' => 0,
      'course_template' => 0,
      'event' => 0,
      'faq' => 0,
      'forum' => 0,
      'site_news' => 0,
      'simplenews' => 0,
      'php_page' => 0,
      'page' => 0,
      'profile' => 0,
      'recommendation' => 0,
      'report_card' => 0,
      'syllabus' => 0,
      'syllabus_template' => 0,
      'team_member' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_submission_assignment][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'Submit an assignment',
        'hover_title' => '',
        'destination' => 'default',
      ),
      'fallback' => 'select',
      'label' => 'Assignment',
      'weight' => '4',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_submission_content
  $fields['submission-field_submission_content'] = array(
    'field_name' => 'field_submission_content',
    'type_name' => 'submission',
    'display_settings' => array(
      'weight' => '5',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'rows' => '10',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_submission_content][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Content',
      'weight' => '5',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_submission_status
  $fields['submission-field_submission_status'] = array(
    'field_name' => 'field_submission_status',
    'type_name' => 'submission',
    'display_settings' => array(
      'weight' => '6',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'ungraded|Ungraded
pass|Pass
incomplete|Incomplete',
    'allowed_values_php' => '',
    'field_permissions' => array(
      'create' => 0,
      'edit' => 0,
      'edit own' => 0,
      'view' => 0,
      'view own' => 0,
    ),
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'ungraded',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Status',
      'weight' => '6',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About the Course Organiser');
  t('Assignment');
  t('Attachment');
  t('Attachments');
  t('Content');
  t('Course Dates');
  t('Course Photo');
  t('Course Status');
  t('Date');
  t('Detail');
  t('Document body');
  t('Due Date');
  t('No of Seats');
  t('Opening Date');
  t('Prerequisites');
  t('Short description');
  t('Sign-up task');
  t('Status');
  t('Submissions');
  t('Summary');
  t('Syllabus document');

  return $fields;
}
