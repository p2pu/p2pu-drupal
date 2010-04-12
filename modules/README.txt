Listing of temporary patches applied to contrib modules
=======================================================

messaging-548864-2.patch

In the drupal logs, messaging was reporting a php mailer error, as reported by George here: http://tracker.p2pu.org/website/node/61
This patch is taken from http://drupal.org/node/548864#comment-2287766

reroute_email_arrayissue.patch

This module is not used on production, only on test to route all mails to a single address.
This patch fixes an empty message body.
See http://tracker.p2pu.org/website/node/16 and http://drupal.org/node/488032