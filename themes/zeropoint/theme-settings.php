<?php

function phptemplate_settings($saved_settings) {
//  $settings = theme_get_settings('zeropoint');

  // Only open one of the general or node setting fieldsets at a time
$js = <<<SCRIPT
  $(document).ready(function(){
    $("fieldset.general_settings > legend > a").click(function(){
      if(!$("fieldset.node_settings").hasClass("collapsed")) {
        Drupal.toggleFieldset($("fieldset.node_settings"));
      }
    });
    $("fieldset.node_settings > legend > a").click(function(){
      if (!$("fieldset.general_settings").hasClass("collapsed")) {
        Drupal.toggleFieldset($("fieldset.general_settings"));
      }
    });
  });
SCRIPT;
drupal_add_js($js, 'inline');

  // Get the node types
  $node_types = node_get_types('names');

/**
 * The default values for the theme variables. Make sure $defaults exactly
 * matches the $defaults in the template.php file.
 */
  $defaults = array(
    'style' => 'grey',
    'layout-width'    => 0,
    'sidebarslayout'  => 0,
    'themedblocks'    => 0,
    'blockicons'      => 2,
    'pageicons'       => 1,
    'menutype'        => 0,
    'navpos'          => 0,
    'roundcorners'    => 1,
    'cssPreload'      => 0,
    'user_notverified_display'         => 1,
    'breadcrumb_display'               => 1,
    'search_snippet'                   => 1,
    'search_info_type'                 => 0,
    'search_info_user'                 => 1,
    'search_info_date'                 => 1,
    'search_info_comment'              => 1,
    'search_info_upload'               => 1,
    'mission_statement_pages'          => 'home',
    'front_page_title_display'         => 'title_slogan',
    'page_title_display_custom'        => '',
    'other_page_title_display'         => 'ptitle_stitle',
    'other_page_title_display_custom'  => '',
    'configurable_separator'           => ' | ',
    'meta_keywords'                    => '',
    'meta_description'                 => '',
    'taxonomy_display_default'         => 'only',
    'taxonomy_format_default'          => 'list',
    'taxonomy_enable_content_type'     => 0,
    'submitted_by_author_default'      => 1,
    'submitted_by_date_default'        => 1,
    'submitted_by_enable_content_type' => 0,
    'rebuild_registry'                 => 0,
  );

  // Make the default content-type settings the same as the default theme settings,
  // so we can tell if content-type-specific settings have been altered.
  $defaults = array_merge($defaults, theme_get_settings());

  // Set the default values for content-type-specific settings
  foreach ($node_types as $type => $name) {
    $defaults["taxonomy_display_{$type}"]    = $defaults['taxonomy_display_default'];
    $defaults["taxonomy_format_{$type}"]     = $defaults['taxonomy_format_default'];
    $defaults["submitted_by_author_{$type}"] = $defaults['submitted_by_author_default'];
    $defaults["submitted_by_date_{$type}"]   = $defaults['submitted_by_date_default'];
  }

  // Merge the saved variables and their default values
  $settings = array_merge($defaults, $saved_settings);



  // Create theme settings form widgets using Forms API

  // TNT Fieldset
  $form['tnt_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Zero Point settings'),
    '#description' => t('Use these settings to change what and how information is displayed in your theme.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Layout Settings
  $form['tnt_container']['layout_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#attributes' => array('class' => 'layout_settings'),
  );

  $form['tnt_container']['layout_settings']['style'] = array(
    '#type' => 'select',
    '#title' => t('Style'),
    '#default_value' => $settings['style'],
    '#options' => array(
      'grey' => t('0 Point'),
      'sky' => t('Sky'),
      'nature' => t('Nature'),
      'ivy' => t('Ivy'),
      'ink' => t('Ink'),
      'sangue' => t('Sangue'),
      'lime' => t('Lime'),
    ),
  );

  $form['tnt_container']['layout_settings']['layout-width'] = array(
    '#type' => 'select',
    '#title' => t('Layout width'),
    '#default_value' => $settings['layout-width'],
    '#description' => t('<em>Fluid width</em> and <em>Fixed width</em> can be customized in _custom/custom-style.css.'),
    '#options' => array(
      0 => 'Adaptive width',
      1 => 'Fluid width (custom)',
      2 => 'Fixed width (custom)',
    ),
  );

  $form['tnt_container']['layout_settings']['sidebarslayout'] = array(
    '#type' => 'select',
    '#title' => t('Sidebars layout'),
    '#default_value' => $settings['sidebarslayout'],
    '#description' => t('<b>Variable width sidebars (wide)</b>: If only one sidebar is enabled, content width is 250px for left sidebar and 300px for right sidebar. If both sidebars are enabled, content width is 160px for left sidebar and 234px for right sidebar. <br /> <b>Fixed width sidebars (wide)</b>: Content width is 160px for left sidebar and 234px for right sidebar. <br /> <em>Equal width sidebars</em> ca be customized in _custom/custom-style.css. For other details, please refer to readme.txt.'),
    '#options' => array(
      0 => 'Variable asyimmetrical sidebars (wide)',
      1 => 'Fixed asyimmetrical sidebars (wide)',
      2 => 'Variable asyimmetrical sidebars (narrow)',
      3 => 'Fixed asyimmetrical sidebars (narrow)',
      4 => 'Equal width sidebars (custom)',
    )
  );

  $form['tnt_container']['layout_settings']['themedblocks'] = array(
    '#type' => 'select',
    '#title' => t('Themed blocks'),
    '#default_value' => $settings['themedblocks'],
    '#options' => array(
      0 => 'Sidebars only',
      1 => 'Sidebars + User regions',
    )
  );

  $form['tnt_container']['layout_settings']['blockicons'] = array(
    '#type' => 'select',
    '#title' => t('Block icons'),
    '#default_value' => $settings['blockicons'],
    '#options' => array(
      0 => 'No',
      1 => 'Yes (32x32 pixels)',
      2 => 'Yes (48x48 pixels)',
    )
  );

  $form['tnt_container']['layout_settings']['pageicons'] = array(
    '#type' => 'checkbox',
    '#title' => t('Page icons'),
    '#default_value' => $settings['pageicons'],
  );

  $form['tnt_container']['layout_settings']['menutype'] = array(
    '#type' => 'select',
    '#title' => t('Menu type'),
    '#default_value' => $settings['menutype'],
    '#description' => t('Choose "Suckerfish" to enable support for Suckerfish drop down menus. <br /> NOTE: Go to <b><a href="/admin/build/menu">admin/build/menu</a></b> and expand all parents in primary menu.'),
    '#options' => array(
      0 => 'Static',
      1 => 'Suckerfish',
    )
  );

  $form['tnt_container']['layout_settings']['navpos'] = array(
    '#type' => 'select',
    '#title' => t('Menu position'),
    '#default_value' => $settings['navpos'],
    '#options' => array(
      0 => 'Left',
      1 => 'Center',
      2 => 'Right',
    )
  );

  $form['tnt_container']['layout_settings']['roundcorners'] = array(
    '#type' => 'checkbox',
    '#title' => t('Rounded corners'),
    '#description' => t('Some page elements (mission, comments, search, blocks) and primary menu will have rounded corners in all browsers but IE. NOTE: With this option enabled 0 Point will not validate CSS2.'),
    '#default_value' => $settings['roundcorners'],
  );

  $form['tnt_container']['layout_settings']['cssPreload'] = array(
    '#type' => 'checkbox',
    '#title' => t('jQuery CSS image preload'),
    '#description' => t('Automatically Preload images from CSS.'),
    '#default_value' => $settings['cssPreload'],
  );

  // General Settings
  $form['tnt_container']['general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#attributes' => array('class' => 'general_settings'),
  );

  // Mission Statement
  $form['tnt_container']['general_settings']['mission_statement'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mission statement'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['tnt_container']['general_settings']['mission_statement']['mission_statement_pages'] = array(
    '#type' => 'radios',
    '#title' => t('Where should your mission statement be displayed?'),
    '#default_value' => $settings['mission_statement_pages'],
    '#options' => array(
      'home' => t('Display mission statement only on front page'),
      'all' => t('Display mission statement on all pages'),
    ),
  );

  // Breadcrumb
  $form['tnt_container']['general_settings']['breadcrumb'] = array(
    '#type' => 'fieldset',
    '#title' => t('Breadcrumb'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['tnt_container']['general_settings']['breadcrumb']['breadcrumb_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display breadcrumb'),
    '#default_value' => $settings['breadcrumb_display'],
  );

  // Username
  $form['tnt_container']['general_settings']['username'] = array(
    '#type' => 'fieldset',
    '#title' => t('Username'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['tnt_container']['general_settings']['username']['user_notverified_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display "not verified" for unregistered usernames'),
    '#default_value' => $settings['user_notverified_display'],
  );

  // Search Settings
  if (module_exists('search')) {
    $form['tnt_container']['general_settings']['search_container'] = array(
      '#type' => 'fieldset',
      '#title' => t('Search results'),
      '#description' => t('What additional information should be displayed on your search results page?'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['tnt_container']['general_settings']['search_container']['search_results']['search_snippet'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display text snippet'),
      '#default_value' => $settings['search_snippet'],
    );
    $form['tnt_container']['general_settings']['search_container']['search_results']['search_info_type'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display content type'),
      '#default_value' => $settings['search_info_type'],
    );
    $form['tnt_container']['general_settings']['search_container']['search_results']['search_info_user'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display author name'),
      '#default_value' => $settings['search_info_user'],
    );
    $form['tnt_container']['general_settings']['search_container']['search_results']['search_info_date'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display posted date'),
      '#default_value' => $settings['search_info_date'],
    );
    $form['tnt_container']['general_settings']['search_container']['search_results']['search_info_comment'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display comment count'),
      '#default_value' => $settings['search_info_comment'],
    );
    $form['tnt_container']['general_settings']['search_container']['search_results']['search_info_upload'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display attachment count'),
      '#default_value' => $settings['search_info_upload'],
    );
  }

  // Node Settings
  $form['tnt_container']['node_type_specific'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node settings'),
    '#description' => t('Here you can make adjustments to which information is shown with your content, and how it is displayed.  You can modify these settings so they apply to all content types, or check the "Use content-type specific settings" box to customize them for each content type.  For example, you may want to show the date on stories, but not pages.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#attributes' => array('class' => 'node_settings'),
  );
  
  // Author & Date Settings
  $form['tnt_container']['node_type_specific']['submitted_by_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Author & date'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Default & content-type specific settings
  if (module_exists('submitted_by') == FALSE) {
    foreach ((array('default' => 'Default') + node_get_types('names')) as $type => $name) {
      $form['tnt_container']['node_type_specific']['submitted_by_container']['submitted_by'][$type] = array(
        '#type' => 'fieldset',
        '#title' => t('!name', array('!name' => t($name))),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['tnt_container']['node_type_specific']['submitted_by_container']['submitted_by'][$type]["submitted_by_author_{$type}"] = array(
        '#type' => 'checkbox',
        '#title' => t('Display author\'s username'),
        '#default_value' => $settings["submitted_by_author_{$type}"],
      );
      $form['tnt_container']['node_type_specific']['submitted_by_container']['submitted_by'][$type]["submitted_by_date_{$type}"] = array(
        '#type' => 'checkbox',
        '#title' => t('Display date posted (you can customize this format on your Date and Time settings page)'),
        '#default_value' => $settings["submitted_by_date_{$type}"],
      );
      // Options for default settings
      if ($type == 'default') {
        $form['tnt_container']['node_type_specific']['submitted_by_container']['submitted_by']['default']['#title'] = t('Default');
        $form['tnt_container']['node_type_specific']['submitted_by_container']['submitted_by']['default']['#collapsed'] = $settings['submitted_by_enable_content_type'] ? TRUE : FALSE;
        $form['tnt_container']['node_type_specific']['submitted_by_container']['submitted_by']['submitted_by_enable_content_type'] = array(
          '#type' => 'checkbox',
          '#title' => t('Use custom settings for each content type instead of the default above'),
          '#default_value' => $settings['submitted_by_enable_content_type'],
        );
      }
      // Collapse content-type specific settings if default settings are being used
      else if ($settings['submitted_by_enable_content_type'] == 0) {
        $form['submitted_by'][$type]['#collapsed'] = TRUE;
      }
    }
  } else {
      $form['tnt_container']['node_type_specific']['submitted_by_container']['#description'] = 'NOTICE: You currently have the "Submitted By" module installed and enabled, so the Author & Date theme settings have been disabled to prevent conflicts.  If you wish to re-enable the Author & Date theme settings, you must first disable the "Submitted By" module.';
  }

  // Taxonomy Settings
  if (module_exists('taxonomy')) {
    $form['tnt_container']['node_type_specific']['display_taxonomy_container'] = array(
      '#type' => 'fieldset',
      '#title' => t('Taxonomy terms'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    // Default & content-type specific settings
    foreach ((array('default' => 'Default') + node_get_types('names')) as $type => $name) {
      // taxonomy display per node
      $form['tnt_container']['node_type_specific']['display_taxonomy_container']['display_taxonomy'][$type] = array(
        '#type' => 'fieldset',
        '#title' => t('!name', array('!name' => t($name))),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      // display
      $form['tnt_container']['node_type_specific']['display_taxonomy_container']['display_taxonomy'][$type]["taxonomy_display_{$type}"] = array(
        '#type' => 'select',
        '#title' => t('When should taxonomy terms be displayed?'),
        '#default_value' => $settings["taxonomy_display_{$type}"],
        '#options' => array(
          '' => '',
          'never' => t('Never display taxonomy terms'),
          'all' => t('Always display taxonomy terms'),
          'only' => t('Only display taxonomy terms on full node pages'),
        ),
      );
      // format
      $form['tnt_container']['node_type_specific']['display_taxonomy_container']['display_taxonomy'][$type]["taxonomy_format_{$type}"] = array(
        '#type' => 'radios',
        '#title' => t('Taxonomy display format'),
        '#default_value' => $settings["taxonomy_format_{$type}"],
        '#options' => array(
          'vocab' => t('Display each vocabulary on a new line'),
          'list' => t('Display all taxonomy terms together in single list'),
        ),
      );
      // Get taxonomy vocabularies by node type
      $vocabs = array();
      $vocabs_by_type = ($type == 'default') ? taxonomy_get_vocabularies() : taxonomy_get_vocabularies($type);
      foreach ($vocabs_by_type as $key => $value) {
        $vocabs[$value->vid] = $value->name;
      }
      // Display taxonomy checkboxes
      foreach ($vocabs as $key => $vocab_name) {
        $form['tnt_container']['node_type_specific']['display_taxonomy_container']['display_taxonomy'][$type]["taxonomy_vocab_hide_{$type}_{$key}"] = array(
          '#type' => 'checkbox',
          '#title' => t('Hide vocabulary: '. $vocab_name),
          '#default_value' => $settings["taxonomy_vocab_hide_{$type}_{$key}"], 
        );
      }
      // Options for default settings
      if ($type == 'default') {
        $form['tnt_container']['node_type_specific']['display_taxonomy_container']['display_taxonomy']['default']['#title'] = t('Default');
        $form['tnt_container']['node_type_specific']['display_taxonomy_container']['display_taxonomy']['default']['#collapsed'] = $settings['taxonomy_enable_content_type'] ? TRUE : FALSE;
        $form['tnt_container']['node_type_specific']['display_taxonomy_container']['display_taxonomy']['taxonomy_enable_content_type'] = array(
          '#type' => 'checkbox',
          '#title' => t('Use custom settings for each content type instead of the default above'),
          '#default_value' => $settings['taxonomy_enable_content_type'],
        );
      }
      // Collapse content-type specific settings if default settings are being used
      else if ($settings['taxonomy_enable_content_type'] == 0) {
        $form['display_taxonomy'][$type]['#collapsed'] = TRUE;
      }
    }
  }

  // SEO settings
  $form['tnt_container']['seo'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search engine optimization (SEO) settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  // Page titles
  $form['tnt_container']['seo']['page_format_titles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page titles'),
    '#description' => t('This is the title that displays in the title bar of your web browser. Your site title, slogan, and mission can all be set on your Site Information page. [NOTE: For more advanced page title functionality, consider using the "Page Title" module.  However, the Page titles theme settings do not work in combination with the "Page Title" module and will be disabled if you have it enabled.]'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  if (module_exists('page_title') == FALSE) {
    // front page title
    $form['tnt_container']['seo']['page_format_titles']['front_page_format_titles'] = array(
      '#type' => 'fieldset',
      '#title' => t('Front page title'),
      '#description' => t('Your front page in particular should have important keywords for your site in the page title'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['tnt_container']['seo']['page_format_titles']['front_page_format_titles']['front_page_title_display'] = array(
      '#type' => 'select',
      '#title' => t('Set text of front page title'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#default_value' => $settings['front_page_title_display'],
      '#options' => array(
        'title_slogan' => t('Site title | Site slogan'),
        'slogan_title' => t('Site slogan | Site title'),
        'title_mission' => t('Site title | Site mission'),
        'custom' => t('Custom (below)'),
      ),
    );
    $form['tnt_container']['seo']['page_format_titles']['front_page_format_titles']['page_title_display_custom'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom'),
      '#size' => 60,
      '#default_value' => $settings['page_title_display_custom'],
      '#description' => t('Enter a custom page title for your front page'),
    );
    // other pages title
    $form['tnt_container']['seo']['page_format_titles']['other_page_format_titles'] = array(
      '#type' => 'fieldset',
      '#title' => t('Other page titles'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['tnt_container']['seo']['page_format_titles']['other_page_format_titles']['other_page_title_display'] = array(
      '#type' => 'select',
      '#title' => t('Set text of other page titles'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#default_value' => $settings['other_page_title_display'],
      '#options' => array(
        'ptitle_slogan' => t('Page title | Site slogan'),
        'ptitle_stitle' => t('Page title | Site title'),
        'ptitle_smission' => t('Page title | Site mission'),
        'ptitle_custom' => t('Page title | Custom (below)'),
        'custom' => t('Custom (below)'),
      ),
    );
    $form['tnt_container']['seo']['page_format_titles']['other_page_format_titles']['other_page_title_display_custom'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom'),
      '#size' => 60,
      '#default_value' => $settings['other_page_title_display_custom'],
      '#description' => t('Enter a custom page title for all other pages'),
    );
    // SEO configurable separator
    $form['tnt_container']['seo']['page_format_titles']['configurable_separator'] = array(
      '#type' => 'textfield',
      '#title' => t('Title separator'),
      '#description' => t('Customize the separator character used in the page title'),
      '#size' => 60,
      '#default_value' => $settings['configurable_separator'],
    );
  } else {
      $form['tnt_container']['seo']['page_format_titles']['#description'] = 'NOTICE: You currently have the "Page Title" module installed and enabled, so the Page titles theme settings have been disabled to prevent conflicts.  If you wish to re-enable the Page titles theme settings, you must first disable the "Page Title" module.';
      $form['tnt_container']['seo']['page_format_titles']['configurable_separator']['#disabled'] = 'disabled';
  }
  // Metadata
  $form['tnt_container']['seo']['meta'] = array(
    '#type' => 'fieldset',
    '#title' => t('Meta tags'),
    '#description' => t('Meta tags are not used as much by search engines anymore, but the meta description is important: it will be shown as the description of your link in search engine results. [NOTE: For more advanced meta tag functionality, consider using the "Meta Tags (or nodewords)" module.  However, the Meta tags theme settings do not work in combination with the "Meta Tags" module and will be disabled if you have it enabled.]'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  if (module_exists('nodewords') == FALSE) {
    $form['tnt_container']['seo']['meta']['meta_keywords'] = array(
      '#type' => 'textfield',
      '#title' => t('Meta keywords'),
      '#description' => t('Enter a comma-separated list of keywords'),
      '#size' => 60,
      '#default_value' => $settings['meta_keywords'],
    );
    $form['tnt_container']['seo']['meta']['meta_description'] = array(
      '#type' => 'textarea',
      '#title' => t('Meta description'),
      '#cols' => 60,
      '#rows' => 6,
      '#default_value' => $settings['meta_description'],
    );
  } else {
      $form['tnt_container']['seo']['meta']['#description'] = 'NOTICE: You currently have the "Meta Tags (or nodewords)" module installed and enabled, so the Meta tags theme settings have been disabled to prevent conflicts.  If you wish to re-enable the Meta tags theme settings, you must first disable the "Meta Tags" module.';
      $form['tnt_container']['seo']['meta']['meta_keywords']['#disabled'] = 'disabled';
      $form['tnt_container']['seo']['meta']['meta_description']['#disabled'] = 'disabled';
  }
  // Development settings
  $form['tnt_container']['themedev'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme development settings'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings['rebuild_registry'] ? FALSE : TRUE,
  );
 $form['tnt_container']['themedev']['rebuild_registry'] = array(
    '#type' => 'checkbox',
    '#title' => t('Rebuild theme registry on every page.'),
    '#default_value' => $settings['rebuild_registry'],
    '#description' => t('During theme development, it can be very useful to continuously rebuild the theme registry. WARNING: this is a huge performance penalty and must be turned off on production websites.', array('!link' => 'http://drupal.org/node/173880#theme-registry')),
  );

  // Return theme settings form
  return $form;
}  
