<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $node->type; ?> clear-block">

<?php if ($page == 0): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a></h2>
<?php endif; ?>
  <?php print $back_to_course_link; ?>
  <div class="meta">
    <?php
    print theme('user_picture',user_load(array('uid'=>$node->uid)));
    ?>
    <?php if ($p2pu_forum_time): ?>
      <span><?php print t(
      'Submitted by !author @time ago on @date', array(
        '@time' => $p2pu_forum_time,
        '!author' => $p2pu_forum_author,
        '@date' => $date,
        )); ?></span>
        
    <?php endif; ?>
    
  </div>

  <div class="content">
    <?php print $content; ?>
  </div>
  
<?php if ($terms){ ?>
  <span class="terms"><?php print $terms; ?></span>
<?php } ?>

<?php
  if ($links) {
    print $links;
  }
?>

</div>
