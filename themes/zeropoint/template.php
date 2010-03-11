<?php

/**
 * Initialize theme settings
 */
if (is_null(theme_get_setting('user_notverified_display')) || theme_get_setting('rebuild_registry')) {

  // Auto-rebuild the theme registry during theme development.
  if(theme_get_setting('rebuild_registry')) {
    drupal_set_message(t('The theme registry has been rebuilt. <a href="!link">Turn off</a> this feature on production websites.', array('!link' => url('admin/build/themes/settings/' . $GLOBALS['theme']))), 'warning');
  }

  global $theme_key;
  // Get node types
  $node_types = node_get_types('names');

/**
 * The default values for the theme variables. Make sure $defaults exactly
 * matches the $defaults in the theme-settings.php file.
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

  // Get default theme settings.
  $settings = theme_get_settings($theme_key);


  // Don't save the toggle_node_info_ variables
  if (module_exists('node')) {
    foreach (node_get_types() as $type => $name) {
      unset($settings['toggle_node_info_'. $type]);
    }
  }
  // Save default theme settings
  variable_set(
    str_replace('/', '_', 'theme_'. $theme_key .'_settings'),
    array_merge($defaults, $settings)
  );
  // Force refresh of Drupal internals
  theme_get_setting('', TRUE);
}


// Get styles (add css stylesheets here to avoid IE 30 stylesheets limit)
function get_zeropoint_style() {
  $style = theme_get_setting('style');
  return $style;
}
drupal_add_css(drupal_get_path('theme','zeropoint').'/css/style-zero.css');
drupal_add_css(drupal_get_path('theme','zeropoint') . '/css/' . get_zeropoint_style() . '.css');
drupal_add_css(drupal_get_path('theme','zeropoint').'/_custom/custom-style.css');

$roundcorners = theme_get_setting('roundcorners');
  if ($roundcorners == '1'){ 
	  drupal_add_css(drupal_get_path('theme','zeropoint').'/css/round.css', 'theme');
}


/**
 * Modify theme variables
 */
function phptemplate_preprocess(&$vars) {
  global $user;                                           // Get the current user
  $vars['is_admin'] = in_array('ADMIN', $user->roles);    // Check for Admin, logged in
  $vars['logged_in'] = ($user->uid > 0) ? TRUE : FALSE;
}


function phptemplate_preprocess_page(&$vars) {
// Remove the duplicate meta content-type tag, a bug in Drupal 6
	$vars['head'] = preg_replace('/<meta http-equiv=\"Content-Type\"[^>]*>/', '', $vars['head']);
// Remove sidebars if disabled
  if (!$vars['show_blocks']) {
    $vars['left'] = '';
    $vars['right'] = '';
  }

// Build array of helpful body classes
  $body_classes = array();
  $body_classes[] = 'layout-'. (($vars['left']) ? 'left-main' : 'main') . (($vars['right']) ? '-right' : '');  // Page sidebars are active (Jello Mold)
  $body_classes[] = ($vars['is_admin']) ? 'admin' : 'not-admin';                                    // Page user is admin
  $body_classes[] = ($vars['logged_in']) ? 'logged-in' : 'not-logged-in';                           // Page user is logged in
  $body_classes[] = ($vars['is_front']) ? 'front' : 'not-front';                                    // Page is front page
  if (isset($vars['node'])) {
    $body_classes[] = ($vars['node']) ? 'full-node' : '';                                           // Page is one full node
    $body_classes[] = (($vars['node']->type == 'forum') || (arg(0) == 'forum')) ? 'forum' : '';     // Page is Forum page
    $body_classes[] = ($vars['node']->type) ? 'node-type-'. $vars['node']->type : '';               // Page has node-type-x, e.g., node-type-page
    $body_classes[] = ($vars['node']->nid) ? 'nid-'. $vars['node']->nid : '';                       // Page has id-x, e.g., id-32
  }
  else {
    $body_classes[] = (arg(0) == 'forum') ? 'forum' : '';                                           // Page is Forum page
  }

// Add any taxonomy terms for node pages
  if (isset($vars['node']->taxonomy)) {
    foreach ($vars['node']->taxonomy as $taxonomy_id => $term_info) {
      $body_classes[] = 'tag-'. $taxonomy_id;                                                       // Page has terms (tag-x)
//      $taxonomy_name = id_safe($term_info->name);
//      if ($taxonomy_name) {
//        $body_classes[] = 'tag-'. $taxonomy_name;                                                 // Page has terms (tag-name)
//      }
    }
  }

// Add unique classes for each page and website section
  if (!$vars['is_front']) {
    $path = drupal_get_path_alias($_GET['q']);
    list($section, ) = explode('/', $path, 2);
    $body_classes[] = id_safe('section-' . $section);
    $body_classes[] = id_safe('page-' . $path);
    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        if ($section == 'node') {
          array_pop($body_classes); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-add'; // Add 'section-node-add'
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        if ($section == 'node') {
          array_pop($body_classes); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-' . arg(2); // Add 'section-node-edit' or 'section-node-delete'
      }
    }
  }

// Build array of additional body classes and retrieve custom theme settings
$layoutwidth = theme_get_setting('layout-width');
  if ($layoutwidth == '0'){ 
    $body_classes[] = 'layout-jello';
  }
  if ($layoutwidth == '1'){ 
    $body_classes[] = 'layout-fluid';
  }
  if ($layoutwidth == '2'){ 
    $body_classes[] = 'layout-fixed';
  }
$sidebarslayout = theme_get_setting('sidebarslayout');
  if ($sidebarslayout == '0'){ 
	  $body_classes[] = (($vars['left']) ? 'l-m' : 'm') . (($vars['right']) ? '-r' : '') . '-var';
  }
  if ($sidebarslayout == '1'){ 
	  $body_classes[] = (($vars['left']) ? 'l-m' : 'm') . (($vars['right']) ? '-r' : '') . '-fix';
  }
  if ($sidebarslayout == '2'){ 
	  $body_classes[] = (($vars['left']) ? 'l-m' : 'm') . (($vars['right']) ? '-r' : '') . '-var1';
  }
  if ($sidebarslayout == '3'){ 
	  $body_classes[] = (($vars['left']) ? 'l-m' : 'm') . (($vars['right']) ? '-r' : '') . '-fix1';
  }
  if ($sidebarslayout == '4'){ 
	  $body_classes[] = (($vars['left']) ? 'l-m' : 'm') . (($vars['right']) ? '-r' : '') . '-eq';
  }
$dropdown = theme_get_setting('menutype'); // if dropdown enabled 
  if ($dropdown == '1'){ 
    $body_classes[] = 'sfish';
	}
$blockicons = theme_get_setting('blockicons');
  if ($blockicons == '1'){ 
    $body_classes[] = 'bicons32';
  }
  if ($blockicons == '2'){ 
    $body_classes[] = 'bicons48';
  }
$pageicons = theme_get_setting('pageicons');
  if ($pageicons == '1'){ 
    $body_classes[] = 'picons';
  }

// Add Panels classes and lang
  $body_classes[] = (module_exists('panels_page') && (panels_page_get_current())) ? 'panels' : '';  // Page is Panels page
  $body_classes[] = ($vars['language']->language) ? 'lg-'. $vars['language']->language : '';        // Page has lang-x

  $body_classes = array_filter($body_classes);                                                      // Remove empty elements
  $vars['body_classes'] = implode(' ', $body_classes);                                              // Create class list separated by spaces

// Generate menu tree from source of primary links
  $vars['primary_links_tree'] = menu_tree(variable_get('menu_primary_links_source', 'primary-links'));



// TNT THEME SETTINGS SECTION
// Display mission statement on all pages
  if (theme_get_setting('mission_statement_pages') == 'all') {
    $vars['mission'] = theme_get_setting('mission', false);  
  }

// Hide breadcrumb on all pages
  if (theme_get_setting('breadcrumb_display') == 0) {
    $vars['breadcrumb'] = '';  
  }

// Set site title, slogan, mission, page title & separator (unless using Page Title module)
  if (!module_exists('page_title')) {
    $title = t(variable_get('site_name', ''));
    $slogan = t(variable_get('site_slogan', ''));
    $mission = t(variable_get('site_mission', ''));
    $page_title = t(drupal_get_title());
    $title_separator = theme_get_setting('configurable_separator');
    if (drupal_is_front_page()) {                                                // Front page title settings
      switch (theme_get_setting('front_page_title_display')) {
        case 'title_slogan':
          $vars['head_title'] = drupal_set_title($title . $title_separator . $slogan);
          break;
        case 'slogan_title':
          $vars['head_title'] = drupal_set_title($slogan . $title_separator . $title);
          break;
        case 'title_mission':
          $vars['head_title'] = drupal_set_title($title . $title_separator . $mission);
          break;
        case 'custom':
          if (theme_get_setting('page_title_display_custom') !== '') {
            $vars['head_title'] = drupal_set_title(t(theme_get_setting('page_title_display_custom')));
          }
      }
    }
    else {                                                                       // Non-front page title settings
      switch (theme_get_setting('other_page_title_display')) {
        case 'ptitle_slogan':
          $vars['head_title'] = drupal_set_title($page_title . $title_separator . $slogan);
          break;
        case 'ptitle_stitle':
          $vars['head_title'] = drupal_set_title($page_title . $title_separator . $title);
          break;
        case 'ptitle_smission':
          $vars['head_title'] = drupal_set_title($page_title . $title_separator . $mission);
          break;
        case 'ptitle_custom':
          if (theme_get_setting('other_page_title_display_custom') !== '') {
            $vars['head_title'] = drupal_set_title($page_title . $title_separator . t(theme_get_setting('other_page_title_display_custom')));
          }
          break;
        case 'custom':
          if (theme_get_setting('other_page_title_display_custom') !== '') {
            $vars['head_title'] = drupal_set_title(t(theme_get_setting('other_page_title_display_custom')));
          }
      }
    }
    $vars['head_title'] = strip_tags($vars['head_title']);                       // Remove any potential html tags
  }

// Set meta keywords and description (unless using Meta tags module)
  if (!module_exists('nodewords')) {
    if (theme_get_setting('meta_keywords') !== '') {
      $keywords = '<meta name="keywords" content="'. theme_get_setting('meta_keywords') .'" />';
      $vars['head'] .= $keywords ."\n";
    } 
    if (theme_get_setting('meta_description') !== '') {
      $keywords = '<meta name="description" content="'. theme_get_setting('meta_description') .'" />';
      $vars['head'] .= $keywords ."\n";
    } 
  }
  $vars['closure'] .= '<div class="page"><div class="sizer"><div class="expander0"><div class="by"><a href="http://www.radut.net">Theme by Dr. Radut</a>.</div></div></div></div>';
}


function phptemplate_preprocess_block(&$vars) {
// Add regions with themed blocks (e.g., left, right) to $themed_regions array and retrieve custom theme settings
$themedblocks = theme_get_setting('themedblocks');
  if ($themedblocks == '0'){ 
  $themed_regions = array('left','right');
}
  if ($themedblocks == '1'){ 
  $themed_regions = array('left','right','user1','user2','user3','user4','user5','user6','user7','user8');
}
  $vars['themed_block'] = (in_array($vars['block']->region, $themed_regions)) ? TRUE : FALSE;
}

function phptemplate_preprocess_node(&$vars) {
// Add node region
  if (!$vars['teaser']){
    foreach (array('content_middle') as $region) {
    $vars[$region] = theme('blocks', $region);
    }
  }

// Build array of handy node classes
  $node_classes = array();
  $node_classes[] = $vars['zebra'];                                              // Node is odd or even
  $node_classes[] = (!$vars['node']->status) ? 'node-unpublished' : '';          // Node is unpublished
  $node_classes[] = ($vars['sticky']) ? 'sticky' : '';                           // Node is sticky
  $node_classes[] = (isset($vars['node']->teaser)) ? 'teaser' : 'full-node';     // Node is teaser or full-node
  $node_classes[] = 'node-type-'. $vars['node']->type;                           // Node is type-x, e.g., node-type-page

// Add any taxonomy terms for node teasers
  if ($vars['teaser'] && isset($vars['taxonomy'])) {
    foreach ($vars['taxonomy'] as $taxonomy_id_string => $term_info) {
      $taxonomy_id = array_pop(explode('_', $taxonomy_id_string));
      $node_classes[] = 'tag-'. $taxonomy_id;                                    // Node teaser has terms (tag-x)
//      $taxonomy_name = id_safe($term_info['title']);
//      if ($taxonomy_name) {
//        $node_classes[] = 'tag-'. $taxonomy_name;                              // Node teaser has terms (tag-name)
//      }
    }
  }

  $node_classes = array_filter($node_classes);                                  // Remove empty elements
  $vars['node_classes'] = implode(' ', $node_classes);                          // Implode class list with spaces

// Add node_bottom region content
  $vars['node_bottom'] = theme('blocks', 'node_bottom');

// Render Ubercart fields into separate variables for node-product.tpl.php
if (module_exists('uc_product') && uc_product_is_product($vars) && $vars['template_files'][0] == 'node-product') {
  $node = node_build_content(node_load($vars['nid']));
  $vars['uc_image'] = drupal_render($node->content['image']);
  $vars['uc_body'] = drupal_render($node->content['body']);
  $vars['uc_display_price'] = drupal_render($node->content['display_price']);
  $vars['uc_add_to_cart'] = drupal_render($node->content['add_to_cart']);
  $vars['uc_weight'] = drupal_render($node->content['weight']);
  $vars['uc_dimensions'] = drupal_render($node->content['dimensions']);
  $vars['uc_model'] = drupal_render($node->content['model']);
  $vars['uc_list_price'] = drupal_render($node->content['list_price']);
  $vars['uc_sell_price'] = drupal_render($node->content['sell_price']);
  $vars['uc_cost'] = drupal_render($node->content['cost']);
  $vars['uc_additional'] = drupal_render($node->content);
}



// Node Theme Settings

// Date & author
  if (!module_exists('submitted_by')) {
    $date = t('') . format_date($vars['node']->created, 'medium');               // Format date as small, medium, or large
    $author = theme('username', $vars['node']);
    $author_only_separator = t('');
    $author_date_separator = t(' &#151; ');
    $submitted_by_content_type = (theme_get_setting('submitted_by_enable_content_type') == 1) ? $vars['node']->type : 'default';
    $date_setting = (theme_get_setting('submitted_by_date_'. $submitted_by_content_type) == 1);
    $author_setting = (theme_get_setting('submitted_by_author_'. $submitted_by_content_type) == 1);
    $author_separator = ($date_setting) ? $author_date_separator : $author_only_separator;
    $date_author = ($date_setting) ? $date : '';
    $date_author .= ($author_setting) ? $author_separator . $author : '';
    $vars['submitted'] = $date_author;
  }

// Taxonomy
  $taxonomy_content_type = (theme_get_setting('taxonomy_enable_content_type') == 1) ? $vars['node']->type : 'default';
  $taxonomy_display = theme_get_setting('taxonomy_display_'. $taxonomy_content_type);
  $taxonomy_format = theme_get_setting('taxonomy_format_'. $taxonomy_content_type);
  if ((module_exists('taxonomy')) && ($taxonomy_display == 'all' || ($taxonomy_display == 'only' && $vars['page']))) {
    $vocabularies = taxonomy_get_vocabularies($vars['node']->type);
    $output = '';
    $term_delimiter = ' | ';
    foreach ($vocabularies as $vocabulary) {
      if (theme_get_setting('taxonomy_vocab_hide_'. $taxonomy_content_type .'_'. $vocabulary->vid) != 1) {
        $terms = taxonomy_node_get_terms_by_vocabulary($vars['node'], $vocabulary->vid);
        if ($terms) {
          $term_items = '';
          foreach ($terms as $term) {                        // Build vocabulary term items
            $term_link = l($term->name, taxonomy_term_path($term), array('attributes' => array('rel' => 'tag', 'title' => strip_tags($term->description))));
            $term_items .= '<li class="vocab-term">'. $term_link . $term_delimiter .'</li>';
          }
          if ($taxonomy_format == 'vocab') {                 // Add vocabulary labels if separate
            $output .= '<li class="vocab vocab-'. $vocabulary->vid .'"><span class="vocab-name">'. $vocabulary->name .':</span> <ul class="vocab-list">';
            //$output .= '<li class="vocab vocab-'. $vocabulary->vid .'"> <ul class="vocab-list">';
            $output .= substr_replace($term_items, '</li>', -(strlen($term_delimiter) + 5)) .'</ul></li>';
          }
          else {
            $output .= $term_items;
          }
        }
      }
    }
    if ($output != '') {
      $output = ($taxonomy_format == 'list') ? substr_replace($output, '</li>', -(strlen($term_delimiter) + 5)) : $output;
      $output = '<ul class="taxonomy">'. $output .'</ul>';
    }
    $vars['terms'] = $output;
  }
  else {
    $vars['terms'] = '';
  }
}


function phptemplate_preprocess_comment(&$vars) {
  global $user;
  // Build array of handy comment classes
  $comment_classes = array();
  static $comment_odd = TRUE;                                                                             // Comment is odd or even
  $comment_classes[] = $comment_odd ? 'odd' : 'even';
  $comment_odd = !$comment_odd;
  $comment_classes[] = ($vars['comment']->status == COMMENT_NOT_PUBLISHED) ? 'comment-unpublished' : '';  // Comment is unpublished
  $comment_classes[] = ($vars['comment']->new) ? 'comment-new' : '';                                      // Comment is new
  $comment_classes[] = ($vars['comment']->uid == 0) ? 'comment-by-anon' : '';                             // Comment is by anonymous user
  $comment_classes[] = ($user->uid && $vars['comment']->uid == $user->uid) ? 'comment-mine' : '';         // Comment is by current user
  $node = node_load($vars['comment']->nid);                                                               // Comment is by node author
  $vars['author_comment'] = ($vars['comment']->uid == $node->uid) ? TRUE : FALSE;
  $comment_classes[] = ($vars['author_comment']) ? 'comment-by-author' : '';
  $comment_classes = array_filter($comment_classes);                                                      // Remove empty elements
  $vars['comment_classes'] = implode(' ', $comment_classes);                                              // Create class list separated by spaces
  // Date & author
  $submitted_by = t('') .'<span class="comment-name">'.  theme('username', $vars['comment']) .'</span>';
  $submitted_by .= t(' - ') .'<span class="comment-date">'.  format_date($vars['comment']->timestamp, 'small') .'</span>';  // Format date as small, medium, or large
  $vars['submitted'] = $submitted_by;
}


/**
 * Set defaults for comments display
 * (Requires comment-wrapper.tpl.php file in theme directory)
 */
function phptemplate_preprocess_comment_wrapper(&$vars) {
  $vars['display_mode']  = COMMENT_MODE_FLAT_EXPANDED;
  $vars['display_order'] = COMMENT_ORDER_OLDEST_FIRST;
  $vars['comment_controls_state'] = COMMENT_CONTROLS_HIDDEN;
}


/**
 * Adds a class for the style of view  
 * (e.g., node, teaser, list, table, etc.)
 * (Requires views-view.tpl.php file in theme directory)
 */
function phptemplate_preprocess_views_view(&$vars) {
  $vars['css_name'] = $vars['css_name'] .' view-style-'. views_css_safe(strtolower($vars['view']->type));
}


/**
 * Modify search results based on theme settings
 */
function phptemplate_preprocess_search_result(&$variables) {
  static $search_zebra = 'even';
  $search_zebra = ($search_zebra == 'even') ? 'odd' : 'even';
  $variables['search_zebra'] = $search_zebra;
  
  $result = $variables['result'];
  $variables['url'] = check_url($result['link']);
  $variables['title'] = check_plain($result['title']);

  // Check for existence. User search does not include snippets.
  $variables['snippet'] = '';
  if (isset($result['snippet']) && theme_get_setting('search_snippet')) {
    $variables['snippet'] = $result['snippet'];
  }
  
  $info = array();
  if (!empty($result['type']) && theme_get_setting('search_info_type')) {
    $info['type'] = check_plain($result['type']);
  }
  if (!empty($result['user']) && theme_get_setting('search_info_user')) {
    $info['user'] = $result['user'];
  }
  if (!empty($result['date']) && theme_get_setting('search_info_date')) {
    $info['date'] = format_date($result['date'], 'small');
  }
  if (isset($result['extra']) && is_array($result['extra'])) {
    // $info = array_merge($info, $result['extra']);  Drupal bug?  [extra] array not keyed with 'comment' & 'upload'
    if (!empty($result['extra'][0]) && theme_get_setting('search_info_comment')) {
      $info['comment'] = $result['extra'][0];
    }
    if (!empty($result['extra'][1]) && theme_get_setting('search_info_upload')) {
      $info['upload'] = $result['extra'][1];
    }
  }

  // Provide separated and grouped meta information.
  $variables['info_split'] = $info;
  $variables['info'] = implode(' - ', $info);

  // Provide alternate search result template.
  $variables['template_files'][] = 'search-result-'. $variables['type'];
}


/**
 * Override username theming to display/hide 'not verified' text
 */
function phptemplate_username($object) {
  if ($object->uid && $object->name) {
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($object->name, 0, 15) .'...';
    }
    else {
      $name = $object->name;
    }
    if (user_access('access user profiles')) {
      $output = l($name, 'user/'. $object->uid, array('attributes' => array('title' => t('View user profile.'))));
    }
    else {
      $output = check_plain($name);
    }
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if (!empty($object->homepage)) {
      $output = l($object->name, $object->homepage, array('attributes' => array('rel' => 'nofollow')));
    }
    else {
      $output = check_plain($object->name);
    }
    // Display or hide 'not verified' text
    if (theme_get_setting('user_notverified_display') == 1) {
      $output .= ' ('. t('not verified') .')';
    }
  }
  else {
    $output = variable_get('anonymous', t('Anonymous'));
  }
  return $output;
}


