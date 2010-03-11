// $Id: og_forum.js,v 1.1.2.1 2008/07/22 14:33:56 paulbooker Exp $

Drupal.ogAttach = function() {
/*  Disable the public checkbox if no groups are selected in in Audience, unless audience is required and set in hidden field*/
  
  var hidden_set;
  if ( $('.og-audience-forum').size() > 0) {
    hidden_set = $('input.og-audience-forum').val();
  }
  if (hidden_set) {
    $('#edit-og-public').removeAttr("disabled");
  }
  else {
    $('#edit-og-public').attr("disabled", "disabled");
  }
}

if (Drupal.jsEnabled) {
  $(document).ready(Drupal.ogAttach);
}