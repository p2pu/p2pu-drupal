$(document).bind('flagGlobalAfterLinkUpdate', function(event, data) {
  //alert('Object #' + data.contentId + ' (of type ' +
  //  data.contentType + ') has been ' + data.flagStatus +
  //  ' using flag "' + data.flagName + '"');

  var base_url = (Drupal.settings && Drupal.settings.basePath) ||  '/';

  function refreshFlaggedByIndication(flagName, contentType, contentId) {
    // There may be more than one flag on a page so we use the nid or cid
    // For nodes it's using the css ID, comments, the class
    if (contentType == 'node') {
      var prefix = '#';
    }
    if (contentType == 'comment') {
      var prefix = '.';
    }
    var contentIdentifier = prefix + contentType + '-' + contentId;
  
    $.get(base_url + '?q=p2pu_flag/get/' + flagName + '/' + contentId, null, function(updatedIndication) {
      var result = Drupal.parseJson(updatedIndication);
      // We get passed an array here by the callback function in p2pu.module
      // Just using the one value for now, but may be useful to have other data at a later point
      
      // Replace the old flagged by text with the updated text
       var domElement = $(contentIdentifier + " .flagged-by-indication").html(result.flagIndicationText); 
      Drupal.attachBehaviors(domElement);
    });
  } 
  
  if (data.flagName == 'like_node' || data.flagName == 'like_comment') {
    refreshFlaggedByIndication(data.flagName, data.contentType, data.contentId);
  }  

});