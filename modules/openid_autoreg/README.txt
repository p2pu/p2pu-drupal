Drupal openid_autoreg README.txt
==============================================================================

This module allows automatic registration of OpenID users, even if OpenID provider does not
supply required fields (email and username).
Since this is very common case, login with OpenID button usually works not as expected.
Instead of silently logging in, user gets confusing messages.

This version of the module only works with Drupal 6.x.

Features
------------------------------------------------------------------------------
Module modifies user admin settings form, adding 'OpenID autoregistration' setting.
Note that autoregistration would work only if Public registration option in admin/user/settings is set to 
'Visitors can create accounts and no administrator approval is required.'

Module settings available in administer user settings form (admin/user/settings),

Note for CAPTCHA users
------------------------------------------------------------------------------
If CAPTCHA is turned on on user registration form, 
autoregistration will work only when Persistence in CAPTCHA settings (admin/user/captcha)
is set either to 
'Omit challenges for a form once the user has successfully responded to a challenge for that form.'
 or 'Omit challenges for all forms once the user has successfully responded to a challenge.'
 This is known issue, probably I'll address it in next releases.