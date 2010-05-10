<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $node->type; ?> clear-block">

<?php if ($page == 0): ?>
  <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
<?php endif; ?>

<?php if ($submitted || $terms): ?>
  <div class="meta">
<?php if ($submitted): ?>
<?php

//George: We want the forum post author information to match that of the comments author info
  $puser = user_load($node -> uid);

  $imagecache_id = variable_get('user_picture_imagecache_profiles_default', FALSE);

  if ($imagecache_id){
    $preset = imagecache_preset($imagecache_id);
    $picture = theme('imagecache', $preset['presetname'], $puser->picture);
  }

  $submitted = str_replace("Submitted by",$picture, $submitted);
?>
    <span class="submitted"><?php print $submitted ?></span>
<?php endif;?>
  </div>
<?php endif; ?>

  <div class="content">

<?php if ($terms): ?>
    <span class="terms"><?php print $terms ?></span>
<?php endif; ?>

    <?php print $content ?>
  </div>

<?php
  if ($links) {
    print $links;
  }
?>

</div>


</div>

