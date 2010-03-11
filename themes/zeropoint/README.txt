README.TXT // 0 Point theme for Drupal 6.

Thank you for downloading this theme!


ABOUT THE 0 POINT THEME:
-------------------------------------------------------------------------+
0 Point is an advanced theme. It contains the same kinds of features 
you'll find in our other Drupal themes, plus many more.

The theme validates XHTML 1.0 Strict / CSS 2, and it is cross-browser compatible; 
works perfect in Firefox, IE 6, IE 7, IE8, Safari, Opera and Google Chrome.

Layout features
===============
- 1, 2, or 3 column layout with adaptive width (min. 1040px max.1200px at 1440px 
	disply width) based on "The Jello Mold Piefecta Layout" 
	(http://www.positioniseverything.net/articles/jello.html); 
- 16+1 collapsible block regions; 
- 7 colour styles; 
- built-in IE transparent PNG fix; 
- jQuery CSS image preload (optional) 
	(http://www.filamentgroup.com/lab/update_automatically_preload_images_from_css_with_jquery/); 
- Fixed / Variable width sidebars (optional); 
- Round corners for page elements and primary menu (optional); 
- Block icons (optional); 
- Page icons (optional); 
- SuckerFish Drop-down primary links menu (optional); 
- Primary links menu position (center, left, right); 
- Helpful body classes (unique classes for each page, term, website section, 
	browser, etc.). Everything can be controlled via CSS, including each menu
	item (for statis menu), how colours and other items will be displayed in
	different browsers, or by terms, sections, etc.; 
- Full breadcrumb; 
- Works perfect in Multilanguage installations. 

Advanced theme settings features
===============================
Layout settings
- Style - Choose a colour palette from 7 options: 0 Point (default), 
	Sky, Nature, Ivy, Ink, Sangue and Lime. More colour options to come.
- jQuery CSS image preload - Choose a colour.
- Sidebars layout - Fixed width sidebars or variable width sidebars.
- Rounded corners - Option to have rounded corners in all browsers but IE.
- Block icons - Choose between none, 32x32 pixel icons and 48x48 pixels icons.
- Page icons - Choose a layout with or without page icons.
- Menu style - Two-level Static or SuckerFish drop-down menu.
- Menu position - Left, center or right.

General settings
- Mission statement - Display mission statement only on front page or on all pages; 
- Display Breadcrumb; 
- Username - Display "not verified" for unregistered usernames; 
- Search results - Customize what should be displayed on the search results page. 

Node settings
- Author & date - display author's username and/or date posted; 
- Taxonomy terms - How to display (or not) vocabularies and category terms. 

Search engine optimization (SEO) settings
- Page titles - Format the title that displays in the browser's title bar; 
- Meta tags. 



MODULE SUPPORT
-------------------------------------------------------------------------+
This theme can support virtualy any module.
It has been heavily tested with:
  - AdSense;
  - Advanced Forum;
  - Blockquotes;
  - CAPTCHA;
  - CCK;
  - Fivestar;
  - Gallerix;
  - Gallery Assist;
  - Google_cse;
  - Google_groups;
  - Gmaplocation;
  - i18n;
  - Image;
  - ImageCache;
  - Panels;
  - Pathauto;
  - Lightbox2;
  - Logintoboggan;
  - Print;
  - Simplenews;
  - Thickbox;
  - ÜBERCART;
  - Views;
  - Wysiwyg (TinyMCE and FCKeditor);
  - Weather;


  
THEME MODIFICATION
-------------------------------------------------------------------------+
0 Point theme alow many sub-themes as plugins. More sub-themes will 
be available at http://www.radut.net/drupal/

If you feel like giving the theme a look of your own, I recommend to play
with /_custom/custom-style.css; please read the comments in this file.



SIDEBARS DIMMENSIONS
-------------------------------------------------------------------------+
The maximum with available for sidebars is as follow:

                                         | left | right | both
-----------------------------------------------------------------
Variable asyimmetrical sidebars (wide)   | 250  |  300  | 160-234
-----------------------------------------------------------------
Fixed asyimmetrical sidebars (wide)      | 160  |  234  | 160-234
-----------------------------------------------------------------
Variable asyimmetrical sidebars (narrow) | 230  |  280  | 140-214
-----------------------------------------------------------------
Fixed asyimmetrical sidebars (narrow)    | 140  |  214  | 140-214
-----------------------------------------------------------------
Equal width sidebars (narrow)            | 155  |  155  | 155-155
-----------------------------------------------------------------

NOTE: Do not exceed the available width (especially with images) or IE will 
not behave so the sidebars may drop. 



USING THE SuckerFish DROP-DOWN MENU
-------------------------------------------------------------------------+
The menu can either be a two-level static menu or a suckerfish drop-down menu.

Out of the box the theme will show the primary and secondary menu. If you select 
(/admin/build/menu/settings) the same menu as primary links then secondary 
links will display the appropriate second level of your navigation hierarchy.

Choose "Suckerfish" to enable support for Suckerfish drop menus. 
NOTE: Go to /admin/build/menu and expand all parents in your primary menu.

KNOWN ISSUES: In order to avoid Opera's rendering problems, SuckerFish position
can be only left.



INSTALLATION INSTRUCTIONS
-------------------------------------------------------------------------+

1) Place the zeropoint directory into your themes directory (sites/all/themes/zeropoint).

2) Enable the 0 Point theme (/admin/build/themes).

3) You can configure settings for the 0 Point theme at /admin/build/themes/settings/zeropoint.  



UPGRADING to a new version of 0 Point
-------------------------------------------------------------------------+

1) If possible, log on as the user with user ID 1. 

2) Put the site in "Off-line" mode.

3) Go to admin/build/themes/settings/zeropoint and change the theme development
   settings to "rebuild theme registry on every page". 

4) Place the zeropoint directory into your themes directory (sites/all/themes/zeropoint).
   In case you have done customization to 0 Point theme, remember to overwrite theme
   custom-style.css with your custom-style.css file.

5) Configure the new settings for the 0 Point theme at /admin/build/themes/settings/zeropoint. 

6) Clear the Drupal cache and deactivate the "rebuild theme registry on every page"
   option and put the site in "On-line" mode. It is always a good idea to refresh 
   the browser's cache (CTRL+F5).



CONTACT
-------------------------------------------------------------------------+
My drupal nick is florian <http://drupal.org/user/35316> – and I can be reached 
at florian@radut.net.

I can also be contacted for paid customizations of 0 Point theme as well as
Drupal consulting, installation and customizations.

The theme is installed at: 
http://www.boaz.ro/
http://www.ecoimm.ro/
http://www.eureko.ro/
