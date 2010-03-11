email_verify: Verifies thoroughly that email addresses are correctly entered
              during registration and account edition.

Copyright: Daniel Bonniot <bonniot@users.sourceforge.net>
License:   GNU GPL v2 or later


Description
-----------
This module provides advanced email address checking. The core of
Drupal, through the user module, only performs syntactical checking of
user-entered email addresses, both during registration and account
edition. This creates loads of problems when users incorrectly enter
their address. First, they don't get any email from the site. If it
happened during registration, they will not get their password. They
will either bug the site admin or give up on the site altogether,
both cases being a bad thing. Second, the site admin will get email
bounces, which soon gets annoying if you have a moderately busy site.

This module tries to solve this problem by checking that the address
really exists when it is entered by the user. First, it checks if the
domain/host part exists at all, and reports an error if it does not. I
found that this step alone catches between 1/2 and 2/3 of typos.
Second, it tries to validate the user name too, by sending a HELO/MAIL
FROM/RCPT TO chain of commands to the SMTP servers for the found
host. Some hosts will not reveal if the user name is valid ("catch-all
policy") while others might refuse the check for some reason (for
instance, some hosts refuse deliveries from IPs delivered to home
users by Internet access providers). When in doub, we try to play it
safe and rather accept some invalid addresses than to refuse valid
ones.

NOTES:
* Provide any feedback on the issue queue:
  http://drupal.org/project/issues/email_verify
* Please send feedback to the author, both praise and constructive
  criticism, even patches!
* If the module does not make the right decision about a certain
  address, let me know so I can check it. If you can provide a detailed
  SMTP conversation to illustrate what is happening _from_the_machine
  hosting_your_site, that will be most helpful.
* See below for known issues and things that can be improved.


Installation
------------
This module requires no database changes.

Install like any other module: copy the whole email_verify directory 
into the directory sites/all/modules/ or wherever you usually put contrib modules.

You then need to go to admin/build/modules and check the Enabled box for
email_verify, then save configuration. The module uses the hooks for
user account validation. Therefore, email checking is automatically
active from then on. Sit back, and enjoy getting ten times less of
those email bounces and see more people succeed in registering to your
site!

If you see 'warning: fsockopen(): ...' output on your pages, make sure
that you set 'Error reporting' on admin/settings/error-reporting to 'Write errors to
the log'. You will still see such errors in the log. They indicate
that an SMTP server did not respond (in which case the username was
supposed valid).


Things to do / Known problems
-----------------------------
See the module's issue queue:
http://drupal.org/project/issues/email_verify


Contact
-------
Feedback should be sent to bonniot@users.sourceforge.net

This module is used in production on my drupal site: http://objectiftarot.net
