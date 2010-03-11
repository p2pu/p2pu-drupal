/**
 * $Id: README.txt,v 1.5 2008/10/01 22:33:38 paulbooker Exp $
 * @package OG_CTA
 * @category NeighborForge
 */

This module adds the ability to have certain content types available only to certain groups.

Since the permissions system only gives a user permission to create a given content type or not,
and doesn't allow us to specify where that user can place that content, this module aims to be 
one way to take care of that. A primary goal of this module was to NOT change any core files.

--Setup--
The site admin must first install the module per the regular drupal installation pattern. This
will:
  1) add a table to the database
  2) adjust it's weight in the table to come after certain other modules
  3) add a 'site-wide' entry in our new table (more on this later)
  4) add a 'default' entry in our new table (more on this later)
  5) copy the settings from OG's block called og_block_detail
  6) deactivate og_block_detail
  7) using the data from og_block_detail, insert an entry for our block which overrides functionality
  8) update the title of the menu entry for 'Create content' to indicate a little better that this
     menu is for site-wide content only
     
--Site Configuration--
The site admin then must go to admin/og/og_content_types to:
  1) change settings for the 'site-wide' content types
  2) change settings for the organic group 'default' content types
  3) add groups to monitor separately
  4) change setting for separately-monitored groups

The settings that can be changed from this UI are:
  1) 'allowed' - this means that a group owner CAN enable or ACTIVATE a given content type for the group.
     the owner doesn't have to ACTIVATE any content type, though that would be a boring group. the group
     owner can create any kind of ALLOWED content, even if his members can't. this would effectively be
     a read-only group. comments can still be made.
  2) 'required' - this means that as the site admin, you want the users of a group to AT LEAST be able to
     create the given content type. this is useful if you think group owners might have trouble figureing
     things out, or you want your site to be known for a particular feature.
  3) propagate an 'allowed' setting for one content type to all groups except the 'Site Wide' group. This
     is particularly useful when you create a new content type well after your group admins have customized
     how they use the content types you have allowed them to activate or deactivate.

--Group Configuration--
The group admin must go to og_content_types/manage from within the group to:
  1) view and select which ALLOWED content types are ACTIVATED.
     those types not ALLOWED will be hidden. those types which are REQUIRED will be disabled.
     
--What all of this does--
This changes three major things:
  1) in the main navigation menu, you should be familiar with the sub menu called 'Create content'. this
     module removes all menu items which point to the creation of content types not ALLOWED at the 'site-wide'
     settings.
  2) in the group detail block, which also has a menu of content type creation with a gid in the url, this
     module substitutes its block instead of the standard OG block. this allows for the removal of DEACTIVATED
     or NOT_ALLOWED content type links.
  3) this module changes (in $_menu) the callback reference for node_add so that changes can be made to the
     page which is displayed. those content types which are either DEACTIVATED or NOT_ALLOWED at the 'site-wide'
     level are removed from the display. additionally, any attempt to go to node/add or any node/add/$type URL
     directly are intercepted and routed to node/add, displaying the ALLOWED and ACTIVATED types the user can
     create. this also works for URLs with gids in them.
  4) this module deactivates groups in the Audience fieldset that do not allow the Content Type currently
     being created.
     
--Uninstallation--
This is done the usual way, first by deactivating, then uninstalling. A reversal of any changes made during
installation is performed.