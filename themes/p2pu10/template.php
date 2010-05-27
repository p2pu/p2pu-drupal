<?php
include_once('bootstrap.inc');



// --------------------------------------------------------------- Preprocessors



/**
 * Hooked to provide dynamic theme variables
 * @param $vars
 *   A keyed array of variables to pass to the page template
 *
 * @return array of variables
 */
function p2pu10_preprocess_page($vars = array()) {
  
  _page_variables($vars);
  
  return $vars;
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
function p2pu10_preprocess_comment(&$vars, $hook) {
  // Add an "unpublished" flag.
  $vars['unpublished'] = ($vars['comment']->status == COMMENT_NOT_PUBLISHED);

  // If comment subjects are disabled, don't display them.
  if (variable_get('comment_subject_field_' . $vars['node']->type, 1) == 0) {
    $vars['title'] = '';
  }

  // Special classes for comments.
  $classes = array('comment');
  if ($vars['comment']->new) {
    $classes[] = 'comment-new';
  }
  $classes[] = $vars['status'];
  $classes[] = $vars['zebra'];
  if ($vars['id'] == 1) {
    $classes[] = 'first';
  }

  if ($vars['id'] == $vars['node']->comment_count) {
    $classes[] = 'last';
  }
  if ($vars['comment']->uid == 0) {
    // Comment is by an anonymous user.
    $classes[] = 'comment-by-anon';
  }
  else {
    if ($vars['comment']->uid == $vars['node']->uid) {
      // Comment is by the node author.
      $classes[] = 'comment-by-author';
    }
    if ($vars['comment']->uid == $GLOBALS['user']->uid) {
      // Comment was posted by current user.
      $classes[] = 'comment-mine';
    }
  }
  $vars['classes'] = implode(' ', $classes);
}

/**
 * Hooked to add node-type-teaser.tpl.php to suggested templates
 * @param $vars
 *   A keyed array of variables to pass to the node template
 *
 * @return a keyed array of variables
 */
function p2pu10_preprocess_node($vars = array()) {

  $imagecache_id = variable_get('user_picture_imagecache_profiles_default', FALSE);

  if ($imagecache_id){
    $preset = imagecache_preset($imagecache_id);
    $vars['picture'] = theme('imagecache', $preset['presetname'], $vars['user']->picture);
  }

  if($vars['teaser']) {
    $vars['template_files'] = array(
      'node-teaser', 
      'node-'.$vars['node']->type.'-teaser',
    );
  }
  if ($vars['type'] == 'forum' && !empty($vars['og_forum_nid'])) {
    // We're using our own node-forum.tpl.php so set up some variables to use
    $vars['p2pu_forum_author'] = isset($vars['node']->uid) ? theme('username', $vars['node']) : '';
    $vars['p2pu_forum_time'] = isset($vars['node']->created) ? format_interval(time() - $vars['node']->created) : '';
  
    $course_name = array_values($vars['og_groups_both']);
    $tid = p2pu_get_discussion_forum_tid($vars['og_forum_nid']);
    $forum = taxonomy_get_term($tid);
    $vars['back_to_forum_link'] = l(t('Go back to: ') . $forum->name, 'node/' . $vars['og_forum_nid'] . '/forums');
  }
  return $vars;
}



// ----------------------------------------------------------------- Theme hooks



/**
 * Implementation of theme_table
 * Wraps tables to provide horisontal scrolling if needed
 */
function p2pu10_table(
    $header, $rows, $attributes = array(), $caption = NULL){
  return
    '<div class="table-wrapper">'.
    theme_table($header, $rows, $attributes, $caption).
    '</div>';
}



function p2pu10_form_element($element, $value) {
  $output  = '<div class="form-item"';
  if (!empty($element['#id'])) {
    $output .= ' id="'. $element['#id'] .'-wrapper"';
  }
  $output .= ">\n";
  $required = !empty($element['#required']) ? '<span class="form-required" title="'. t('This field is required.') .'">*</span>' : '';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    if (!empty($element['#id'])) {
      $output .= ' <label for="'. $element['#id'] .'">'. t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
    else {
      $output .= ' <label>'. t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
  }

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
  }

  $output .= " $value\n";

  $output .= "</div>\n";

  return $output;
}

// ---------------------------------------------------------- Graphical themeing



function p2pu10_logo(){
  $url = theme_get_setting('logo');
  $title = t('Home');
  return module_exists('page_elements')
    ? theme('graphical_logo', $url, $title)
    : '<a href="/" title="'.$title.'">'.
        '<img src="'.$url.'" alt="'.$title.'"/>'.
      '</a>';
}

function p2pu10_primary_links(){
  $primary_links = menu_primary_links();
  return module_exists('page_elements')
    ? theme('graphical_main_navigation', $primary_links, 'primary')
    : theme_links($primary_links);
}

function p2pu10_secondary_links(){
  $secondary_links = menu_secondary_links();
  return module_exists('page_elements')
    ? theme('graphical_main_navigation', $secondary_links, 'secondary')
    : theme_links($secondary_links);
}

function p2pu10_page_title($title){
  return module_exists('page_elements')
    ? theme('graphical_page_title', $title)
    : '<h1 class="title">'.$title.'</h1>';
}

function p2pu10_block_title($title){
  return module_exists('page_elements')
    ? theme('graphical_block_title', $title)
    : '<h2 class="title">'.$title.'</h2>';
}

function p2pu10_menu_local_tasks(){
  return module_exists('page_elements')
    ? theme('graphical_menu_local_tasks')
    : theme_menu_local_tasks();
}

function p2pu10_button($element){
  return module_exists('page_elements')
    ? theme('graphical_button', $element)
    : theme_button($element);
}

function p2pu10_menu_item_link($link) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }

  $link['localized_options']['html'] = TRUE;
  return l('<span>'.$link['title'].'</span>', $link['href'], $link['localized_options']);
}

