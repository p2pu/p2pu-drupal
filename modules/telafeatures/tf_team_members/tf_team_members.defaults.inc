<?php

/**
 * Helper to implemetation of hook_content_default_fields().
 */
function _tf_team_members_content_default_fields() {
  $fields = array();

  // Exported field: field_team_member_body
  $fields[] = array(
    'field_name' => 'field_team_member_body',
    'type_name' => 'team_member',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'token' => array(
        'format' => 'trimmed',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'trimmed',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'trimmed',
        'exclude' => 0,
      ),
      'full' => array(
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
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_team_member_body][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Bio',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_team_member_main_image
  $fields[] = array(
    'field_name' => 'field_team_member_main_image',
    'type_name' => 'team_member',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'token' => array(
        'format' => 'team-members-small_linked',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'team-members-small_linked',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'team-members-small_linked',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'imagefield__lightbox2__team-members-large__original',
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
    'widget' => array(
      'file_extensions' => 'jpeg jpg png gif',
      'file_path' => 'u-[author-uid]/[type]',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '640x480',
      'min_resolution' => 0,
      'alt' => '[title]',
      'custom_alt' => 1,
      'title' => '[title]',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Main Image',
      'weight' => '-4',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('Bio'),
    t('Main Image'),
  );

  return $fields;
}

/**
 * Helper to implemetation of hook_imagecache_default_presets().
 */
function _tf_team_members_imagecache_default_presets() {
  $items = array(
    'team-members-large' => array(
      'presetname' => 'team-members-large',
      'actions' => array(
        '0' => array(
          'actionid' => '8',
          'presetid' => '8',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '150',
            'height' => '150',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'team-members-small' => array(
      'presetname' => 'team-members-small',
      'actions' => array(
        '0' => array(
          'actionid' => '9',
          'presetid' => '9',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '60px',
            'height' => '60px',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implemetation of hook_menu_default_items().
 */
function _tf_team_members_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Team Members',
    'path' => 'team-members',
    'weight' => '0',
  );
  // Translatables
  array(
    t('Team Members'),
  );


  return $items;
}

/**
 * Helper to implemetation of hook_node_info().
 */
function _tf_team_members_node_info() {
  $items = array(
    'team_member' => array(
      'name' => t('Team Member'),
      'module' => 'node',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => t(''),
    ),
  );
  return $items;
}

/**
 * Helper to implemetation of hook_views_default_views().
 */
function _tf_team_members_views_default_views() {
  $views = array();

  // Exported view: tf_team_members
  $view = new view;
  $view->name = 'tf_team_members';
  $view->description = 'TelaFeature: Team Members Basic';
  $view->tag = 'telafeature, team members';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'field_team_member_main_image_fid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'team-members-large_linked',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_team_member_main_image_fid',
      'table' => 'node_data_field_team_member_main_image',
      'field' => 'field_team_member_main_image_fid',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_team_member_body_value' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '150',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 1,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_team_member_body_value',
      'table' => 'node_data_field_team_member_body',
      'field' => 'field_team_member_body_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'team_member' => 'team_member',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Team Members');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 9);
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('use_more', 1);
  $handler->override_option('style_plugin', 'grid');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'columns' => '3',
    'alignment' => 'horizontal',
  ));
  $handler = $view->new_display('page', 'Page: Team Members', 'page_1');
  $handler->override_option('path', 'team-members');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Team Members',
    'description' => '',
    'weight' => '0',
    'name' => 'features',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));

  $views[$view->name] = $view;

  return $views;
}
