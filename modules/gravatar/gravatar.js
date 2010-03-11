// $Id: gravatar.js,v 1.1.2.2 2008/11/17 03:39:20 davereid Exp $

Drupal.behaviors.gravatarPreview = function (context) {
  $('input[name=gravatar_default]:not(.gravatarPreview-processed)', context).addClass('gravatarPreview-processed').click(function () {
    var selected_image = $('img#gravatar-imagepreview-' + this.value);
    $('img#gravatar-imagepreview').attr('src', selected_image.attr('src'));
  });
  $(document).ready(function () {
    var selected_index = $('input[name=gravatar_default][checked]').val();
    var selected_image = $('img#gravatar-imagepreview-' + selected_index);
    $('img#gravatar-imagepreview').attr('src', selected_image.attr('src'));
    //$('.js-show').show();
  });
};
