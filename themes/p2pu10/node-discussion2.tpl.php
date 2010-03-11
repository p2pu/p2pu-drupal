<div id="node-<?php print $node->nid; ?>" class="node <?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $node->type; ?> node-<?php print $node->type; ?>-teaser clear-block">

  <div class="meta">
    <?php print $picture; ?>
<?php if ($page == 0): ?>
    <h2 class="title">Discussion: <?php print $title; ?></h2>
<?php endif; ?>
    <span class="created-date"><?php print $date; ?></span>
    <span><?php print $name; ?></span>
  </div>

  <div class="content">
    <?php print $content; ?>
  </div>

</div>