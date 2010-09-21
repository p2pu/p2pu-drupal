<?php

/**
 * Implementation of hook_default_page_manager_handlers().
 */
function p2pu_courses_default_page_manager_handlers() {
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '33.945414408990565',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
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
      1 => array(
        'type' => 'column',
        'width' => '66.05458559100944',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
          1 => 3,
          2 => 4,
        ),
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
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
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
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
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'centre',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
    $pane->api_version = 1;
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '33.945414408990565',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
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
      1 => array(
        'type' => 'column',
        'width' => '66.05458559100944',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 4,
          1 => 3,
          2 => 2,
        ),
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
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
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
          1 => 6,
        ),
        'parent' => '1',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top_region',
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
      5 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 7,
        ),
      ),
      6 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 8,
        ),
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_left',
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
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_right',
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
    $pane->api_version = 1;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'block-9';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
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
    $pane->api_version = 1;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Custom course dates block (static)',
      'title' => '<none>',
      'body' => 'Sign-up closes 8 Sep. The course starts on 15 Sep. Applicants will be notified of acceptance by 8 Sep.',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'yellow-panel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-3';
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
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['center'][2] = 'new-3';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-4';
    $pane->panel = 'center';
    $pane->type = 'panels_mini';
    $pane->subtype = 'course_general_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
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
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['center'][3] = 'new-4';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-5';
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
    $pane->position = 4;
    $display->content['new-5'] = $pane;
    $display->panels['center'][4] = 'new-5';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-6';
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
        0 => 'argument_nid_1.nid',
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
    $pane->position = 5;
    $display->content['new-6'] = $pane;
    $display->panels['center'][5] = 'new-6';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-7';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Hide if course applications are closed',
            'php' => 'if ($contexts[\'argument_nid_1\']->data->og_selective != 3) {
	return TRUE;
}',
          ),
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Custom: temporary leave this course link',
      'title' => '<none>',
      'body' => '<?php
  global $user;
  $nid = arg(1);
  if (og_is_group_member($nid, FALSE)) {
    print \'<strong>\' . l(t(\'Unsubscribe from this course\'), "og/unsubscribe/$nid/$user->uid") . \'</strong>\';
  }
?>',
      'format' => '3',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grey-panel',
    );
    $pane->extras = array();
    $pane->position = 6;
    $display->content['new-7'] = $pane;
    $display->panels['center'][6] = 'new-7';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-8';
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
    $display->content['new-8'] = $pane;
    $display->panels['top_region'][0] = 'new-8';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-9';
    $pane->panel = 'top_region';
    $pane->type = 'panels_mini';
    $pane->subtype = 'course_summary_and_syllabus';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_nid_1',
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
    $display->content['new-9'] = $pane;
    $display->panels['top_region'][1] = 'new-9';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-10';
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
    $display->content['new-10'] = $pane;
    $display->panels['top_region'][2] = 'new-10';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-11';
    $pane->panel = 'top_region';
    $pane->type = 'panels_mini';
    $pane->subtype = 'prereq_and_signup_task';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
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
        0 => 'argument_nid_1',
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
    $display->content['new-11'] = $pane;
    $display->panels['top_region'][3] = 'new-11';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-12';
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
    $display->content['new-12'] = $pane;
    $display->panels['top_region'][4] = 'new-12';
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-13';
    $pane->panel = 'top_region';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_nid_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $display->content['new-13'] = $pane;
    $display->panels['top_region'][5] = 'new-13';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-4';
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '66.73798503769686',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
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
      1 => array(
        'type' => 'column',
        'width' => '33.26201496230315',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'rightsidebar',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
 * Implementation of hook_default_page_manager_pages().
 */
function p2pu_courses_default_page_manager_pages() {
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
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'course' => 'course',
          ),
        ),
        'context' => 'argument_nid_1',
      ),
      1 => array(
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
    'type' => 'none',
    'settings' => NULL,
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => '',
        1 => '',
        2 => '',
        3 => '',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => '',
        1 => '',
        2 => '',
        3 => '',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'centre',
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
        1 => '',
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
      0 => array(
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
    'type' => 'none',
    'settings' => NULL,
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
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'course' => 'course',
            ),
          ),
          'context' => 'argument_nid_1',
        ),
        1 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
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
    $pane->api_version = 1;
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
        0 => 'argument_nid_1.nid',
        1 => '',
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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $display->api_version = 1;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = 'Courses';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->api_version = 1;
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
      0 => array(
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
        0 => array(
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
  $display->api_version = 1;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_',
          1 => 'right',
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
    $pane->api_version = 1;
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
      else {
        // Only show to members of the course
        // Load the general discussion forum taxonomy term id for this course
        $forum_tid  = og_forum_get_forum_container(arg(1));
        $children = taxonomy_get_children($forum_tid);
        $children_tids = array_keys($children);
        // General discussion is the 1st item
        $forum_tid = $children_tids[0];        
        $link = l(\'Start a discussion\', \'node/add/forum/\' . $forum_tid, array(\'query\' => \'gids[]=\'.$group->nid));
        print ($link);        
      }

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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
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
    $pane->api_version = 1;
    $pane->pid = 'new-6';
    $pane->panel = 'right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'forum_post_and_comments';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
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

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'webcraft_course_listing';
  $page->task = 'page';
  $page->admin_title = 'Webcraft: Course listing';
  $page->admin_description = '';
  $page->path = 'course-listing';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_webcraft_course_listing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'webcraft_course_listing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel: Webcraft courses listing',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->api_version = 1;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Webcraft courses';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->api_version = 1;
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'course_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'orange-panel',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['webcraft_course_listing'] = $page;

 return $pages;

}
