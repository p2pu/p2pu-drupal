Drupal.og_abt_attach = function() {  
  // Node authoring form for group content 
  // - Disable the public checkbox if no groups are selected in in Audience 
  // - Start by unbinding the click event bound in og.js so there's no conflict
  $('.og-audience').unbind('click');
  $('.form-checkboxes.og-audience input').change(function() {
    Drupal.og_abt_testSelectors();
  });
  $('.form-select.og-audience').change(function() {
    Drupal.og_abt_testSelectors();
  });
}

Drupal.og_abt_testSelectors = function() {
  var count = 0;
  count += $('.og-audience.form-checkbox:checked').size();
  $('.og-audience.form-select').each(function() {
    var val = $(this).val();
    if (val && val != '0') {
      count++;
    }
  });
  if (count) {
    $('#edit-og-public').removeAttr("disabled");
  }
  else {
    $('#edit-og-public').attr("disabled", "disabled");
  }
}

if (Drupal.jsEnabled) {
  $(document).ready(Drupal.og_abt_attach);
}