<?php

class p2pu_handler_field_activity extends views_handler_field {
  /**
   * Add the time_horizon option.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['time_horizon'] = array('default' => 30);
    return $options;
  }

  /**
   * Add the time_horizon element.
   */
  function options_form(&$form, $form_state) {
    parent::options_form($form, $form_state);
    $form['time_horizon'] = array(
      '#type' => 'select',
      '#title' => t('Time horizon'),
      '#description' => t('Show activity that goes back to the selected period. Choosing a shorter period will result in a more optimized view.'),
      '#options' => array(
        7 => t('@num days', array('@num' => 7)),
        14 => t('@num days', array('@num' => 14)),
        30 => t('@num days', array('@num' => 30)),
        90 => t('@num days', array('@num' => 90)),
      ),
      '#default_value' => $this->options['time_horizon'],
    );
  }

  /**
   * Constructor. Add additional fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = array('table' => 'node', 'field' => 'nid');
    $this->additional_fields['node_title'] = array('table' => 'node', 'field' => 'title');
    $this->additional_fields['node_uid'] = array('table' => 'node', 'field' => 'uid');
    $this->additional_fields['comment_uid'] = array('table' => 'comments', 'field' => 'uid');
    $this->additional_fields['node_changed'] = array('table' => 'node', 'field' => 'changed');
    $this->additional_fields['node_created'] = array('table' => 'node', 'field' => 'created');
  }

  /**
   * Query. This relies on the hijacking of the Views execution process in
   * p2pu_views_query_alter().
   */
  function query() {
    parent::query();
    if (!isset($this->view->p2pu_activity)) {
      $this->view->p2pu_activity = TRUE;
      $node = $this->query->ensure_table('node');
      $comments = $this->query->ensure_table('comments');
      $horizon = $this->options['time_horizon'] * 24 * 60 * 60;
      $this->query->add_orderby(NULL, "***P2PU_ACTIVITY_TIMESTAMP***", 'DESC', 'p2pu_activity_sort');
      $this->query->add_where(NULL, "***P2PU_ACTIVITY_TIMESTAMP*** > (***CURRENT_TIME*** - $horizon)");
    }
  }

  /**
   * Don't allow advanced render of this field.
   */
  function allow_advanced_render() { return FALSE; }

  /**
   * Render this field as a link to group space.
   */
  function render($value) {
    // Has comments
    if (!empty($value->{$this->field_alias})) {
      $account = user_load($value->{$this->aliases['comment_uid']});
      $tokens = array(
        '!user' => theme('username', $account),
        '!title' => l($value->{$this->aliases['node_title']}, "node/{$value->{$this->aliases['nid']}}", array('fragment' => "comment-{$value->{$this->field_alias}}")),
      );
      $user_picture = theme('user_picture', $account);
      return $user_picture . ' ' . t('!user commented on !title', $tokens);
    }
    // No comments
    $account = user_load($value->{$this->aliases['node_uid']});
    $user_picture = theme('user_picture', $account);   
    $tokens = array(
      '!user' => theme('username', $account),
      '!title' => l($value->{$this->aliases['node_title']}, "node/{$value->{$this->aliases['nid']}}"),
    );
    if ($value->{$this->aliases['node_changed']} > $value->{$this->aliases['node_created']}) {
      return $user_picture . ' ' . t('!user updated !title', $tokens);
    }
    return $user_picture . ' ' . t('!user posted !title', $tokens);
  }
}