/**
 * Set default form file input size 
 */
function phptemplate_file($element) {
  $element['#size'] = 40;
  return theme_file($element);
}


/**
 * Creates a link with prefix and suffix text
 *
 * @param $prefix
 *   The text to prefix the link.
 * @param $suffix
 *   The text to suffix the link.
 * @param $text
 *   The text to be enclosed with the anchor tag.
 * @param $path
 *   The Drupal path being linked to, such as "admin/content/node". Can be an external
 *   or internal URL.
 *     - If you provide the full URL, it will be considered an
 *   external URL.
 *     - If you provide only the path (e.g. "admin/content/node"), it is considered an
 *   internal link. In this case, it must be a system URL as the url() function
 *   will generate the alias.
 * @param $options
 *   An associative array that contains the following other arrays and values
 *     @param $attributes
 *       An associative array of HTML attributes to apply to the anchor tag.
 *     @param $query
 *       A query string to append to the link.
 *     @param $fragment
 *       A fragment identifier (named anchor) to append to the link.
 *     @param $absolute
 *       Whether to force the output to be an absolute link (beginning with http:).
 *       Useful for links that will be displayed outside the site, such as in an RSS
 *       feed.
 *     @param $html
 *       Whether the title is HTML or not (plain text)
 * @return
 *   an HTML string containing a link to the given path.
 */
