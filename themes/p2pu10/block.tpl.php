<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">
<!-- wrappers -->

<?php if ($block->subject): ?>
  <?php print theme('block_title', $block->subject); ?>
<?php endif;?>

  <div class="content"><?php print $block->content ?></div>
  
<!-- /wrappers -->
</div>