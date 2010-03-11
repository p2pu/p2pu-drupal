;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Field Permissions module
;; $Id: README.txt,v 1.1.2.3 2009/11/14 12:32:51 markuspetrux Exp $
;;
;; Original author: markus_petrux (http://drupal.org/user/39593)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CONTENTS OF THIS FILE
=====================
* OVERVIEW
* USAGE
* REQUIREMENTS
* INSTALLATION
* UPGRADING FROM CCK CONTENT PERMISSIONS


OVERVIEW
========

The Field Permissions module is a drop-in replacement for the Content
Permissions module shipped with CCK.

The key differences are:

  * It allows site administrators to set field-level permissions to edit or
    view CCK fields in any node, and optionally (new feature compared to
    Content Permissions), edit or view permissions for nodes owned by the
    current user.

  * Permissions for each field are not created by default. Instead,
    administrators can enable these permissions explicitly for the fields
    where this feature is needed.


USAGE
=====

Once Field Permissions module is installed, you need to edit the field settings
form to enable permissions for each where you need this feature. You can enable
any of the following permission types:

  * Create FIELD (edit on node creation).
  * Edit any FIELD, regardless of its node author.
  * Edit own FIELD on node created by the user.
  * View any FIELD, regardless of its node author.
  * View own FIELD on node created by the user.

Use these options to enable role based permissions for this field. When
permissions are enabled, access to this field is denied by default and explicit
permissions should be granted to the proper user roles from the permissions
administration page. On the other hand, when these options are disabled, field
permissions are inherited from node view and/or edit permissions. In example,
users allowed to view a particular node will also be able to view this field,
and so on.


REQUIREMENTS
============

- CCK (6.x-2.5 or higher).
  http://drupal.org/project/cck

  Field permissions requires that hook_field_access() is invoked with $account
  as 3rd argument (added to CCK in 6.x-2.2, see [#336174] [1]) and $node as 4th
  argument (added to CCK in 6.x-2.5, see [#514452] [2]).

  [1] http://drupal.org/node/336174
  [2] http://drupal.org/node/514452


INSTALLATION
============

- Be sure to install all dependent modules.

- Copy all contents of this package to your modules directory preserving
  subdirectory structure.

- Go to Administer -> Site building -> Modules to install module.

- Review the settings of your fields. You will find a new option labelled
  "Field permissions" that allows you to enable permissions per field. It
  is disabled by default.


UPGRADING FROM CCK CONTENT PERMISSIONS
======================================

The Field Permissions module is fully compatible with the permissions already
defined with Content Permissions module shipped with CCK.

  1. Make backups to ensure you can easily fallback in case of any trouble.
  2. Install Field Permissions module while Content Permissions module is
     still enabled.
  3. Disable and then Uninstall Content Permissions module.
  4. You can now check your existing permissions are still there, in the
     Permissions administration screen.
  5. Now, you may wish to disable permissions for fields where this feature
     is not really needed.
