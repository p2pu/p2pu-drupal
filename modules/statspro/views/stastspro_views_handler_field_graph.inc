<?php
// $Id: stastspro_views_handler_field_graph.inc,v 1.2 2009/01/01 18:38:15 mr3dblond Exp $

/**
 * @file
 *   Views field handler for graph
 *
 */

class stastspro_views_handler_field_graph extends views_handler_field_numeric {

  var $_max_graph_value = 0;

  /**
   * Table name for max. calculation
   *
   * @var string
   */
  var $base_table = 'statspro_term';

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['display_mode'] = array(
      '#type' => 'select',
      '#title' => t('Display mode'),
      '#default_value' => $this->value,
      '#options' => array('text' => t('String'), 'graph' => t('Graph') ),
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

      default:
        if ($estimation) {
          $rc = $estimation;
        }
        break;
    }

    return $rc;
  }

  /**
   * Get HTML code for bar graph
   *
   * @param   object  $values
   * @return  string
   */
  function get_bar_graph($values) {

    $rc  = '<div style="width: '. intval($this->options['graph_size']) .'px">';
    $rc .= '<img src="'. base_path() . drupal_get_path('module', 'statspro') .'/images/bar_l.gif" height="10" alt="" />';
    $rc .= '<img src="'. base_path() . drupal_get_path('module', 'statspro') .'/images/bar.gif" width="'. $this->get_current_graph_size($values) .'" height="10" alt="graph image" title="value '. $estimation .'" />';
    $rc .= '<img src="'. base_path() . drupal_get_path('module', 'statspro') .'/images/bar_r.gif" height="10" alt="" />';
    $rc .= '</div>';

    return $rc;
  }

  function get_max_graph_value() {

    $view_sql   = $this->view->build_info['count_query'];
    $view_args  = $this->view->build_info['query_args'];
    $pos        = strpos($view_sql, ' FROM ');
    $max_query  = 'SELECT MAX('. $this->base_table .'.'. $this->field .') FROM '. drupal_substr($view_sql, $pos + 6);

    return db_result(db_query($max_query, $view_args));
  }

  function get_current_graph_size($values) {

    if (!$this->_max_graph_value) {
      $this->_max_graph_value = $this->get_max_graph_value();
    }

    if (empty($this->options['graph_size'])) {
      $this->options['graph_size'] = 50;
    }

    return $values->{$this->field_alias} * ((intval($this->options['graph_size']) - 6) / $this->_max_graph_value);
  }
}
