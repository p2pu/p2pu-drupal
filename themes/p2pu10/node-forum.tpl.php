<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $node->type; ?> clear-block">

<?php if ($page == 0): ?>
  <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
<?php endif; ?>

<?php if ($submitted): ?>
  <div class="meta">
  <?php if ($submitted): ?>
    <?php $submitted = str_replace("Submitted by",$picture, $submitted);?>
    <span class="submitted"><?php print $submitted ?></span>
  <?php endif;?>
  </div>
<?php endif; ?>

  <div class="content">
    <!-- Removed the terms - just display the link to the forum -->
    <span class="terms"><?php print $back_to_forum_link;?></span>

    <?php print $content ?>
  </div>
  <div class="node-flags">
    <?php print flag_create_link('like_node', $node->nid); ?>
    <span class="flagged-by-indication"><?php echo p2pu_get_item_flag_indication('like_node', $node->nid); ?></span>
  </div>
<?php
  if ($links) {
    print $links;
  }
?>

</div>


</div>