function _themesettings_link($prefix, $suffix, $text, $path, $options) {
  return $prefix . (($text) ? l($text, $path, $options) : '') . $suffix;
}


/**
 * Breadcrumb override
 */
function phptemplate_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    $breadcrumb[] = drupal_get_title();  // full breadcrumb ( › = â€º , » = &#187; &raquo;)
    return '<div class="breadcrumb">'. implode(' &raquo; ', $breadcrumb) .'</div>';
  }
}


/**
 * Converts a string to a suitable html ID attribute.
 *
 * http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
 * valid ID attribute in HTML. This function:
 *
 * - Ensure an ID starts with an alpha character by optionally adding an 'id'.
 * - Replaces any character except A-Z, numbers, and underscores with dashes.
 * - Converts entire string to lowercase.
 *
 * @param $string
 *   The string
 * @return
 *   The converted string
 */
function id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9_-]+/', '-', $string));
  // If the first character is not a-z, add 'n' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id' . $string;
  }
  return $string;
}


// retrieve additional custom theme settings

$preload = theme_get_setting('cssPreload'); // print the js file if css image preload enabled
  if ($preload == '1'){
    drupal_add_js(drupal_get_path('theme','zeropoint').'/js/preloadCssImages.jQuery_v5.js'); // load the javascript
    drupal_add_js('$(document).ready(function(){
    $.preloadCssImages();
  });
  ','inline');
}

function menupos() {
  $navpos = theme_get_setting('navpos'); // Primary links position 
    if ($navpos == '0'){ 
      return 'navleft';
  }
    if ($navpos == '1'){ 
      return 'navcenter';
  }
    if ($navpos == '2'){ 
      return 'navright';
  }
}


// Quick fix for the validation error: 'ID "edit-submit" already defined'
$elementCountForHack = 0;
function phptemplate_submit($element) {
	global $elementCountForHack;
	return str_replace('edit-submit', 'edit-submit-' . ++$elementCountForHack, theme('button', $element));
}


/**
 * CUSTOM
 */

/**
 * Use this to return links or whatever
 */
function toplinks() {
}
