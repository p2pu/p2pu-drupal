/**
 * $Id: README.txt,v 1.5.2.1.2.7.2.2.2.1 2009/08/25 11:49:53 paulbooker Exp $
 * @package OG_Forum
 * @category NeighborForge
 */
This module extends the forum module to allow for Organic Groups to have their own forums.
When viewing groups, only forum discussions for that group are displayed. This module does
not hinder the creation of site-wide forums in any way. You can have both OG forums and
site-wide forums.  There are a multitude of settings for customizing how these forums work
which are detailed below.

--CONTENTS--
  REQUIREMENTS
  INSTALL
  SETUP
  FEATURES
  USAGE (Example)
  THEMING
  CREDITS
  
--REQUIREMENTS--
  This module requires both the OG module and the Forum module from Core to be installed.
     
--INSTALL--
  Before you post an issue to the queue with installation problems, be sure you did all
  of these things in this order:
  
  FOR A NEW SITE/ONE WITHOUT OG ALREADY INSTALLED
    1) Install the forum module through the regular Drupal means.
    
    2) Trigger the forum vocabulary creation routine by visiting admin/forums - this is
       the part most often overlooked.
       
    3) Install OG through the regular Drupal means.
    
    4) Install this module, again through the regular Drupal means.
  
  FOR A SITE WITH OG ALREADY INSTALLED
    1) Install the forum module through the regular Drupal means.
    
    2) Trigger the forum vocabulary creation routine by visiting admin/forums - this is
       the part most often overlooked.
       
    3) Install this module, again through the regular Drupal means.
    
    4) Go to admin/og/og_forum and click on "Update old groups" to have forum containers
       and default forums created for existing groups. See the FEATURES section for
       options.

--SETUP--
  There are two permissions that you can assign to roles: 'make forums public' and
  'admin own group forums'. The former is to allow non-group-owners the ability to set
  the publicity of forums in groups. Usually, you will want to reserve this for admins.
  
  The latter is to allow group owners all priviledges for administering forums of their
  groups.

--FEATURES--
  At admin/og/og_forum there are a bunch of options divided into five groups, three of
  which are fieldsets. The groupings are:
  
  -Retroactively update old groups
  -Default forum name
  -Group forum container
  -Forum publicity administration
  -Limit number of forums per group
  
  RETROACTIVELY UPDATE OLD GROUPS
    This is a single button which adds containers and forums to each existing OG and is
    to be used if you install og_forum into a site where groups already exist. You may
    wish to change some settings below before pushing this button.
    
  DEFAULT FORUM NAME
    When a new group is created, or during the retroactive forum creation function, each
    group is given a forum container with the term name of the group's name as well as one
    default forum. Normally, the default forum is called "General discussion". You may
    change that name here.
    
    CAVEAT - Having the container name the same as the group name makes it easy for people
      to find the group's forum in a site-wide listing of forums like at the 'forum' URL.
      This container's name will change as the group's name is changed.
  
  GROUP FORUM CONTAINER
    Rather than have all groups' containers and forums show up at the site-wide level, you
    may designate another (pre-existing) container for all group containers to be placed in.
    This alternate container may be any number of levels deep in the forum structure. To
    use this feature, check the box and select the container.
    
  FORUM PUBLICITY ADMINISTRATION
    This section has several controls which work together as follows:
    
   -AUTOMATIC FORUM PUBLICITY
      This turns on/off the automatic publicity of group forums. If a group forum has at
      least one post which is public, than entries will be made in the database to indicate
      that the forum and its container are also publicly browsable. If a group forum does
      not have any public posts, then that forum will not be publicly browsable except as
      noted below in conjunction with other settings.
      
      NOTE: The automatic setting uses two values for storing the forum and containers'
      states - PRIVATE_DEFAULT and PUBLIC_AUTO.
      
   -ALLOW PUBLIC CHOICE
      This allows group owners to decide which of their forums are public or private, but
      can also work with the auto setting above. First an explaination without the auto
      setting:
      
        In each forum, the group owner (or admins) will see a link in the context menu to
        'Administer group forums' which presents a table structure whereby they may edit
        forums' names or delete them, add forums to the container, make them public,
        make them private, or rest them. The publicity settings enter these values into the
        database - PRIVATE_SET_BY_OWNER, PUBLIC_SET_BY_OWNER, and PRIVATE_DEFAULT. The 'set
        by owner' values take precedence over the 'auto' and 'default' values.
        
      With the auto setting:
      
        Forums and containers will appear or not in any browsable listing per the standard
        automatic rules unless overridden by the group owner or an admin. As mentioned above,
        the 'set by owner' values take precedence over the 'auto' and 'default' values when
        determining publicity or browsability.
        
   -MAKE ALL FORUMS PUBLIC
      Checking this does not mean you can't check the options above. However, the effects of
      any settings made under the above settings will not be appearant unless this feature
      is later turned off. This is either an easy way to ensure that all forums are always
      browsable by the public, or may be used to temporarily open the site for something like
      an 'open house'. Turning it off would keep in-tact any settings made before its use.
      
   -MANAGE PUBLICITY OF OLD GROUPS
      Similar to the other retroactive control above, this one manages publicity settings in
      the database for the case where you are upgrading from a version of og_forum without
      these features. As noted on the admin page, it should only be used once.
      
   -SWITCH TO AUTOMATIC PUBLICITY
      Although this may sound like simply turning off the 'Make all forums public' check box
      and ensuring that the 'Automatic forum publicity' checkbox is set, that is NOT what
      this feature does.
      
      Should you use the 'Allow public choice' feature, but later decide that as site admin
      you would like total control of the forums' publicity, you may push this button and
      change all entries in the database to reflect a state as though they had always been
      managed by the 'Automatic forum publicity' feature.
      
      In other words, PUBLIC_SET_BY_OWNER will be changed to PUBLIC_AUTO and PRIVATE_SET_BY_
      OWNER will be changed to PRIVATE_DEFAULT in all database entries. Make sure that you
      uncheck the 'Allow public choice' checkbox, or else group owners will continue to be
      able to make their own settings.
    
  LIMIT NUMBER OF FORUMS PER GROUP
    Here you can set a three digit number (0 - 999) to limit the number of forums that may
    be created by group owners. This limit does not apply to user 1, nor to those with the
    'administer forums' permission.
    
--USAGE--
  I couldn't think of anything not already covered by the FEATURES section. If anyone has a
  special use-case or combo of settings they think need special mention here, let me know.

--THEMING--
  NOTE: This module overrides the theme functions from Drupal core's
    forum module.
    
  There are three theme functions that are overridden. It would be best for you to copy the
  functions from this module to your theme files, rather than use the originals from the
  forum module as starting points.
  
--CREDITS--
  Ryan Constantine (Drupal ID rconstantine) & Paul Booker (Drupal ID paulbooker)  are the current maintainers.
  
  Darren Oh is a previous maintainer.

  Historical thanks to:
  Evan Leeson of Catalyst Creative for sponsorship of 4.7 port and
  improvements.
  Gavin Mogan for http://drupal.org/node/63379 which was a huge help in
  porting the module.