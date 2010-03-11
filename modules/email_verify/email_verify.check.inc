<?php
// $Id: email_verify.check.inc,v 1.1.2.2 2009/05/20 19:51:17 killes Exp $
/**
 * @file
 * User email check menu callback file for email_verify module.
 */

/**
 * Menu callback; look though the whole user base for invalid emails.
 * Can be very long when hosts timeout.
 */
function email_verify_checkall() {
  $content = "<table>";
  $found = 0;

  $result = db_query('SELECT uid, name, mail FROM {users}');
  while ($row = db_fetch_object($result)) {
    if (email_verify_check($row->mail)) {

      $content .= "<tr><td><a href='?q=user/$row->uid/edit'>". check_plain($row->name) ."</a><td>". check_plain($row->mail);

      if (++$found >= 100) break;
    }
  }

  $content .= "</table>";

  unset($found, $result, $row); // Destroy variables
  print theme("page", $content);
}