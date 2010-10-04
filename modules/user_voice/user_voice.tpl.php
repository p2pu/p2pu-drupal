<?php
// $Id: user_voice.tpl.php,v 1.1 2009/09/15 17:22:31 eastabrook Exp $

/**
 * @file
 * Default theme implementation of the user voice javascript
 *
 * Available variables:
 * - $key: User Voice key.
 * - $host: User Voice host.
 * - $forum: The forum User Voice is pointed to.
 * - $alignment: Alignment of the tab button: 'right' 'left'.
 * - $background_color: Background colour of the tab. CSS ready.
 * - $text_color: Text colour on the word Feedback: 'white' 'black'.
 * - $hover_color: The hover colour of the tab. CSS ready.
 * - $lang: The language of User Voice: 'en' 'de' 'nl' 'es' 'fr'.
 *
 * @see template_preprocess_user_voice()
 */
 
?>
<script type="text/javascript">
var uservoiceJsHost = ("https:" == document.location.protocol) ? "https://uservoice.com" : "http://cdn.uservoice.com";
document.write(unescape("%3Cscript src='" + uservoiceJsHost + "/javascripts/widgets/tab.js' type='text/javascript'%3E%3C/script%3E"))
</script>
<script type="text/javascript">
UserVoice.Tab.show({ 
  key: '<?php print $key ?>',
  host: '<?php print $host ?>', 
  forum: '<?php print $forum ?>', 
  alignment: '<?php print $alignment ?>',
  background_color:'<?php print $background_color ?>', 
  text_color: '<?php print $text_color ?>',
  hover_color: '<?php print $hover_color ?>',
  lang: '<?php print $lang ?>'
})
</script>