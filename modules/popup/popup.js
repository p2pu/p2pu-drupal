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
  this.origin = $($('.popup-origin', element)[0]);
  this.leaveTimeout = false;
  this.visible = false;
  this.parentId = this.element.attr('id');
  this.parentClass = this.element.attr('class');
  
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

  // Trigger immediate hiding of popup
  var handler = function(event){
    thisObject.hide();
  }
  this.element.unbind('hide', handler).bind('hide', handler);
  this.origin.unbind('hide', handler).bind('hide', handler);

  if (this.element.hasClass('popup-hover-activate-element')){
    this.hoverEvents();
  }

  if (this.element.hasClass('popup-click-activate-element')){
    this.clickEvents();
  }

  $('a.popup-close-button').click(
    function(){
      $($(this).parents('.popup-origin')[0]).trigger('hide');
      return false;
    }
  );
}




PopupObject.prototype.hoverEvents = function(){

  var thisObject = this;

  // Trigger showing of popup
  var showHandler = function(event){
    if (!thisObject.visible){
      thisObject.show();
      thisObject.leftOrigin = false;
      if (thisObject.element.hasClass('popup-menu-element')){
        thisObject.element.siblings('.popup-menu-element').trigger('hide');
      }
    }
  }
  this.title.unbind('mouseenter', showHandler).bind('mouseenter', showHandler);
  
  // Trigger delayed hiding of popup
  var hideHandler = function(event){
    if (thisObject.leaveTimeout){
      clearTimeout(thisObject.leaveTimeout);
    }
    thisObject.leaveTimeout = setTimeout(
      function(){
        thisObject.hide();
      }, Drupal.settings.popup.hoverLinger
    );
  }
  this.element.unbind('mouseleave', hideHandler).bind('mouseleave', hideHandler);
  if (this.origin.parents('.popup-origin').length == 0){
    this.origin.unbind('mouseleave', hideHandler).bind('mouseleave', hideHandler);
  }

  // Handle the cancellation of hiding
  var cancelHideHandler = function(){
    if (thisObject.leaveTimeout){
      clearTimeout(thisObject.leaveTimeout);
      thisObject.leaveTimeout = false;
    }
  }
  this.origin.unbind('cancelHide', cancelHideHandler).bind('cancelHide', cancelHideHandler);

  // Cancel hiding
  var handler = function(event){
    thisObject.origin.parents().andSelf().trigger('cancelHide');
  }
  this.element.unbind('mouseenter', handler).bind('mouseenter', handler);
  if (this.origin.parents('.popup-origin').length == 0){
    this.origin.unbind('mouseenter', handler).bind('mouseenter', handler);
  }
  
}



PopupObject.prototype.clickEvents = function(){

  var thisObject = this;
  
  var handler = function(event){
    if (thisObject.visible){
      thisObject.hide();
    } else {
      thisObject.show();
    }
  }
  this.title.unbind('click', handler).click(handler);

  if (this.body.hasClass('popup-close-button')){
    this.body.prepend('<a href="#" class="popup-close-button popup-generated-close-button"><span>[x]</span></a>');
  }
  
}


PopupObject.prototype.show = function(){

  var thisObject = this;
  var zIndex = (this.element.parents('.popup-element').length + 1) * 500;

  this.element.addClass('popped-up-element');
  this.body.css('z-index', zIndex).addClass('popped-up-body');
  this.title.addClass('popped-up-title');
  this.visible = true;

  if (this.element.parents('.popup-origin').length == 0){

    var offset = this.origin.offset();
    this.origin.appendTo('body').wrap('<div id="' + this.parentId + '-wrapper"/>');
    this.origin.css(
        {
          top: offset.top,
          left: offset.left,
          zIndex: zIndex
        }
    );
  }

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
    thisObject.element.removeClass('popped-up-element');
    thisObject.body.removeClass('popped-up-body');
    thisObject.visible = false;
    thisObject.origin.appendTo(thisObject.element);
    thisObject.origin.css(
      {
        top: '',
        left: '',
        zIndex: ''
      }
    );
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

  this.title.removeClass('popped-up-title');
  $('body').children('#' + this.parentId).remove();
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


