// $Id:



/* ---- Initialise all popups on load ---- */



$(
  function(){
    $('.popup-element').popup();
  }
);



/* ---- Popup object ---- */



function PopupObject(element){

  this.element = element;
  this.title = element.children('.popup-title-container').children('.popup-title');
  this.body = $($('.popup-body', element)[0]);
  this.leaveTimeout = false;
  this.visible = false;

  if (this.body.length){
    var opacity = this.body.attr('class').match(/popup-opacity-([0-9]*\.?[0-9]*)/);
    this.opacity = opacity == null
      ? false
      : opacity[1];
  }

  if (!this.element.hasClass('popup-menu-flat-element')){
    this.initEvents();
  }
}



PopupObject.prototype.initEvents = function(){

  var thisObject = this;

  if (this.element.hasClass('popup-hover-activate-element')){

    // Trigger showing of popup
    var handler = function(event){
      if (!thisObject.visible){
        thisObject.show();
      }
    }
    this.title.unbind('mouseenter', handler).bind('mouseenter', handler);

    // Trigger hiding of popup
    var handler = function(event){
      thisObject.leaveTimeout = setTimeout(
        function(){
          thisObject.hide();
        }, Drupal.settings.popup.hoverLinger
      );

    }
    this.element.unbind('mouseleave', handler).bind('mouseleave', handler);

    // Handle the cancellation of hiding
    var handler = function(){
      if (thisObject.leaveTimeout){
        clearTimeout(thisObject.leaveTimeout);
        thisObject.leaveTimeout = false;
      }
    }
    this.element.unbind('cancelHide', handler).bind('cancelHide', handler);

    // Cancel hiding
    var handler = function(event){
      thisObject.element.parents().andSelf().trigger('cancelHide');
    }
    this.element.unbind('mouseenter', handler).bind('mouseenter', handler);

  }

  if (this.element.hasClass('popup-click-activate-element')){

    var handler = function(event){
      if (thisObject.visible){
        thisObject.hide();
      } else {
        thisObject.show();
      }
    }
    this.title.unbind('click', handler).click(handler);

    if (this.body.hasClass('popup-close-button')){
      this.body.prepend('<a href="#" class="popup-close-button"><span>[x]</span></a>');
      this.body.children('a.popup-close-button').click(
        function(){
          thisObject.hide();
        }
      );
    }
  }
}



PopupObject.prototype.show = function(){

  var thisObject = this;
  var zIndex = (this.element.parents('.popup-element').length + 1) * 500;

  thisObject.element.css('position', 'relative').addClass('popped-up-element');
  thisObject.body.css('z-index', zIndex).addClass('popped-up-body');
  thisObject.title.addClass('popped-up-title');
  thisObject.visible = true;

  switch(true){

    case this.body.hasClass('popup-slide-effect'): 
      this.body.slideDown("medium");
    break;

    case this.body.hasClass('popup-fade-effect'):
      if (this.opacity){
        this.body.fadeTo("medium", this.opacity);
      } else {
        this.body.fadeIn("medium");
      }
    break;

    case this.body.hasClass('popup-slide-fade-effect'): 
      this.body.animate(
        {
          height: 'show',
          opacity: (this.opacity ? this.opacity : 'show')
        }, 'medium'
      );
    break;

    default:
      if (this.opacity){
        this.body.css('opacity', this.opacity);
      }
      this.body.show();
  }

}



PopupObject.prototype.hide = function(){

  var thisObject = this;

  var restoreState = function(){
    thisObject.element.css('position', 'static').removeClass('popped-up-element');
    thisObject.body.css('z-index', '').removeClass('popped-up-body');
    thisObject.title.removeClass('popped-up-title');
    thisObject.visible = false;
  }

  switch(true){

    case this.body.hasClass('popup-slide-effect'): this.body.slideUp('medium', restoreState); break;

    case this.body.hasClass('popup-fade-effect'): this.body.fadeOut('medium', restoreState); break;

    case this.body.hasClass('popup-slide-fade-effect'):
      this.body.animate(
        {
          height: 'hide',
          opacity: 'hide'
        }, 'medium', 
        restoreState
      ); 
      break;

    default: 
      this.body.hide();
      restoreState();
  }

}



/* ---- JQuery interface ---- */



jQuery.fn.popup = function(){
  return this.each(
    function(){
      var thisObject = $(this);
      if (!thisObject.popupObject){
        thisObject.popupObject = new PopupObject($(this));
      }
    }
  );
}


