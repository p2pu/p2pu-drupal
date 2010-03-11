$Id: README.txt,v 1.1.2.6 2008/12/10 20:25:14 davereid Exp $

CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Frequently Asked Questions (FAQ)
 * Known Issues
 * How Can You Contribute?


INTRODUCTION
------------

Maintainer: Narno <http://drupal.org/user/141690>
Maintainer: Dave Reid <http://drupal.org/user/53892>
Contributer: madler <http://drupal.org/user/123779>
Project Page: http://drupal.org/project/gravatar

This module integrates the Gravatar service with Drupal user pictures.


INSTALLATION
------------

See http://drupal.org/getting-started/5/install-contrib for instructions on
how to install or update Drupal modules.

User picture support (admin/user/settings) must be enabled for Gravatar to
work. Once Gravatar is installed and enabled, you can configure the module
at admin/user/gravatar.

You will also want to make sure user pictures are enabled for your theme at
admin/build/themes/settings and the approprate user roles have the 'use gravatar'
permission assigned to them at admin/user/permissions.


FREQUENTLY ASKED QUESTIONS
--------------------------

Q: Is Gravatar support enabled by default for my users?
A: If their user role has the 'use gravatar' permission, yes Gravatar is enabled
   by default.

Q: What if a user has a different Gravatar e-mail from their user account's
   email?
A: Currently, users can specify a separate Gravatar e-mail in their account
   page (user/x/edit). This option is slated for removal as Gravatar accounts
   can have more than one e-mail address associated with it.


KNOWN ISSUES
------------

There are no known issues at this time.

To report new bug reports, feature requests, and support requests, visit
http://drupal.org/project/issues/gravatar.


HOW CAN YOU CONTRIBUTE?
---------------------

- Write a review for this module at drupalmodules.com.
  http://drupalmodules.com/module/gravatar

- Help translate this module on launchpad.net.
  https://translations.launchpad.net/drupal-gravatar

- Report any bugs, feature requests, etc. in the issue tracker.
  http://drupal.org/project/issues/gravatar
