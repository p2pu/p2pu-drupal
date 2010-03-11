// $Id: README.txt,v 1.1.2.4 2008/06/15 00:11:01 jrbeeman Exp $


NAME
--------------------------------
Organic Groups - Audience by Type modules


DESCRIPTION
--------------------------------
Note on terms: "content type" and "node type" are synonymous. In this document 
we use "node type." Any node type may be designated as a "group type" in order 
to use the Organic Groups system. 

The OG ABT module allows more fine-grained control over the presentation of the 
node add / edit form's audience selector. It offers the following added 
functionality:

* In place of the default OG method of listing all groups in alphabetical 
  order, groups of different node types are presented by type in audience 
  selector. This is useful on sites with a very large number of groups and 
  many different group types.  For example, a site with Districts, Schools 
  and Interest Groups (all group types defined as organic groups) will be 
  able to subdivide the group selectors by group type. 
  
  This is default behavior if the module is enabled, and no settings need to 
  be configured.

* If there are groups of more than one node type, any group type can be 
  excluded from appearing in the audience selector of the node add / edit form 
  for any non-group node types. This is useful if you have content which you 
  want to place only into groups of one group type but not into groups of 
  another group type. 

  On editing a group type (OG enabled node type), there is an 'OG audience 
  settings' tab. Each node type which is not a group type is shown there, and 
  for each you can choose the option 'Omit from the audience targeting scheme.'

* Nodes of any non-group node type can be configured to force placement into 
  only one group of a group type. This is useful if you have content which must 
  be assigned to only one group of a particular group type. Optionally, it can 
  also be required that one group be selected. 

  On the 'OG audience settings' page for any group type, tick 'Force single' 
  for any non-group node type where you want to limit placement into only one 
  group. Optionally, also tick 'Require' to prevent the user from saving the 
  node without choosing one group.

* Nodes of any non-group node type can be configured to allow users of 
  particular role/s to post content into all groups of a group type, regardless 
  of whether the user is a member of the group. This is useful if you want some 
  privileged users to be able to post content into any group without having to 
  become a member of the group. 

  On the 'OG audience settings' page for any group type, select those roles in 
  the 'Administrator roles' drop down list to which you want to allow this 
  privilege.

* For any non-group node type, the 'Public' checkbox in the audience box can 
  be omitted for users who do not have a particular role/s. This is useful if 
  you want to prevent some users from making a post public. 

  On the 'OG audience settings' page for any non-group node type, select any 
  role/s to which you want to restrict the visibility of the 'Public' checkbox. 
  If no roles are selected, the behavior of the checkbox will remain unaffected.


INSTALLATION
--------------------------------
The module provides the audience-by-type functionality after it has been
enabled at Administer, Site building, Modules.

There are additional options available for the various content types that can
be published to organic groups.  These can be found on the "OG audience settings"
tab of each group type's content settings page, i.e. Administer, Content
management, Content types, <type name>.


INCLUDED MODULES
--------------------------------
Other modules can tap into and modify the resulting list of groups presented
in each audience selection box by implementing hook_og_abt_alter().  See
og_abt_domain.module for an example.


Organic Groups ABT Domain Module
--------------------------------
The OG ABT Domain module adds a setting which is useful for multisite 
configurations which use Drupal's core sub-directory multisite method and which 
use organic groups in all domains (by sharing the nodes across domains). It 
allows limiting the groups that appear in the audience selector to only those 
groups which are assigned to the active domain, via a vocabulary. 

To implement this:
- Enable the OG ABT Domain module.
- Create a domains vocabulary, and associate it with each group type you have 
  configured.  Each of your domains needs to be added as a term; the actual 
  domain names (e.g. one.example.com, two.example.com) need to be consistently 
  either the name or the description for each term.
- For each group on your site, select the domain (or domains) in which you 
  want it to appear.
- Go to Administer, Organic Groups, Audience selector domain settings, and 
  choose your domains vocabulary. Choose whether the names or descriptions of 
  that vocabulary contain the domain names. Optionally, tick the box to enforce 
  'Strict domain checking.' If this is not ticked, groups which are not 
  assigned to any domain will appear in the audience selector on all domains.
- Now, a user in any domain will see in the audience selector only those groups 
  which are assigned to the active domain. 


CREDITS
--------------------------------
* Authored and maintained by Jeff Beeman (jrbeeman on drupal.org)
* Some development sponsored by Edward Peters, Initiative of Change (iofc.org)