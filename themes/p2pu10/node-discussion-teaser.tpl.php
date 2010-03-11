<div id="node-<?php print $node->nid; ?>" class="node node-teaser<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $node->type; ?> node-<?php print $node->type; ?>-teaser clear-block">

  <div class="meta">
<?php if ($page == 0): ?>
    <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title ?>">Discussion: <?php print $title; ?></a></h2>
<?php endif; ?>
    <span class="created-date"><?php print $date; ?></span>
  </div>

  <div class="content">
    <?php print $content; ?>
  </div>

</div>