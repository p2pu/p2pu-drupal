<div id="<?php print $id; ?>" class="<?php print $classes['element']; ?>">

<?php if ($title) {?>
  <div class="<?php print $classes['title-container']; ?>"><a<?php print $href; ?> id="<?php print $id; ?>-title" class="<?php print $classes['title']; ?>"><?php print $title; ?></a></div>
<?php } ?>

<?php if ($body) {
  print $body['prefix']; ?>
    <div id="<?php print $id; ?>-body" class="<?php print $classes['body']; ?>"><?php print $body['content']; ?></div>
<?php 
  print $body['suffix'];
}
?>

</div>