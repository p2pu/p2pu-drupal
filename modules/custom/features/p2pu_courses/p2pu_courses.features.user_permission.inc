<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function p2pu_courses_user_default_permissions() {
  $permissions = array();

  // Exported permission: create assignment content
  $permissions['create assignment content'] = array(
    'name' => 'create assignment content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: create course content
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: create course_application content
  $permissions['create course_application content'] = array(
    'name' => 'create course_application content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: create discussion content
  $permissions['create discussion content'] = array(
    'name' => 'create discussion content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: create document content
  $permissions['create document content'] = array(
    'name' => 'create document content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: create event content
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: create recommendation content
  $permissions['create recommendation content'] = array(
    'name' => 'create recommendation content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: create report_card content
  $permissions['create report_card content'] = array(
    'name' => 'create report_card content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: create shout_box content
  $permissions['create shout_box content'] = array(
    'name' => 'create shout_box content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: create submission content
  $permissions['create submission content'] = array(
    'name' => 'create submission content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete any announcement content
  $permissions['delete any announcement content'] = array(
    'name' => 'delete any announcement content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any assignment content
  $permissions['delete any assignment content'] = array(
    'name' => 'delete any assignment content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any course content
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any course_application content
  $permissions['delete any course_application content'] = array(
    'name' => 'delete any course_application content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any document content
  $permissions['delete any document content'] = array(
    'name' => 'delete any document content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any event content
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any recommendation content
  $permissions['delete any recommendation content'] = array(
    'name' => 'delete any recommendation content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any report_card content
  $permissions['delete any report_card content'] = array(
    'name' => 'delete any report_card content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete any shout_box content
  $permissions['delete any shout_box content'] = array(
    'name' => 'delete any shout_box content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete any submission content
  $permissions['delete any submission content'] = array(
    'name' => 'delete any submission content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: delete own announcement content
  $permissions['delete own announcement content'] = array(
    'name' => 'delete own announcement content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: delete own assignment content
  $permissions['delete own assignment content'] = array(
    'name' => 'delete own assignment content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own course content
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own course_application content
  $permissions['delete own course_application content'] = array(
    'name' => 'delete own course_application content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own event content
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own recommendation content
  $permissions['delete own recommendation content'] = array(
    'name' => 'delete own recommendation content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: delete own report_card content
  $permissions['delete own report_card content'] = array(
    'name' => 'delete own report_card content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete own shout_box content
  $permissions['delete own shout_box content'] = array(
    'name' => 'delete own shout_box content',
    'roles' => array(
      '0' => 'system',
    ),
  );

  // Exported permission: delete own submission content
  $permissions['delete own submission content'] = array(
    'name' => 'delete own submission content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit any announcement content
  $permissions['edit any announcement content'] = array(
    'name' => 'edit any announcement content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any assignment content
  $permissions['edit any assignment content'] = array(
    'name' => 'edit any assignment content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any course content
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any course_application content
  $permissions['edit any course_application content'] = array(
    'name' => 'edit any course_application content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any document content
  $permissions['edit any document content'] = array(
    'name' => 'edit any document content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any event content
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any recommendation content
  $permissions['edit any recommendation content'] = array(
    'name' => 'edit any recommendation content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any report_card content
  $permissions['edit any report_card content'] = array(
    'name' => 'edit any report_card content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any shout_box content
  $permissions['edit any shout_box content'] = array(
    'name' => 'edit any shout_box content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit any submission content
  $permissions['edit any submission content'] = array(
    'name' => 'edit any submission content',
    'roles' => array(
      '0' => 'system',
      '1' => 'webmaster',
    ),
  );

  // Exported permission: edit own announcement content
  $permissions['edit own announcement content'] = array(
    'name' => 'edit own announcement content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: edit own assignment content
  $permissions['edit own assignment content'] = array(
    'name' => 'edit own assignment content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: edit own course content
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: edit own course_application content
  $permissions['edit own course_application content'] = array(
    'name' => 'edit own course_application content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own document content
  $permissions['edit own document content'] = array(
    'name' => 'edit own document content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'course organiser',
      '2' => 'system',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: edit own event content
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own recommendation content
  $permissions['edit own recommendation content'] = array(
    'name' => 'edit own recommendation content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own report_card content
  $permissions['edit own report_card content'] = array(
    'name' => 'edit own report_card content',
    'roles' => array(
      '0' => 'course organiser',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own shout_box content
  $permissions['edit own shout_box content'] = array(
    'name' => 'edit own shout_box content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: edit own submission content
  $permissions['edit own submission content'] = array(
    'name' => 'edit own submission content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'system',
    ),
  );

  // Exported permission: schedule courses
  $permissions['schedule courses'] = array(
    'name' => 'schedule courses',
    'roles' => array(
      '0' => 'system',
    ),
  );

  return $permissions;
}
