


Drupal.behaviors.popupFilter = function(){

  // Show/Hide appropriate sections based on type

  $('a.popup-filter-admin-form-title').click(
    function(){
      $('#edit-body').focus();
    }
  );  

  // Show/Hide appropriate sections based on type

  $('#edit-popup-type')
    .change(updateSections)
    .keyup(updateSections)
    .click(updateSections);

  function updateSections(){
    $('.popup-content-' + $('#edit-popup-type').val())
      .slideDown()
      .siblings('.popup-content-section')
        .slideUp();
  }
  updateSections();


  // Node title autocomplete

  $('#edit-popup-content-node-title')
    .change(setNodeId)
    .keyup(setNodeId);

  function setNodeId(){
    var matches = $('#edit-popup-content-node-title').val().match(/\[([0-9]+)\]/);
    if (matches){
      $('#edit-popup-content-node-id').val(matches[1]);
    }
  }


  // Block delta selection box
 
  $('#edit-popup-content-block-module')
    .change(loadBlockDelta)
    .keyup(loadBlockDelta)
    .click(loadBlockDelta);

  function loadBlockDelta(){
    $.get(
      '/ajax/popup-filter/getdeltas/' + $('#edit-popup-content-block-module').val(), 
      null, 
      function(data) { 
        $('#edit-popup-content-block-delta').html(data);
      }
    );
  } 
  loadBlockDelta();

  
  // View display selection box
  
  $('#edit-popup-content-view')
    .change(loadViewDisplay)
    .keyup(loadViewDisplay)
    .click(loadViewDisplay);

  function loadViewDisplay(){
    $.get(
      '/ajax/popup-filter/getdisplays/' + $('#edit-popup-content-view').val(), 
      null, 
      function(data) { 
        $('#edit-popup-content-view-display').html(data); 
      }
    );
  } 
  loadViewDisplay();

  
  // Insert popup tag

  $('div.popup-insert input')
    .click(insert);

  function insert(){

    var title = $('#edit-popup-title').val();
    var id = $('#edit-popup-id').val();
    var popupClass = $('#edit-popup-class').val();
    var link = $('#edit-popup-link').val();
    var type = $('#edit-popup-type').val();
    var effect = $('#edit-popup-effect').val();

    var rendered =
      '[popup ' +
        (title != '' ? 'title=' + title + ' ' : '') +
        (id != '' ? 'id=' + id + ' ' : '') +
        (popupClass != '' ? 'class=' + popupClass + ' ' : '') +
        (link != '' ? 'link=' + link + ' ' : '') +
        'origin=' + $('#edit-popup-origin').val() + ' ' +
        'expand=' + $('#edit-popup-expand').val() + ' ' +
        'activate=' + $('#edit-popup-activate').val() + ' ' +
        (effect != '0' ? 'effect=' + effect + ' ' : '') +
        type;

    switch(type){

      case 'text':
        var text = $('#edit-popup-content-text-text').val();
        if (text.match(/\s/)){
          if (text.match(/'/)){
            rendered += '="' + text + '"';
          } else {
            rendered += "='" + text + "'";
          }
        } else {
          rendered += '=' + text;
        }
      break;

      case 'node':
        rendered += '=' + $('#edit-popup-content-node-id').val();
        var teaser = $('#edit-popup-content-node-options-teaser').attr('checked');
        rendered += teaser ? ' teaser' : '';
        var page = $('#edit-popup-content-node-options-page').attr('checked');
        rendered += page ? ' page' : '';
        var links = $('#edit-popup-content-node-options-links').attr('checked');
        rendered += links ? ' links' : '';
      break;
      
      case 'block':
        rendered += 
          ' module=' + $('#edit-popup-content-block-module').val() +
          ' delta=' + $('#edit-popup-content-block-delta').val();
      break;
      
      case 'form':
        rendered += '=' + $('#edit-popup-content-form-id').val();
      break;
      
      case 'menu':
        rendered += '=' + $('#edit-popup-content-menu').val();
        var flat = $('#edit-popup-content-menu-flat').attr('checked');
        rendered += flat ? ' flat' : '';
      break;

      case 'view':
        rendered += '=' + $('#edit-popup-content-view').val();
        rendered += ' display=' + $('#edit-popup-content-view-display').val();
        var args = $('#edit-popup-content-view-args').val();
        if (args != ''){
          if (args.match(/\s/)){
            if (args.match(/'/)){
              rendered += ' args="' + args + '"';
            } else {
              rendered += " args='" + args + "'";
            }
          } else {
            rendered += ' args=' + args;
          }
        }
      break;

      case 'php':
        var php = $('#edit-popup-content-php-php').val();
        if (php.match(/\s/)){
          if (php.match(/'/)){
            rendered += '="' + php + '"';
          } else {
            rendered += "='" + php + "'";
          }
        } else {
          rendered += '=' + php;
        }
      break;

    }

    rendered += ']';
    var textField = $('#edit-body');
    textField.insertAtCaret(rendered);
    
  }

  $('form').submit(function(){ $('div.popup-filter-admin-form').remove();});
}



// By Alex King, adapted to jquery by Alex Brem http://www.mail-archive.com/jquery-en@googlegroups.com/msg08708.html
$.fn.insertAtCaret = function (myValue) {

  return this.each(function(){
    //IE support
    if (document.selection) {
      this.focus();
      sel = document.selection.createRange();
      sel.text = myValue;
      this.focus();
    }
    //MOZILLA/NETSCAPE support
    else if (this.selectionStart || this.selectionStart == '0') {
      var startPos = this.selectionStart;
      var endPos = this.selectionEnd;
      var scrollTop = this.scrollTop;
      this.value = this.value.substring(0, startPos) + myValue + this.value.substring(endPos, this.value.length);
      this.focus();
      this.selectionStart = startPos + myValue.length;
      this.selectionEnd = startPos + myValue.length;
      this.scrollTop = scrollTop;
    } else {
      this.value += myValue;
      this.focus();
    }
  });

};