function p2pu10_theme(){
  return array(
    'logo' => array(),
    'primary_links' => array(),
    'secondary_links' => array(),
    'page_title' => array('title' => FALSE),
    'block_title' => array('title' => FALSE),
    'button' => array('element' => array()),
    'form_element' => array('element' => array(), 'value' => ''),
  );
}



// ----------------------------------------------------------- Utility functions



/**
 * Adds page custom page variables
 *
 * @param $vars
 *   keyed array of existing page variables
 */
function _page_variables(&$vars){
  
  $custom_grid =
    theme_get_setting('column-count') != 24 ||
    theme_get_setting('column-width') != 30 ||
    theme_get_setting('column-margin') != 10;

  // Toggles
  $vars['logo'] = theme_get_setting('toggle_logo')
    ? theme('logo')
    : FALSE;
  $vars['primary_links'] = theme_get_setting('toggle_primary_links')
    ? theme('primary_links')
    : FALSE;
  $vars['secondary_links'] = theme_get_setting('toggle_secondary_links')
    ? theme('secondary_links')
    : FALSE;
  $vars['breadcrumb'] = theme_get_setting('show-breadcrumb')
    ? $vars['breadcrumb']
    : FALSE;
  $vars['title'] = $vars['title']
    ? theme('page_title', $vars['title'])
    : FALSE;
    
  if (theme_get_setting('toggle_slogan')) {
    $vars['site_slogan'] = variable_get('site_slogan', '');
  }
  
  // Body classes
  $alias = array_shift(explode('/', drupal_get_path_alias($_GET['q'])));
  $body_class['path'] = theme_get_setting('path-class')
    ? 'path-'.arg(0) : '';
  $body_class['alias'] = theme_get_setting('alias-class') && $alias
    ? 'alias-'.arg(0) : '';

  $vars['body_class'] = 
    ' class="'.
    $vars['body_classes'].
    (count($body_class) > 0
      ? ' '
      : ''
    ).
    implode(' ', $body_class).'"';
}



/**
 * Converts a title into an id
 *
 * @param string $title
 */
function _title_to_id($title){
  return ereg_replace('[\ ]+', '-', 
            ereg_replace('[^a-z0-9\ \-]*', '', 
              strtolower(
                trim(
                  htmlspecialchars_decode($title, ENT_QUOTES)
                )
              )
            )
          );
}

//added by George Z to tidy up the comments information - removed text: Submitted By
function p2pu10_comment_submitted($comment) {
  $submitted = t('!username',
    array(
      '!username' => theme('username', $comment)
    ));
  $submitted .= "<div id='comment-submitted-date'>\n";
  $submitted .= t('@datetime.',
    array(
      '@datetime' => format_date($comment->timestamp)
    ));
  $submitted .= "</div>\n";
  return $submitted;
}

// --------------------------------------------------------------- Views themeng
