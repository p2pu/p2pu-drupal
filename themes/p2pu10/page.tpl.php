<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">

<head>
<title><?php print $head_title; ?></title>
<?php print $head; ?>
<?php print $styles; ?>
<?php print $scripts; ?>
</head>

<body<?php print $body_class; ?>>

  <div id="page">

      <div id="page-header" class="float-container">

        <div id="logo"><?php print $logo; ?></div>
        <div id="slogan"><?php print $site_slogan; ?></div>
        <div id="region-header"><?php print $header; ?></div>

        <?php print $breadcrumb; ?>
      </div><!-- /page-header -->

      <div id="navigation">
        <?php if ($primary_navigation){ $primary_navigation = str_replace('/http://','http://',$primary_navigation); ?><div class="primary"><?php print $primary_navigation; ?></div><?php } ?>
        <?php print $search_box; ?>
      </div><!-- /Navigation -->

      <div id="page-sub-header"><?php print $sub_header; ?></div>

      <div class="page-body-back">
      <div class="page-body-bottom">
      <div id="page-body" class="float-container page-body-top">
        <div id="page-sub-body">
  
          <div id="content-column">
            <div class="inner">
              <?php print $title; ?>
              <?php if ($content_top): ?><div id="content-top"><?php print $content_top; ?></div><?php endif; ?>
              <?php if ($mission): ?><div id="mission"><?php print $mission; ?></div><?php endif; ?>
              <?php print $messages; ?>
              <?php if ($tabs): ?><div class="tabs float-container"><?php print $tabs; ?></div><?php endif; ?>
              <?php print $help; ?>
              <?php print $content; ?>
              <?php print $feed_icons; ?>
              <?php if ($content_bottom): ?><div id="contentBottom"><?php print $content_bottom; ?></div><?php endif; ?>
            </div>
          </div><!-- /content-column -->
  
          <?php if ($left): ?>
            <div id="sidebar-left" class="sidebar">
              <div class="inner">
                <?php print $left; ?>
              </div>
            </div><!-- /left-column -->
            <?php endif; ?>
        </div>
        
        <?php if ($right): ?>
          <div id="sidebar-right" class="sidebar">
            <div class="inner">
              <?php print $right; ?>
            </div>
          </div><!-- /right-column -->
        <?php endif; ?>
          
      </div><!-- /page-body -->
      </div>
      </div>
  
      <?php if ($footer || $footer_message): ?>
        <div id="page-footer">
          <div class="inner">
            <div class="message">
              <?php print $footer_message; ?>
            </div>
            <?php print $footer; ?>
          </div>
        </div>
      <?php endif; ?>

  </div><!-- /page -->
  
  <?php print $closure; ?>

</body>
</html>
