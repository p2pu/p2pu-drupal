#!/bin/bash 

read -s -p "Enter the www.p2pu.org Drupal MySQL password : " DBPASS 

function anonymize_images {
  echo Anonymizing files - can take a while
  cd /tmp/p2pu.org_anon_files/
  find /tmp/p2pu.org_anon_files/ -iname "*.png" -o -iname "*.jpg" -o -iname "*.gif" | xargs -l -i convert '{}' -verbose -monochrome -noise 6 '{}'
  #mogrify uses more memory than the convert line above
  #find /tmp/p2pu.org_anon_files/ -iname "*.png" -o -iname "*.jpg" -o -iname "*.gif" | xargs -l -i mogrify -verbose -monochrome -noise 6 {}
}

echo ...
echo Cloning live DB - can take a while
mysqldump -u devel -p$DBPASS d6dev_p2pu --ignore-table=d6dev_p2pu.p2pu_stats_accesslog --ignore-table=d6dev_p2pu.accesslog --ignore-table=d6dev_p2pu.watchdog | mysql -u devel -p$DBPASS p2pu_anon_db
mysqldump -u devel -p$DBPASS d6dev_p2pu --no-data --tables accesslog watchdog p2pu_stats_accesslog | mysql -u devel -p$DBPASS p2pu_anon_db

echo Anonymizing
mysql -u devel -p$DBPASS p2pu_anon_db < /var/www/p2pu/sites/p2pu.org/anonymize.sql 

echo Dumping to /tmp/p2pu_anon_dump.sql
mysqldump -u devel -p$DBPASS p2pu_anon_db > /tmp/p2pu_anon_dump.sql

echo Compressing
zip /tmp/p2pu_anon_dump.sql.zip /tmp/p2pu_anon_dump.sql

echo Copying images ...
rsync -avz --include "*/" --include "*.jpg" --include "*.JPG" --include "*.png" --include "*.gif" --exclude "*" /var/www/p2pu/sites/p2pu.org/files/ /tmp/p2pu.org_anon_files/  

echo Anonymizing images, can take more than 20 minutes ...
anonymize_images

echo Done!

