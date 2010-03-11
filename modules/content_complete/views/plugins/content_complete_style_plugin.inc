<?php
// $Id: content_complete_style_plugin.inc,v 1.1.2.1 2009/09/30 15:33:36 pvhee Exp $

/**
 * @file
 *Provide the views Complete Complete plugin.
 */

/**
  * Implementation of views_plugin_style().
  */
class content_complete_style_plugin extends views_plugin_style {
  function render($values) {
    // Make calculations here (always on the fly but using cached values to compute with...)
    $data = $this->compute_sum($values);
    return theme('content_complete_profile_percent_complete', $data);
  }
  
   /**
    * Style validation.
    */
   function validate() {
     $errors = parent::validate();
     
     if (empty($this->display->display_options['style_plugin'])) {
       return $errors;
     }
     
     // Make sure a completeness field is provided.
     $fields = $this->display->handler->get_option('fields');
     if (!isset($fields['completeness'])) {
       $errors[] = t("You need to provide a completeness field in the display '@display_title'.", array('@display_title' => $this->display->display_title));
     }
     
     return $errors;
   }
  
  /**
   * Compute the sum of a series of complete values.
   * TODO: include other values such as next field, path, ...
   * 
   * @return 
   *   An array of fields such as percentage complete (summed).
   */
  function compute_sum(&$rows) {
    $data['percent'] = 0;
    
    foreach ($rows as &$row) {
      $data['percent'] += $row->content_complete_completeness;
    }
    
    if (count($rows)) {
      $data['percent'] /= count($rows);
    }

    return $data;
  }
  
  
}