#!/bin/bash 

hostname=$(hostname)
if [ "$hostname" != "li186-229" ]
then
  echo "You should not be running this here"
  exit
fi


APACHE_PATH=/etc/apache2
DRUSH=/etc/drush/drush

read -p "Enter the name of the new site (SITENAME.dev.p2pu.org): " NSITE
read -p "Enter your SSH username for www.p2pu.org : " P2PU_USER
read -s -p "Enter the MySQL root password for dev.p2pu.org : " DBPASS 
echo 

function copy_site {	
  
  echo 
  echo Checking out site
  svn co http://p2pu.org/svn/p2pu/trunk/p2pu.org/ /var/www/p2pu_dev/sites/$NSITE.dev.p2pu.org
     
  echo Importing anonymized images
  echo
  echo Enter your SSH password for www.p2pu.org below
  rsync -avz -e ssh $P2PU_USER@p2pu.org:/tmp/p2pu.org_anon_files/ /var/www/p2pu_dev/sites/$NSITE.dev.p2pu.org/files/ 
  
  echo Setting permissions
  chmod 777 -R /var/www/p2pu_dev/sites/$NSITE.dev.p2pu.org/files/
  
  echo  
}
  
function edit_drupal_settings {
  echo 	
  DS_PATH=/var/www/p2pu_dev/sites/$NSITE.dev.p2pu.org
  echo Copying and updating settings.php
  cp /etc/p2pu/template_settings.php $DS_PATH/settings.php
  sh -c "cat $DS_PATH/settings.php | sed -e 's/P_DATABASE/p2pu_dev_$NSITE/;s/P_PASSWORD/p2pu_password/;s/P_USERNAME/p2pu_public/;s/P_BASE_PATH/$NSITE.dev.p2pu.org:1000/;' > $DS_PATH/settings.php.tmp"
  mv $DS_PATH/settings.php.tmp $DS_PATH/settings.php  
  
  echo 
  echo Enter your dev.p2pu.org SSH password below \(must have sudo rights\):  
  sudo chown p2pu_public -R /var/www/p2pu_dev/sites/$NSITE.dev.p2pu.org

  echo
  echo Setting permissions
  
  echo
}

function create_db {
  echo Creating database p2pu_dev_${NSITE}
  mysql -u root -p$DBPASS -e "CREATE DATABASE p2pu_dev_${NSITE};"
  
  echo Retrieving Anonymous dump
  echo
  echo Enter your SSH password for www.p2pu.org below
  scp p2pu.org:/tmp/p2pu_anon_dump.sql.zip /tmp/p2pu_anon_dump.sql.zip
  
  echo Decompressing
  unzip -j -o /tmp/p2pu_anon_dump.sql.zip -d /tmp
  
  echo Importing to p2pu_dev_$NSITE - can take a while
  mysql -u root -p$DBPASS p2pu_dev_${NSITE} < /tmp/p2pu_anon_dump.sql  
  
  mysql -u root -p$DBPASS -e "GRANT ALL on p2pu_dev_${NSITE}.* TO 'p2pu_public'@'localhost';"
  
  echo Clearing files
  rm /tmp/p2pu_anon_dump.sql.zip
  rm /tmp/p2pu_anon_dump.sql
  echo
}



function drush_updates {
  echo 	
  cd /var/www/p2pu_dev/sites/$NSITE.dev.p2pu.org/
  echo Setting Drupal variables
  $DRUSH vset site_name "$NSITE P2PU Development Site" --yes
  
  $DRUSH vset popup-style "sites/$NSITE.dev.p2pu.org/modules/popup/styles/Soft grey frame" --yes
  $DRUSH vset file_directory_path  "sites/$NSITE.dev.p2pu.org/files" --yes
  $DRUSH vset getid3_path "sites/$NSITE.dev.p2pu.org/modules/getid3/getid3" --yes
  $DRUSH vset user_picture_default "sites/$NSITE.dev.p2pu.org/files/pictures/default-user.png" --yes
  $DRUSH vset better_messages_skin "sites/$NSITE.dev.p2pu.org/modules/better_messages/skins/default/default.css" --yes
  $DRUSH vset mass_contact_attachment_location "sites/$NSITE.dev.p2pu.org/files/mass_contact_attachments" --yes
  
  echo Updating Paths  
  $DRUSH sqlq 'UPDATE `system` SET `filename` = REPLACE(`filename`, "sites/p2pu.org/", "sites/$NSITE.dev.p2pu.org/");'
  $DRUSH sqlq 'UPDATE `files` SET `filepath` = REPLACE(`filepath`, "sites/p2pu.org/files/", "sites/$NSITE.dev.p2pu.org/files/");'
  $DRUSH sqlq 'UPDATE `users` SET `picture` = REPLACE(`picture`, "sites/p2pu.org/files/", "sites/$NSITE.dev.p2pu.org/files/");'
  
  echo Clearing Cache - will take a while \(Some errors are normal\)
  $DRUSH php-eval "module_rebuild_cache();drupal_clear_css_cache();system_theme_data();"
  $DRUSH sqlq 'TRUNCATE cache;'
  $DRUSH cc all
  $DRUSH cc all
  $DRUSH php-eval "menu_router_build(TRUE);"
  echo Caches cleared
  echo
}

function show_info {
  echo
  echo Script complete!
  echo
  echo
  echo Site URL: http://$NSITE.dev.p2pu.org:1000/
  echo Files Path: /var/www/p2pu_dev/sites/$NSITE.dev.p2pu.org
  echo
  echo Drupal Login details: administrator, user-1, user-2 etc.
  echo Drupal Login password: password
  echo 
  echo SSH username: p2pu_public
  echo SSH password: p2pu_password
  echo
}

echo
read -p "Copy the sites files? (y/n) : "
if [[ $REPLY =~ ^[Yy]$ ]] 
then
  copy_site
  edit_drupal_settings  
fi

echo
read -p "Setup and import the database? (y/n) : "
if [[ $REPLY =~ ^[Yy]$ ]] 
then
  create_db
fi

echo
read -p "Run Drush updates? (y/n) : "
if [[ $REPLY =~ ^[Yy]$ ]] 
then
  drush_updates
fi

show_info



