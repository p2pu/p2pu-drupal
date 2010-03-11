DESCRIPTION
--------------------------------------------------
This module provides functionality for inheritance when assigning groups to book pages.
Books can be made to use the groups of their immediate parent or their top level parent.
The public flag can also be inherited.
The module also allows you to make groups manatory for books, so that the groups must either inherit from their parents or a selection must be made.


INSTALLATION
--------------------------------------------------
- Make sure the og modeule and the book module are both enabled (This module also has some functionality related to the og_access module if that is also installed).
- Enable the OG book inheritance module.
- Visit the admin/og/og-book-inheritance page.
- On admin/og/og-book-inheritance, select whether you want to inherit from a book page's immediate parent or their top level parent and under what circumstances you want inheritance to take place.  You can also select whether or not the public flag is inherited and whether or not to make group selection mandatory (inheriting from a parent counts as a selection).  Then to enable the inheritance check the enable checkbox at the top of the settings page.


MODULE INFORMATION
--------------------------------------------------
- see http://drupal.org/project/og_book_inheritance


MODULE BUGS/ISSUES/FEATURE REQUESTS
--------------------------------------------------
- see http://drupal.org/project/issues/og_book_inheritance


CREDITS
----------------------------
Authored and maintained by Agileware - http://www.agileware.net
