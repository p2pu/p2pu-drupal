<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _p2pu_courses_content_default_fields() {
  $fields = array();

  // Exported field: field_announcement_detail
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
    'required' => '1',
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
      'label' => 'Sign Up Requirement',
      'weight' => '14',
      'description' => 'Please outline a short assignment that users have to complete when they sign-up for your course. This should give an indication of the work load required in the course - and the types of things users will be doing. Don\'t make it too easy - but don\'t make it too hard either. ',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_course_status
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  $fields[] = array(
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
  array(
    t('About the Course Organiser'),
    t('Assignment'),
    t('Attachment'),
    t('Attachments'),
    t('Content'),
    t('Course Dates'),
    t('Course Photo'),
    t('Course Status'),
    t('Date'),
    t('Detail'),
    t('Document body'),
    t('Due Date'),
    t('No of Seats'),
    t('Opening Date'),
    t('Prerequisites'),
    t('Short description'),
    t('Sign Up Requirement'),
    t('Status'),
    t('Submissions'),
    t('Summary'),
    t('Syllabus document'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _p2pu_courses_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  else if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  else if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _p2pu_courses_imagecache_default_presets() {
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
 * Helper to implementation of hook_default_page_manager_handlers().
 */
function _p2pu_courses_default_page_manager_handlers() {
  $export = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Course Template Group',
    'no_blocks' => 0,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course_template' => 'course_template',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
          '1' => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '33.945414408990565',
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      '1' => array(
        'type' => 'column',
        'width' => '66.05458559100944',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          '0' => 2,
          '1' => 3,
          '2' => 4,
        ),
      ),
      '2' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'center_',
        ),
        'parent' => '1',
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
      ),
      '3' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'left',
          '1' => 'right',
        ),
        'parent' => '1',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
      ),
      '4' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'centre',
        ),
        'parent' => '1',
      ),
      'centre' => array(
        'type' => 'region',
        'title' => 'Centre',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = 'Course Template';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'block-9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'button-panel yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'page' => 1,
      'no_extras' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'teaser' => 0,
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'context' => 'argument_nid_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'og-0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Actions',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['center'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'og_members_faces';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '25',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Members',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['center'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'center_';
    $pane->type = 'views';
    $pane->subtype = 'course_documents_arg';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Course Material',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'rounded_corners',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['center_'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'center_';
    $pane->type = 'views';
    $pane->subtype = 'course_template_assignments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Course Template Assignments',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'rounded_corners',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-6'] = $pane;
    $display->panels['center_'][1] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'centre';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '2',
      'order' => '1',
      'comments_per_page' => '30',
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'rounded_corners',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-7'] = $pane;
    $display->panels['centre'][0] = 'new-7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;

  $export['node_view_panel_context'] = $handler;
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Course Group',
    'no_blocks' => 0,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
          '1' => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '33.945414408990565',
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      '1' => array(
        'type' => 'column',
        'width' => '66.05458559100944',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          '0' => 4,
          '1' => 3,
          '2' => 2,
        ),
      ),
      '2' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'center_',
        ),
        'parent' => '1',
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
      ),
      '3' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 5,
          '1' => 6,
        ),
        'parent' => '1',
      ),
      '4' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'top_region',
        ),
        'parent' => '1',
      ),
      'top_region' => array(
        'type' => 'region',
        'title' => 'Top Region',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
      ),
      '5' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          '0' => 7,
        ),
      ),
      '6' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          '0' => 8,
        ),
      ),
      '7' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'middle_left',
        ),
        'parent' => '5',
      ),
      'middle_left' => array(
        'type' => 'region',
        'title' => 'Middle left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
      ),
      '8' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'middle_right',
        ),
        'parent' => '6',
      ),
      'middle_right' => array(
        'type' => 'region',
        'title' => 'Middle Right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'block-9';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        '0' => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Show if course status is open for signup',
            'php' => '$show_statuses = array(\'10_open\');
if (in_array($contexts[\'argument_nid_1\']->data->field_course_status[0][\'value\'], $show_statuses)) {
  return TRUE;
}',
          ),
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'button-panel yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'content_field';
    $pane->subtype = 'field_course_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'course_photo_default',
      'context' => 'argument_nid_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'center';
    $pane->type = 'panels_mini';
    $pane->subtype = 'course_general_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        '0' => 'argument_nid_1',
      ),
      'override_title' => 1,
      'override_title_text' => '%node:title',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['center'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'dashboard_mytracker-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['center'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'og_members_faces';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '25',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Members',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-5'] = $pane;
    $display->panels['center'][4] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'top_region';
    $pane->type = 'block';
    $pane->subtype = 'p2pu-6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-6'] = $pane;
    $display->panels['top_region'][0] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'top_region';
    $pane->type = 'panels_mini';
    $pane->subtype = 'course_summary_and_syllabus';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        '0' => 'argument_nid_1',
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-7'] = $pane;
    $display->panels['top_region'][1] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'top_region';
    $pane->type = 'views_panes';
    $pane->subtype = 'activity_atrium-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-8'] = $pane;
    $display->panels['top_region'][2] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'top_region';
    $pane->type = 'panels_mini';
    $pane->subtype = 'prereq_and_signup_task';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        '0' => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Show if course status is draft or open for signup',
            'php' => '$show_statuses = array(\'00_draft\', \'10_open\');
