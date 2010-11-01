<?php
  $course_nid = array_pop( $node->og_groups );

  $uid = $node->uid;
  $token = og_get_token($course_nid);
  $item = menu_get_item("og/approve/$nid/$uid/$token");
  $new_link = t('Request: <a href="@approve">approve</a> or <a href="@deny">deny</a>.', array('@approve' => url("og/approve/$course_nid/$uid/$token", array('query' => "destination=node/$course_nid/course/admin")), '@deny' => url("og/deny/$course_nid/$uid/$token", array('query' => "destination=node/$course_nid/course/admin"))));
?>

<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $node->type; ?> clear-block">

<?php if ($page == 0): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a></h2>
<?php endif; ?>

<div class="approve-deny">
  <?php print $new_link; ?>
</div>

  <div class="meta">
    <?php
    print theme('user_picture',user_load(array('uid'=>$node->uid)));
    ?>
    <span class="created-date"><?php print $date; ?></span>
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
