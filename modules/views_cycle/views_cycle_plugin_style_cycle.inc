<?php
// $Id: views_cycle_plugin_style_cycle.inc,v 1.1.2.4 2010/01/13 20:20:42 crell Exp $

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item in a slideshow of an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class views_cycle_plugin_style_cycle extends views_plugin_style_list {

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['skin'] = 'default';
    $options['skin_info'] = array();
    $options['height'] = 0;
    $options['verticalPadding'] = 5;
    $options['thumbnail_field'] = array('default' => '');
    $options['pager']['event'] = array('default' => 'click');
    $options['params']['fx'] = array('default' => 'fade');
    $options['params']['timeout'] = array('default' => 2000);
    $options['params']['speed'] = array('default' => 2000);

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Pre-build all of our option lists for the dials and switches that follow.
    $fields = array('' => t('<None>'));
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if ($label = $handler->label()) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }

    // This list copied from the jQuery Cycle home page.
    $transitions = array(
      'blindX'      => t('Blinds (Horizontal)'),
      'blindY'      => t('Blinds (Vertical)'),
      'blindZ'      => t('Blinds (3D)'),
      'cover'       => t('Cover'),
      'curtainX'    => t('Curtain (Horizontal)'),
      'curtainY'    => t('Curtain (Vertical)'),
      'fade'        => t('Fade'),
      'fadeZoom'    => t('Fade and Zoom'),
      'growX'       => t('Grow (Horizontal)'),
      'growY'       => t('Grow (Vertical)'),
      'scrollUp'    => t('Scroll (Up)'),
      'scrollDown'  => t('Scroll (Down)'),
      'scrollLeft'  => t('Scroll (Left)'),
      'scrollRight' => t('Scroll (Right)'),
      'scrollHorz'  => t('Scroll (Horizontal)'),
      'scrollVert'  => t('Scroll (Vertical)'),
      'shuffle'     => t('Shuffle'),
      'slideX'      => t('Slide (Horizontal)'),
      'slideY'      => t('Slide (Vertical)'),
      'toss'        => t('Toss'),
      'turnUp'      => t('Turn (Up)'),
      'turnDown'    => t('Turn (Down)'),
      'turnLeft'    => t('Turn (Left)'),
      'turnRight'   => t('Turn (Right)'),
      'uncover'     => t('Uncover'),
      'wipe'        => t('Wipe'),
      'zoom'        => t('Zoom'),
    );

    $events = array('click' => t('On Click'), 'mouseover' => t('On Mouseover'));

    // Get a list of all available stylesheet plugins.
    $skin_info = views_cycle_get_skins();
    foreach ($skin_info as $skin => $info) {
      $skins[$skin] = $info['title'];
    }
    asort($skins);

    // Relabel the description field of the list type option to be more descriptive
    // for this plugin.
    $form['type']['#description'] = t('Whether to use an ordered or unordered list for the retrieved cycle items. Most use cases will prefer Unordered.');


    // And now our own form additions.
    $form['skin'] = array(
      '#type' => 'select',
      '#title' => t('Skin'),
      '#options' => $skins,
      '#default_value' => $this->options['skin'],
      '#description' => t('Select the skin to use for this display.  Skins allow for easily swappable layouts of things like next/prev links and thumbnails.  Note that not all skins support thumbnails, so mis-matching skins and thumbnails may lead to unpredictable results.'),
    );

    $form['thumbnail_field'] = array(
      '#type' => 'select',
      '#title' => t('Thumbnail field'),
      '#options' => $fields,
      '#default_value' => $this->options['thumbnail_field'],
      '#description' => t('Select the field that will be used as the thumbnail field, if one is required.'),
    );

    $form['height'] = array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#default_value' => $this->options['height'],
      '#description' => t('Enter the height for the views cycle block. To have the cycler adjust to the height of the largest picture, please enter 0.'),
    );

    $form['verticalPadding'] = array(
      '#type' => 'textfield',
      '#title' => t('Vertical Padding'),
      '#default_value' => $this->options['verticalPadding'],
      '#description' => t('Enter the the vertical padding in pixels to increase the height of the container beyond the size of the images.'),
    );

    $form['pager'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Pager settings'),
      '#description' => t('The following configuration settings control how the cycle plugin will behave.'),
    );

    $form['pager']['event'] = array(
      '#type' => 'select',
      '#title' => t('Transition event'),
      '#options' => $events,
      '#default_value' => $this->options['pager']['event'],
      '#description' => t('Determines what sort of user input will result in a cycle transition.'),
      '#tree' => TRUE,
    );

    $form['params'] = array(
      '#type' => 'fieldset',
      '#title' => t('Transition effects configuration'),
      '#description' => t('The following settings govern how cycle transitions will occur.'),
      '#tree' => TRUE,
    );

    $form['params']['fx'] = array(
      '#type' => 'select',
      '#title' => t('Transition effect'),
      '#options' => $transitions,
      '#default_value' => $this->options['params']['fx'],
      '#description' => t('Select the transition effect you wish to use. If 0 is selected as the timeout below, this value has no effect.'),
      '#required' => TRUE,
    );

    $form['params']['timeout'] = array(
      '#type' => 'textfield',
      '#title' => t('Timeout (ms)'),
      '#default_value' => $this->options['params']['timeout'],
      '#description' => t('The time in milliseconds before the cycle auto-advances. Set to 0 to disable auto-advance.'),
      '#required' => TRUE,
    );

    $form['params']['speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed (ms)'),
      '#default_value' => $this->options['params']['speed'],
      '#description' => t('The time in milliseconds that each transition takes.'),
      '#required' => TRUE,
    );
  }

  function options_submit($form, &$form_state) {
    // In addition to the skin, we also pre-save the definition that
    // correspond to it.  That lets us avoid a hook lookup on every page.
    $skins = views_cycle_get_skins();
    $form_state['values']['style_options']['skin_info'] = $skins[$form_state['values']['style_options']['skin']];
  }
}

/**
 * Retrieve a list of all available skins in the system.
 */
function views_cycle_get_skins() {
  static $skins;

  if (empty($skins)) {
    $skins = array();
    foreach (module_implements('views_cycle_skins') as $module) {
      $skin_items = call_user_func($module .'_views_cycle_skins');
      if (isset($skin_items) && is_array($skin_items)) {
        foreach (array_keys($skin_items) as $skin) {
          // Ensure that the definition is complete, so we don't need lots
          // of error checking later.
          $skin_items[$skin] += array(
            'title' => t('Untitled skin'),
            'pager_location' => 'after',
            'module' => $module,
            'path' => '',
            'stylesheets' => array(),
          );
        }
        $skins = array_merge($skins, $skin_items);
      }
    }
  }

  return $skins;
}
