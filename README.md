How to get your dev environment set up
======================================
Requirements
------------
* install drush, php, php cli (Make sure you install PHP 5.2.x)
* you probably want to increase the memory limit for php and php cli, i have it
  set up to 128MB and it STILL spazzes some times. 
* apache is probably the easier web server to run because this is php.
* make sure mod rewrite (rewrite.load) is enabled in /etc/apache2/mods-enabled.
* set up a virtual host for server. here is an example virtual host file:

      <VirtualHost *:80>
           ServerName p2pudev.p2pudev
           ServerAdmin jessy.cowansharp@gmail.com
           DocumentRoot /home/jessy/dev/p2pu/drupal/src/drupal-6.19
           ErrorLog /var/log/apache2/p2pudev-error
           CustomLog /var/log/apache2/p2pudev-access.log combined

         <Directory /home/jessy/dev/p2pu/drupal/src/drupal-6.19>
            RewriteEngine On
            RewriteBase /
            RewriteCond %{REQUEST_FILENAME} !-f
            RewriteCond %{REQUEST_FILENAME} !-d
            RewriteRule ^(.*)$ index.php?q=$1 [L,QSA]
        </Directory>
      </VirtualHost>

* add an entry to your /etc/hosts file:
  $`sudo vi /etc/hosts`

* then add your site name to the end of the localhost line
  127.0.0.1   localhost p2pudev.p2pudev 

installation
------------

* create a new database for the site: 
    $ mysql -u root -p 
    mysql> create database p2pu_dev_anonymized;
    mysql> exit;

* grab the db dump from Dropbox. 
    $ wget http://dl.dropbox.com/u/1914037/p2pu_anon_db.20101101.tgz
    $ tar xvfz p2pu_anon_db.20101101.tgz
    read in into mysql:
    $ mysql -u root -p p2pu_dev_anonymized < p2pu_anon_dump.sql

* set up the admin password (change 'password' to whatever you like):
    $ mysql -u root -p 
    mysql> use p2pu_dev_anonymized;
    mysql> update users set pass = md5('password') where uid=1;

* download and unpack drupal core into your site root (6.19)

* checkout the p2pu.org files from svn into sites/all within your drupal install:
    git clone http://github.com/p2pu/p2pu.git all

* copy sites/default/default.settings.php to sites/default/settings.php  
* edit the $db_url setting to contain the right db settings. eg:
    $db_url = 'mysql://myusername:mypassword@localhost/p2pu_dev_anonymized';

also, in case you have any trouble logging into the site at first, you might
want to set $update_free_access = TRUE;, which will allow you to run update.php
without authenticating

* set up the permissions on the files and themes directories so the web server can move move things around as it sees fit:
  sudo chown -R <username>.www-data all/files
  sudo chmod -R 775 all/files
  sudo chown -R <username>.www-data all/themes
  sudo chmod -R 775 all/themes

(these permissions may mean you need to use sudo when running drush)

* follow instructions at http://tracker.p2pu.org/website/node/72, starting at
  step 3:
  * 3: as prescribed
  * 4: all prescribed
  * 5: drush dl reroute_email
     drush en reroute_email
     drush php-eval "menu_router_build(TRUE);" 
     then as described
  * 6: as described
  * 7: as described

* you probably want to turn the css caching settings off so you'll see any css
  changes you make:  
  $ drush -y vset cache '0'
  $ drush -y vset page_compression '0'
  $ drush -y vset preprocess_css '0'
  $ drush -y vset preprocess_js '0'

* you should now be able to access your site at the hostname you set in
  /etc/hosts, eg. http://p2pudev/p2pudev

if you get an error about files /tmp/filex837fgs could not be uploaded,because
the destination is not properly configured, then double check that your
sites/all/files/ directory is web server writable

* go to /user/login, and login as administrator or siteadmin, with password you
  set above. (if you're having any rewrite problems, go to example.com/?q=user)

* run update.php


if you need to update the database again
----------------------------------------
* read in the new copy of the db (see above)
* run update.php
* sudo dbrush cc all


How to Include Database Chages Made Via GUI in the Codebase
-----------------------------------------------------------
* Make your change in gui
* run `drush features-update p2pu_courses`
* Commit your change


How Others Can Update Their Feature to the One You Just Pushed
--------------------------------------------------------------
* git pull origin master
* `drush features-revert p2pu_courses`


Other Notes
-----------

Make sure that the languages/ directory in the Drupal root is writable by the
web server user. If you get errors about moving files from /tmp/fileXXXX to
languages/p2pu_XXXX.js, this is the reason.  Random database update: UPDATE
variable SET value = 's:46:"sites/all/modules/popup/styles/Soft grey frame";'
WHERE name = 'popup-style'; and your watchdog will stop being littered with
error messages. 

Another random database update: UPDATE variable SET value =
's:15:"sites/all/files"' WHERE name = 'file_directory_path' and you will stop
getting error messages about CTools not being able to create CSS cache
directory.

