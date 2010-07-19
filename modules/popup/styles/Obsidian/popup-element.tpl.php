<div id="<?php print $id; ?>" class="<?php print $classes['element']; ?>">

<?php if ($title) {?>
  <div class="<?php print $classes['title-container']; ?>"><a<?php print $href; ?> id="<?php print $id; ?>-title" class="<?php print $classes['title']; ?>"><span class="wrapper"><?php print $title; ?></span></a></div>
<?php } ?>

<?php if ($body) {
  print $body['prefix']; ?>

    <div id="<?php print $id; ?>-body" class="<?php print $classes['body']; ?>">

      <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-tl">
        <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-tr">
          <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-t"></div>
        </div>
      </div>

      <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-l">
        <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-r">
          <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-inner">
            <?php print $body['content']; ?>
          </div>
        </div>
      </div>

      <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-bl">
        <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-br">
          <div class="<?php print $classes['body-wrapper']; ?> popup-body-edge popup-body-b"></div>
        </div>
      </div>

    </div>

  <?php 
  print $body['suffix'];
}
?>

</div>