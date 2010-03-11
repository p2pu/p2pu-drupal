<div class="search-result <?php print $search_zebra; ?>">
  <dt class="title">
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </dt>
  <dd>
    <?php if ($snippet) : ?>
    <p class="search-snippet"><?php print $snippet; ?></p>
    <?php endif; ?>
    
    <?php if ($info_split) : ?>
    <p class="search-info">
      <?php $info_separator = ''; ?>
      
      <?php if (isset($info_split['type'])) : ?>
      <span class="search-info-type"><?php print $info_split['type']; ?></span>
        <?php $info_separator = ' - '; ?>
      <?php endif; ?>
        
      <?php if (isset($info_split['user'])) : ?>
      <span class="search-info-user"><?php print $info_separator . $info_split['user']; ?></span>
        <?php $info_separator = ' - '; ?>
      <?php endif; ?>
        
      <?php if (isset($info_split['date'])) : ?>
      <span class="search-info-date"><?php print $info_separator . $info_split['date']; ?></span>
        <?php $info_separator = ' - '; ?>
      <?php endif; ?>
        
      <?php if (isset($info_split['comment'])) : ?>
      <span class="search-info-comment"><?php print $info_separator . $info_split['comment']; ?></span>
        <?php $info_separator = ' - '; ?>
      <?php endif; ?>
      
      <?php if (isset($info_split['upload'])) : ?>
      <span class="search-info-upload"><?php print $info_separator . $info_split['upload']; ?></span>
      <?php endif; ?>
    </p>
    <?php endif; ?>
  </dd>
</div>
