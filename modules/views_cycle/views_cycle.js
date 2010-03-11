// $Id: views_cycle.js,v 1.2.2.14 2010/01/13 20:20:42 crell Exp $

Drupal.behaviors.viewsCycle = function(context) {

  var settings = Drupal.settings.views_cycle;

  $('.views-cycle-container:not(.viewsCycle-processed)', context).addClass('viewsCycle-processed').each(function () {

    var cycler = $(this);
    var id = cycler.attr('id');
    var config = settings[id];
    var tallest = 0;
    var verticalPadding = parseInt(config.verticalPadding) || 0;
    var usingPager = false;
    
    // Correct this value, because of Javascript's brain-dead type handling.
    config.params.height = parseInt(config.params.height);

    // If we have a pager of some kind, create our pager placeholder.
    if (config.params.pager && config.params.pagerLocation) {
      var usingPager = true;
    }

    if (usingPager) {
      var pagerId = id + '-nav';
      if (config.params.pagerLocation == "after") {
        cycler.after('<ul class="view-cycle-pager" id="' + pagerId + '">');
      }
      else if (config.params.pagerLocation == "before") {
        cycler.before('<ul class="view-cycle-pager" id="' + pagerId + '">');
      }

      // If we're triggering the pager on mouseover, disable the transitions
      // while hovering so that the slide doesn't change out from under us.
      if (config.params.pagerEvent == 'mouseover') {
        config.params.pauseOnPagerHover = true;
      }
    }

    // Find the tallest item and set the height to that item's height + padding,
    // unless we already have an explicit maximum height set.
    if (config.params.height) {
      config.params.height = config.params.height + verticalPadding;
    }
    else {
      cycler.children('li').each(function () {
        var li = $(this);
        if (li.height() > tallest) {
          tallest = li.height();
        }
      });
      config.params.height = tallest + verticalPadding;
    }

    // If thumbnails are used, this will always be how they're created.
    // Finds the thumbnail by the hidden div & id #.
    function makeAnchors(idx, slide) {
      // Get the cycle container and use it's id to select thumbs
      parent_selector = "#" + $(slide).parent().attr('id') + "-thumb-data";

      thumb_item = $(parent_selector).children().eq(idx);
      // Grab the thumbnail item's content and class names.
      return Drupal.theme('viewsCycle', thumb_item.html(), thumb_item.attr('class'), idx);
    }

    // We will need our own custom callback for updating the pager, as 
    // our pager is potentially complex HTML.
    function updateActivePager(pager, currSlideIndex) {
      $(pager)
        .find('li').removeClass('activeSlide')
        .filter('li:eq(' + currSlideIndex + ')').addClass('activeSlide');
    }

    // We can't set the function from PHP because we can't specify a datatype of
    // "function" from PHP.  So we simply flag it to use the function above.
    if (config.use_pager_callback) {
      config.params.pagerAnchorBuilder = makeAnchors;

      // Because our cycle may use a complex thumbnail, we need to use our own 
      // custom page-changer callback.  Note that this is a global callback
      // for all cycles on the page.  Fortunately, the same one should apply
      // to any cycle so we're OK.
      $.fn.cycle.updateActivePagerLink = updateActivePager;
    }

    // Fire away!
    cycler.cycle(config.params);

    // jquery.cycle breaks links within the pager.  I'm not entirely sure how,
    // but the event itself never fires.  However, we can then re-attach our 
    // own event to simulate the link being clicked.  It's weird, but it works.
     if (usingPager && config.params.pagerEvent == 'mouseover') {
      $("#" + pagerId + ' a').click(function() {
        window.location = this.href;
      });
    }
  });
};

Drupal.theme.prototype.viewsCycle = function(body, classes, id) {
  return '<li class="' + classes + '">' + body + "</li>\n";
}
