<!-- node UC --> 
<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">

  <?php if ($page == 0): ?>
  <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  <?php endif; ?>

  <div class="images">
    <?php print $uc_image; ?>
  </div><!-- /images -->

  <div class="content">
    <?php if ($uc_additional && !$teaser): ?>
    <div id="product-additional" class="product-additional">
      <?php print $uc_additional; ?>
    </div>
    <?php endif; ?>

    <div id="content-body">
      <?php print $uc_body; ?>
    </div>

    <div id="product-details">
      <div id="field-group">
        <?php print $uc_weight; ?>
        <?php print $uc_dimensions; ?>
        <?php print $uc_model; ?>
        <?php print $uc_list_price; ?>
        <?php print $uc_sell_price; ?>
        <?php print $uc_cost; ?>
      </div>

      <div id="price-group">
        <?php print $uc_display_price; ?>
        <?php print $uc_add_to_cart; ?>
      </div>
    </div><!-- /product-details -->

    <?php if ($terms): ?>
    <div class="terms">
      <?php print $terms; ?>
    </div>
    <?php endif;?>

    <?php if ($links && !$teaser): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
    <?php endif; ?>
  </div><!-- /content -->

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom">
    <?php print $node_bottom; ?>
  </div>
  <?php endif; ?>
</div>
<!-- /node UC-<?php print $node->nid; ?> --> 