if (in_array($contexts[\'argument_nid_1\']->data->field_course_status[0][\'value\'], $show_statuses)) {
  return TRUE;
}',
          ),
        ),
      ),
    );
    $pane->configuration = array(
      'context' => array(
        '0' => 'argument_nid_1',
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-9'] = $pane;
    $display->panels['top_region'][3] = 'new-9';
    $pane = new stdClass;
    $pane->pid = 'new-10';
    $pane->panel = 'top_region';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '2',
      'order' => '2',
      'comments_per_page' => '30',
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-10'] = $pane;
    $display->panels['top_region'][4] = 'new-10';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-3';
  $handler->conf['display'] = $display;

  $export['node_view_panel_context_2'] = $handler;
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Book Page',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'book' => 'book',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
          '1' => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '66.73798503769686',
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      '1' => array(
        'type' => 'column',
        'width' => '33.26201496230315',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          '0' => 2,
        ),
      ),
      '2' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'rightsidebar',
        ),
        'parent' => '1',
      ),
      'rightsidebar' => array(
        'type' => 'region',
        'title' => 'RightSideBar',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '%1',
      'teaser' => 0,
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'rightsidebar';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-about';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['rightsidebar'][0] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'rightsidebar';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-3'] = $pane;
    $display->panels['rightsidebar'][1] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;

  $export['node_view_panel_context_3'] = $handler;
  return $export;
}

/**
 * Helper to implementation of hook_default_page_manager_pages().
 */
