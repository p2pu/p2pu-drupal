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
 
 /* We want to change the 'label' associated with each content type for this view
   so that when it's a 'submission' the text is 'submitted an assignment etc:
		created a new document
		created a new discussion topic
		submitted an assignment
		
 */
 $type_string = '';
 $created_text = t('created a new');
  switch($row->node_type) {
		case 'discussion':
			$node_type_string = t('discussion topic');
			break;
		case 'document':
			$node_type_string = t('document');
			break;	
		case 'submission':
			$node_type_string = t('assignment');
			$created_text = t('submitted an');
			break;
		default:
			$node_type_string = $output;
			break;
	}
	$type_string = $created_text . ' <strong>' . $node_type_string . '</strong>';
?>

<?php print strtolower($type_string); ?>: 