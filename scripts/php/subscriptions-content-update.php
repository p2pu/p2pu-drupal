<?php
// TO run this you need to call it from the full multisite path, e.g.
// http://testing.p2pu.org/sites/testing.p2pu.org/scripts/php/subscriptions-content-update.php

chdir('../../../../');
require_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Set up some default variables
$content_types = array('announcement', 'assignment', 'discussion', 'document');

$result = db_query("SELECT u.uid, u.name, u.status FROM {users} u 
WHERE u.status = 1 AND u.uid <> 0 
ORDER BY u.name ASC");
while ($u = db_fetch_object($result)) {
  $items[] = $u;
}
foreach ($items as $item) {
  $user_link = l($item->name, "http://p2pu.org/user/" . $item->uid);
  print "<h3>User: $user_link </h3>\n\n";
  $user = user_load($item->uid);
  if (!empty($user->og_groups)) {
    foreach($user->og_groups as $group) {
      if ($group['type'] == 'course') {
        print "<strong>" . $group['title'] . "</strong><br />\n";
        // Subscribe the user for each content type
        // We don't have to check for duplicates, as the function notifications_save_subscription
        // will check and performs an update if it's already a subscription
        // * Announcement * Assignment * Discussion * Document
        foreach ($content_types as $type) {
          $subscription = array(
            'type' => 'grouptype',
            'uid' => $user->uid,
            'send_interval' => 0,
            'send_method' => 'phpmailer',
            'fields' => array(
                              'group' => (string) $group[nid],
                              'type' => $type,
                             ),
            );
          // Save the subscription
          //print "Subscription details: \n\n";
          //dprint_r($subscription);
          notifications_save_subscription($subscription);
          print "Subscription saved for content type: $type <br />\n";        
        }
      }
    }
    //print $message;    
  }
  else {
    print "User does not belong to any groups<br />\n";
  }
}