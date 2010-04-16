<?php
// $Id: views-view-field.tpl.php,v 1.1 2008/05/16 22:22:32 merlinofchaos Exp $
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_alias}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */
 // We want to changed the text that appears in views when displaying course status
 // from 'Closed' to 'Running'
 // This is set in og/modules/og_views/includes/og_views_handler_field_og_subscribe
 // Can override using translation UI - this is already done for the "Join" text
 // is set here: admin/build/translate/edit/2482
 // For Closed: http://local.p2pu.org/admin/build/translate/edit/4838
 // A request was made for the "Click here" text to be bold. This is done here,
 // but it's not elegant, and won't work if there's a translation.
?>
<?php if (stristr($output, 'Click here.')):?>
	<?php $output = str_replace('Click here.', '<strong>Click here.</strong>', $output);?>
<?php endif;?>
<?php print $output; ?>