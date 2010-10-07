#!/bin/bash 

read -s -p "Enter the MySQL password : " DBPASS 

echo ...
echo Cloning live DB - can take a while
mysqldump -u devel -p$DBPASS d6dev_p2pu --ignore-table=d6dev_p2pu.p2pu_stats_accesslog --ignore-table=d6dev_p2pu.accesslog --ignore-table=d6dev_p2pu.watchdog | mysql -u devel -p$DBPASS p2pu_anon_db
mysqldump -u devel -p$DBPASS d6dev_p2pu --no-data --tables accesslog watchdog p2pu_stats_accesslog | mysql -u devel -p$DBPASS p2pu_anon_db

echo Anonymizing
mysql -u devel -p$DBPASS p2pu_anon_db < /var/www/p2pu/sites/p2pu.org/anonymize.sql 

echo Dumping to /tmp/p2pu_anon_dump.sql
mysqldump -u devel -p$DBPASS d6dev_p2pu > /tmp/p2pu_anon_dump.sql

echo Compressing
zip /tmp/p2pu_anon_dump.sql.zip /tmp/p2pu_anon_dump.sql

echo Done!