function _p2pu_courses_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'book';
  $page->task = 'page';
  $page->admin_title = 'Document';
  $page->admin_description = '';
  $page->path = 'node/%node/document';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'course' => 'course',
          ),
        ),
        'context' => 'argument_nid_1',
      ),
      '1' => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'course_template' => 'course_template',
          ),
        ),
        'context' => 'argument_nid_1',
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Course Material',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'nid',
      'settings' => array(),
    ),
  );
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_book_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'book';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Course',
    'no_blocks' => 0,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'left',
          '1' => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '66.06978879706152',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '33.93021120293848',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '%3',
      'teaser' => 0,
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'panel_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '%0/%1/%2/%3',
      'url' => '',
      'display' => 'default',
      'context' => array(
        '0' => '',
        '1' => '',
        '2' => '',
        '3' => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Comments',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'p2pu-0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['center'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Add Document',
      'title' => '',
      'body' => '<?php
$group = og_get_group_context();
global $user;
if ($user->uid == 0) {
  $register = l(\'register\', \'user/register\', array(\'query\' => \'distination=node/\'.$group->nid));
  $login = l(\'login\', \'user/login\', array(\'query\' => \'distination=node/\'.$group->nid));
  print (\'You must \'.$register.\' or \'.$login.\' in order to post into this group.\');
  return;  
}
if (!og_is_group_member($group->nid)) {
  $label = \'Sign up\';
  if ($group->og_selective == 0) {
      $label = \'Join\';
  }
  $link = l($label, \'og/subscribe/\'.$group->nid, array(\'query\' => \'distination=node/\'.$group->nid));
  print ($link);
  return;
}
$link = l(\'Add a document\', \'node/add/document\', array(\'query\' => \'gids[]=\'.$group->nid));
print ($link);
?>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'button-panel yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-4'] = $pane;
    $display->panels['left'][0] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'course_documents_arg';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Course Material',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-5'] = $pane;
    $display->panels['left'][1] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_book_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'book';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Course Template',
    'no_blocks' => 0,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course_template' => 'course_template',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'left',
          '1' => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '66.06978879706152',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '33.93021120293848',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '%3',
      'teaser' => 0,
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'panel_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '%0/%1/%2/%3',
      'url' => '',
      'display' => 'default',
      'context' => array(
        '0' => '',
        '1' => '',
        '2' => '',
        '3' => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Add document',
      'title' => '',
      'body' => '<?php
$group = og_get_group_context();
global $user;
if ($user->uid == 0) {
  $register = l(\'register\', \'user/register\', array(\'query\' => \'distination=node/\'.$group->nid));
  $login = l(\'login\', \'user/login\', array(\'query\' => \'distination=node/\'.$group->nid));
  print (\'You must \'.$register.\' or \'.$login.\' in order to post into this group.\');
  return;  
}
if (!og_is_group_member($group->nid)) {
  $label = \'Sign up\';
  if ($group->og_selective == 0) {
      $label = \'Join\';
  }
  $link = l($label, \'og/subscribe/\'.$group->nid, array(\'query\' => \'distination=node/\'.$group->nid));
  print ($link);
  return;
}
$link = l(\'Add a document\', \'node/add/document\', array(\'query\' => \'gids[]=\'.$group->nid));
print ($link);
?>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'button-panel yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['left'][0] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'course_documents_arg';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Course Material',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-4'] = $pane;
    $display->panels['left'][1] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['book'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'calendar';
  $page->task = 'page';
  $page->admin_title = 'Calendar';
  $page->admin_description = '';
  $page->path = 'node/%node/group_calendar';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'Calendar',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'nid',
      'settings' => array(),
    ),
  );
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_calendar_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'calendar';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          '0' => 1,
        ),
        'parent' => 'canvas',
      ),
      '1' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'centre',
        ),
        'parent' => 'main',
      ),
      'centre' => array(
        'type' => 'region',
        'title' => 'Centre',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'centre';
    $pane->type = 'views';
    $pane->subtype = 'course_events';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '100',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_3',
      'context' => array(
        '0' => 'argument_nid_1.nid',
        '1' => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['centre'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['calendar'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'course_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Dashboard';
  $page->admin_description = '';
  $page->path = 'node/%node/dashboard';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'course' => 'course',
          ),
        ),
        'context' => 'argument_nid_1',
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'My Dashboard',
    'name' => 'navigation',
    'weight' => '-50',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'nid',
      'settings' => array(),
    ),
  );
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_dashboard_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'course_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -10;
  $handler->conf = array(
    'title' => 'Digital Journalism Course',
    'no_blocks' => 1,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
        '1' => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Course is KMD Digital Journalism 2010',
            'php' => 'if ($contexts[\'argument_nid_1\']->data->nid == 3838
) return TRUE;
else return FALSE;',
          ),
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'left',
          '1' => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '66.07156812656761',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '33.92843187343238',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'activity_atrium-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Recent activity in this course',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'og_mytracker-panel_pane_1';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'dashboard_mytracker-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['left'][0] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'course_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -9;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'left',
          '1' => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '66.07156812656761',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '33.92843187343238',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'activity_atrium-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Recent activity in this course',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'course_announcements';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'dashboard_mytracker-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['left'][0] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'og-0';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Actions',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-4'] = $pane;
    $display->panels['left'][1] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'og_members';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '90',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_2',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Members',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-5'] = $pane;
    $display->panels['left'][2] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'course_assignments';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'context' => array(
        '0' => 'argument_nid_1.nid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-6'] = $pane;
    $display->panels['left'][3] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'course_events';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_4',
      'context' => array(
        '0' => 'argument_nid_1.nid',
        '1' => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-7'] = $pane;
    $display->panels['left'][4] = 'new-7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['course_dashboard'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses';
  $page->task = 'page';
  $page->admin_title = '';
  $page->admin_description = '<br />
Panel page of courses list<br />
';
  $page->path = 'course/list';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Courses',
    'name' => 'primary-links',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = 'Courses';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'course_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'forums_panel';
  $page->task = 'page';
  $page->admin_title = 'Forums';
  $page->admin_description = '';
  $page->path = 'node/%node/forums';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'course' => 'course',
          ),
        ),
        'context' => 'argument_nid_1',
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Forums',
    'name' => 'navigation',
    'weight' => '15',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'nid',
      'settings' => array(),
    ),
  );
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_forums_panel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'forums_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        '0' => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'left_',
          '1' => 'right',
        ),
        'parent' => 'main',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '66.06978879706152',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'left_' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '33.93021120293848',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'left_';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Start a discussion',
      'title' => '',
      'body' => '<?php
      global $user;
    
    // Load the general discussion forum taxonomy term id for this course
    
      $forum_tid  = og_forum_get_forum_container(arg(1));
      $children = taxonomy_get_children($forum_tid);
      $children_tids = array_keys($children);
      // General discussion is the 1st item
      $forum_tid = $children_tids[0];
    
      $group = og_get_group_context();
      if ($user->uid == 0) {
        $register = l(\'register\', \'user/register\', array(\'query\' => \'destination=node/\'.$group->nid.\'/forums\'));
        $login = l(\'login\', \'user/login\', array(\'query\' => \'destination=node/\'.$group->nid.\'/forums\'));
        print (\'You must \'.$register.\' or \'.$login.\' in order to post into this group.\');
        return;  
      }
      if (!og_is_group_member($group->nid)) {
        $link = l(\'Sign-up\', \'og/subscribe/\'.$group->nid, array(\'query\' => \'destination=node/\'.$group->nid.\'/forums\'));
        print ($link);
        return;
      }
      $link = l(\'Start a discussion\', \'node/add/forum/\' . $forum_tid, array(\'query\' => \'gids[]=\'.$group->nid));
      print ($link);
    ?>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'button-panel yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['left_'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'left_';
    $pane->type = 'block';
    $pane->subtype = 'p2pu-3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'forum-rss-icon-block',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['left_'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'left_';
    $pane->type = 'views_panes';
    $pane->subtype = 'course_forum_posts-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['left_'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'left_';
    $pane->type = 'views_panes';
    $pane->subtype = 'course_forum_posts-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['left_'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'p2pu-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => 'forum-listing-pane',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['right'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'forum_post_and_comments';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        '0' => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Only display if viewing a single forum topic',
            'php' => 'if (arg(0) == \'node\' && is_numeric(arg(1)) && arg(2) == \'forums\' && is_numeric(arg(3))) {
          return TRUE;
          }
          return FALSE;',
          ),
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => 'forum-post-and-comments-mini-panel',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-6'] = $pane;
    $display->panels['right'][1] = 'new-6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['forums_panel'] = $page;

 return $pages;

}

/**
 * Helper to implementation of hook_default_panels_mini().
 */
function _p2pu_courses_default_panels_mini() {
  $export = array();
  $mini = new stdClass;
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'course_general_info';
  $mini->category = 'Course pages';
  $mini->title = 'Course general information';
  $mini->requiredcontexts = array(
    '0' => array(
      'name' => 'node',
      'id' => 1,
      'identifier' => 'Node',
      'keyword' => 'node',
    ),
  );
  $mini->contexts = FALSE;
  $mini->relationships = array(
    '0' => array(
      'context' => 'requiredcontext_node_1',
      'name' => 'user_from_node',
      'id' => 1,
      'identifier' => 'Node author',
      'keyword' => 'user',
    ),
  );
  $display = new panels_display;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'User picture and link',
      'title' => '',
      'body' => '<?php
$user_id = \'%node:uid\';
$realname_link = \'%node:realname-link\';
print "<div class=\'meta\'>\\n";
print theme(\'user_picture\',user_load(array(\'uid\'=>$user_id)));
print "<span class=\'created-date\'>Course organiser: $realname_link</span>\\n";
print "</div>\\n";
?>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'middle';
    $pane->type = 'content_field';
    $pane->subtype = 'field_course_facilitator_about';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'default',
      'context' => 'requiredcontext_node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'p2pu10_clean',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['middle'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'middle';
    $pane->type = 'content_field';
    $pane->subtype = 'field_course_no_of_seats';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'default',
      'context' => 'requiredcontext_node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'p2pu10_clean',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['middle'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'middle';
    $pane->type = 'content_field';
    $pane->subtype = 'field_course_status';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'default',
      'context' => 'requiredcontext_node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'p2pu10_clean',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['middle'][3] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;

  $export['course_general_info'] = $mini;
  $mini = new stdClass;
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'course_summary_and_syllabus';
  $mini->category = 'Course pages';
  $mini->title = 'Course Summary and Syllabus';
  $mini->requiredcontexts = array(
    '0' => array(
      'name' => 'node',
      'id' => 1,
      'identifier' => 'Node',
      'keyword' => 'node',
    ),
  );
  $mini->contexts = FALSE;
  $mini->relationships = FALSE;
  $display = new panels_display;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'content_field';
    $pane->subtype = 'field_course_summary';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'default',
      'context' => 'requiredcontext_node_1',
      'override_title' => 1,
      'override_title_text' => 'Summary',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'p2pu10_clean',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'middle';
    $pane->type = 'content_field';
    $pane->subtype = 'field_refers_to_syllabus';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'default',
      'context' => 'requiredcontext_node_1',
      'override_title' => 1,
      'override_title_text' => 'Course Syllabus',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'p2pu10_clean',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['middle'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;

  $export['course_summary_and_syllabus'] = $mini;
  $mini = new stdClass;
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'forum_post_and_comments';
  $mini->category = 'Forums';
  $mini->title = 'Forum post and comments';
  $mini->requiredcontexts = array();
  $mini->contexts = FALSE;
  $mini->relationships = FALSE;
  $display = new panels_display;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'middle' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'p2pu-2';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        '0' => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Only display viewing a single forum topic',
            'php' => 'if (arg(0) == \'node\' && is_numeric(arg(1)) && arg(2) == \'forums\' && is_numeric(arg(3))) {
          return TRUE;
          }
          return FALSE;',
          ),
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-on-orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;

  $export['forum_post_and_comments'] = $mini;
  $mini = new stdClass;
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'prereq_and_signup_task';
  $mini->category = 'Course pages';
  $mini->title = 'Prerequisites & Sign-Up Task';
  $mini->requiredcontexts = array(
    '0' => array(
      'name' => 'node',
      'id' => 1,
      'identifier' => 'Node',
      'keyword' => 'node',
    ),
  );
  $mini->contexts = FALSE;
  $mini->relationships = FALSE;
  $display = new panels_display;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'content_field';
    $pane->subtype = 'field_course_prerequisites';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'default',
      'context' => 'requiredcontext_node_1',
      'override_title' => 1,
      'override_title_text' => 'Prerequisites',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'p2pu10_clean',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'middle';
    $pane->type = 'content_field';
    $pane->subtype = 'field_course_sign_up_req';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'normal',
      'formatter' => 'default',
      'context' => 'requiredcontext_node_1',
      'override_title' => 1,
      'override_title_text' => 'Sign-Up Task',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'p2pu10_clean',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['middle'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;

  $export['prereq_and_signup_task'] = $mini;
  return $export;
}

/**
 * Helper to implementation of hook_rules_defaults().
 */
function _p2pu_courses_rules_defaults() {
  return array(
    'rules' => array(
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
            '#weight' => 0,
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
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'course' => 'course',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
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
            '#name' => 'rules_action_mail_to_users_of_role',
            '#info' => array(
              'label' => 'Send a mail to all users of a role',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#weight' => 0,
          ),
          '1' => array(
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
            '#type' => 'action',
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'auto_save' => 1,
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_core_p2pu_create_course_syllabus_action',
            '#info' => array(
              'module' => 'Node',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Create empty course syllabus document and link to course.',
              'base' => 'rules_core_action_execute',
              'action_name' => 'p2pu_create_course_syllabus_action',
              'configurable' => FALSE,
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _p2pu_courses_user_default_permissions() {
  $permissions = array();

  // Exported permission: create assignment content
  $permissions[] = array(
    'name' => 'create assignment content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: create course content
  $permissions[] = array(
    'name' => 'create course content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: create course_application content
  $permissions[] = array(
    'name' => 'create course_application content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: create discussion content
  $permissions[] = array(
    'name' => 'create discussion content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: create document content
  $permissions[] = array(
    'name' => 'create document content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: create event content
  $permissions[] = array(
    'name' => 'create event content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: create recommendation content
  $permissions[] = array(
    'name' => 'create recommendation content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: create report_card content
  $permissions[] = array(
    'name' => 'create report_card content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: create shout_box content
  $permissions[] = array(
    'name' => 'create shout_box content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: create submission content
  $permissions[] = array(
    'name' => 'create submission content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete any announcement content
  $permissions[] = array(
    'name' => 'delete any announcement content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any assignment content
  $permissions[] = array(
    'name' => 'delete any assignment content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any course content
  $permissions[] = array(
    'name' => 'delete any course content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any course_application content
  $permissions[] = array(
    'name' => 'delete any course_application content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any document content
  $permissions[] = array(
    'name' => 'delete any document content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any event content
  $permissions[] = array(
    'name' => 'delete any event content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any page content
  $permissions[] = array(
    'name' => 'delete any page content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any recommendation content
  $permissions[] = array(
    'name' => 'delete any recommendation content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any report_card content
  $permissions[] = array(
    'name' => 'delete any report_card content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any shout_box content
  $permissions[] = array(
    'name' => 'delete any shout_box content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete any submission content
  $permissions[] = array(
    'name' => 'delete any submission content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete own announcement content
  $permissions[] = array(
    'name' => 'delete own announcement content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: delete own assignment content
  $permissions[] = array(
    'name' => 'delete own assignment content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own course content
  $permissions[] = array(
    'name' => 'delete own course content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own course_application content
  $permissions[] = array(
    'name' => 'delete own course_application content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own event content
  $permissions[] = array(
    'name' => 'delete own event content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own recommendation content
  $permissions[] = array(
    'name' => 'delete own recommendation content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own report_card content
  $permissions[] = array(
    'name' => 'delete own report_card content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete own shout_box content
  $permissions[] = array(
    'name' => 'delete own shout_box content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete own submission content
  $permissions[] = array(
    'name' => 'delete own submission content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit any announcement content
  $permissions[] = array(
    'name' => 'edit any announcement content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any assignment content
  $permissions[] = array(
    'name' => 'edit any assignment content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any course content
  $permissions[] = array(
    'name' => 'edit any course content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any course_application content
  $permissions[] = array(
    'name' => 'edit any course_application content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any document content
  $permissions[] = array(
    'name' => 'edit any document content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any event content
  $permissions[] = array(
    'name' => 'edit any event content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any recommendation content
  $permissions[] = array(
    'name' => 'edit any recommendation content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any report_card content
  $permissions[] = array(
    'name' => 'edit any report_card content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any shout_box content
  $permissions[] = array(
    'name' => 'edit any shout_box content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any submission content
  $permissions[] = array(
    'name' => 'edit any submission content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit own announcement content
  $permissions[] = array(
    'name' => 'edit own announcement content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: edit own assignment content
  $permissions[] = array(
    'name' => 'edit own assignment content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: edit own course content
  $permissions[] = array(
    'name' => 'edit own course content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: edit own course_application content
  $permissions[] = array(
    'name' => 'edit own course_application content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own document content
  $permissions[] = array(
    'name' => 'edit own document content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: edit own event content
  $permissions[] = array(
    'name' => 'edit own event content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own recommendation content
  $permissions[] = array(
    'name' => 'edit own recommendation content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own report_card content
  $permissions[] = array(
    'name' => 'edit own report_card content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own shout_box content
  $permissions[] = array(
    'name' => 'edit own shout_box content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own submission content
  $permissions[] = array(
    'name' => 'edit own submission content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: schedule courses
  $permissions[] = array(
    'name' => 'schedule courses',
    'roles' => array(
      '0' => 'system',
    ),
  );

  return $permissions;
}
