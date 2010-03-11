The Mass Contact module is simply a modified version of the core contact
module. It works opposite the latter, in that it allows site moderators (or
anyone with permission), to send mass e-mail to a set role or group of roles
or even to all registered users.

Scaling factors:
 -Retrieving userids and emails in a scaled way: no
 -Sending email in a scaled way: yes, within server limits
 -Keeping connections up while the long process continues: no

The sender's own address may be placed in the 'To:' field and all recipients
placed in the 'Bcc:' field, or the recipients simply placed in the 'To:'
field. Note that the latter option leaves all recipients open to abuse due to
their e-mail addresses being visible to all other recipients.

The e-mail may be sent as html or plain text, and may include a single binary
file attachment (if permitted by admin).

At the option of the sender (if permitted by admin), a node may be created in
order to keep a record of the e-mail sent. Do not try to send e-mails by
creating nodes; it will not work.

Users may opt-out of mass mailings on their profile page, but this may be
overridden by the admin (or respected). The entire opt-out system may be
disabled on the settings page.

Make sure to add at least one category and configure the module before trying
to send mass e-mails.

The Mass Contact module also adds a menu item (disabled by default) to the
navigation block.
