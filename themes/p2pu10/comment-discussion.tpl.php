<div class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ($comment->status == COMMENT_NOT_PUBLISHED) ? ' comment-unpublished' : ''; ?> clear-block">
  
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

  <?php print $links; ?>
</div>