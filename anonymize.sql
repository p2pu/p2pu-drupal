USE p2pu_anon_db;

UPDATE users SET name='administrator' WHERE uid=1;
UPDATE users SET pass=MD5('password'),
mail=CONCAT('address', uid, '@example.com'),
init=CONCAT('address', uid, '@example.com');
UPDATE users SET name=CONCAT('user-', uid) WHERE uid > 1;
UPDATE realname set realname = CONCAT('User-', uid);
/* User profiles*/
UPDATE content_type_profile SET
field_profile_country_value = NULL,
field_profile_city_value = NULL,
field_profile_aboutme_value = 'P2PU student',
field_profile_aboutme_format = 1,
field_profile_facebook_url = NULL,
field_profile_facebook_title = NULL,
field_profile_facebook_attributes = NULL,
field_profile_twitter_url = NULL,
field_profile_twitter_title = NULL,
field_profile_twitter_attributes = NULL,
field_profile_gender_value = NULL,
field_profile_education_value = NULL;

/* It's nice to have a different name when looking at a user profile */
UPDATE content_type_profile p SET
p.field_profile_firstname_value = 'User',
p.field_profile_lastname_value = (SELECT n.uid FROM node n where n.nid = p.nid AND n.type='profile');

/* Google analytics */
UPDATE system SET status=0 WHERE name='googleanalytics';
/* Messaging */
TRUNCATE notifications_queue; /* Don't want to send off any queued notifications */
/* User imagecache pictures */
UPDATE variable SET value='s:1:"4";' WHERE name='user_picture_imagecache_profiles';
UPDATE variable SET value='s:1:"5";' WHERE name='user_picture_imagecache_profiles_default';
UPDATE variable SET value='s:1:"5";' WHERE name='user_picture_imagecache_comments';
/* Comments hostname */
UPDATE comments SET hostname = '127.0.0.1';
/* flood hostname */
UPDATE flood SET hostname = '127.0.0.1';
/* Remove some entries from the variables table */
/* I think it's better to remove them than to set them to null, as Drupal should always have a default to use*/
DELETE FROM variable WHERE name IN (
    'googleanalytics_account',
    'messaging_phpmailer_smtp_password',
    'messaging_phpmailer_smtp_username'
);
/* Clear the URL aliases that have the username  */
DELETE FROM url_alias WHERE dst LIKE "users/%";
