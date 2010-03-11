<?php
// $Id: stastspro_views_handler_field_graph_trend.inc,v 1.1 2009/01/01 18:38:15 mr3dblond Exp $

/**
 * @file
 *   Views field handler for graph
 *
 */

require 'stastspro_views_handler_field_graph.inc';

class stastspro_views_handler_field_graph_trend extends stastspro_views_handler_field_graph {

  var $_last_value = -1;

  /**
   * Table name for max. calculation
   *
   * @var string
   */
  var $base_table = 'statspro';

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['display_mode'] = array(
      '#type' => 'select',
      '#title' => t('Display mode'),
      '#default_value' => $this->value,
      '#options' => array('text' => t('String'), 'graph' => t('Graph'), 'trend' => t('Trend') ),
      '#description' => t('Define the display mode for presentation.'),
    );

    $form['graph_size'] = array(
      '#type' => 'textfield',
      '#title' => t('Graph size'),
      '#default_value' => $this->options['graph_size'],
      '#description' => t('Define the maximum width of the graph. The larges value/image will have this size. Only used with display mode <em>graph</em>'),
      '#size' => 10,
      '#field_suffix' => t('px'),
      );
  }

  function render($values) {

    $estimation = $values->{$this->field_alias};
    $rc = '-';

    switch ($this->options['display_mode']) {

      case 'graph':

        if ($estimation) {
          $rc = $this->get_bar_graph($values);
        }
        break;

      case 'trend':

        $mode = $this->_last_value;

        if ($estimation>=0) {
          $trend = $this->get_current_trend($values);
          if (!empty($trend)) {
            $rc = '<img src="'. base_path() . drupal_get_path('module', 'statspro') .'/images/trend_'. $trend .'.gif" alt="" />';
          }
        }

        if (empty($rc)) {

          if ($mode == -1) {
            if ($this->_last_value == -1) {
              $this->_last_value = 0;
            }
          }
          else {
            $rc = '<img src="'. base_path() . drupal_get_path('module', 'statspro') .'/images/trend_same.gif" alt="" />';
          }
        }
        break;

      default:
        if ($estimation) {
          if (!empty($this->options['set_precision'])) {
            $estimation = number_format($estimation, $this->options['precision'], $this->options['decimal'], $this->options['separator']);
          }
          $rc = check_plain($this->options['prefix']) . $estimation . check_plain($this->options['suffix']);
        }
        break;
    }

    return $rc;
  }

  function get_current_trend($values) {

    if ($this->_last_value == -1) { // first run
      $rc = '';
    }
    else if ($values->{$this->field_alias} > $this->_last_value) {
      $rc = 'up';
    }
    else if ($values->{$this->field_alias} == $this->_last_value) {
      $rc = 'same';
    }
    else {
      $rc = 'down';
    }

    // store current value
    $this->_last_value = $values->{$this->field_alias};

    return $rc;
  }
}
