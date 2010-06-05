<?php //dprint_r(get_defined_vars());?>
<div class="<?php print $classes; ?> clear-block">
  
  <?php if ($title): ?>
    <h3 class="title">
      <?php print $title; ?>
      <?php if ($comment->new): ?>
        <span class="new"><?php print $new; ?></span>
      <?php endif; ?>
    </h3>
  <?php elseif ($comment->new): ?>
    <div class="new"><?php print $new; ?></div>
  <?php endif; ?>

  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>
  
  <div class="meta">
    <?php print $picture; ?>
    <span><?php print $submitted; ?></span>
  </div>

  <div class="content">
    <?php print $content; ?>
  </div>
  
  <div class="comment-flags">
    <?php print flag_create_link('like_comment', $comment->cid); ?>
    <span class="flagged-by-indication"><?php echo p2pu_get_item_flag_indication('like_comment', $comment->cid); ?></span>
  </div>
  
  <?php print $links; ?>
</div>