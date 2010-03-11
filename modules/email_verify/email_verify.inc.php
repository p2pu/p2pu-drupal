<?php
// $Id: email_verify.inc.php,v 1.1.2.2 2009/04/11 11:07:12 dbr Exp $
/**
 * @file
 * Check the email for email_verify module.
 */
function _email_verify_check($mail) {
  if (!valid_email_address($mail)) {
    // The address is syntactically incorrect.
    // The problem will be caught by the 'user' module anyway, so we avoid
    // duplicating the error reporting here, just return.
    return;
  }

  // checkdnsrr and getmxrr were added to Windows platform in PHP 5.3 
  // http://www.php.net/checkdnsrr http://www.php.net/manual/en/function.getmxrr.php
  if (stristr(PHP_OS, 'WIN') && PHP_VERSION < 5.3) {
    drupal_set_message(t('Email Verify could not check the address because the server is running on Windows with a version of PHP below 5.3.'), 'warning');
    return;
  }

  $host = substr(strchr($mail, '@'), 1);

  // Let's see if we can find anything about this host in the DNS
  if (!checkdnsrr($host, 'ANY')) {
    return t('Email host %host invalid, please retry.', array('%host' => "$host"));
  }

  // What SMTP servers should we contact?
  $mx_hosts = array();
  if (!getmxrr($host, $mx_hosts)) {
    // When there is no MX record, the host itself should be used
    $mx_hosts[] = $host;
  }

  // Try to connect to one SMTP server
  foreach ($mx_hosts as $smtp) {

    $connect = @fsockopen($smtp, 25, $errno, $errstr, 15);

    if (!$connect) continue;

    if (ereg("^220", $out = fgets($connect, 1024))) {
      // OK, we have a SMTP connection
      break;
    }
    else {
      // The SMTP server probably does not like us
      // (dynamic/residential IP for aol.com for instance)
      // Be on the safe side and accept the address, at least it has a valid
      // domain part...
      watchdog('email_verify', "Could not verify email address at host $host: $out");
      return;
    }
  }

  if (!$connect)
    return t('Email host %host is invalid, please contact us for clarification.', array('%host' => "$host"));

  $from = variable_get('site_mail', ini_get('sendmail_from'));

  // Extract the <...> part if there is one
  if (preg_match('/\<(.*)\>/', $from, $match) > 0) {
    $from = $match[1];
  }

  $localhost = $_SERVER["HTTP_HOST"];
  if (!$localhost) // Happens with HTTP/1.0
    //should be good enough for RFC compliant SMTP servers
    $localhost = 'localhost';

  fputs($connect, "HELO $localhost\r\n");
  $out  = fgets($connect, 1024);
  fputs($connect, "MAIL FROM: <$from>\r\n");
  $from = fgets($connect, 1024);
  fputs($connect, "RCPT TO: <{$mail}>\r\n");
  $to   = fgets($connect, 1024);
  fputs($connect, "QUIT\r\n");
  fclose($connect);

  if (!ereg ("^250", $from)) {
    // Again, something went wrong before we could really test the address,
    // be on the safe side and accept it.
    watchdog('email_verify', "Could not verify email address at host $host: $from");
    return;
  }

  if (
      // This server does not like us
      // (noos.fr behaves like this for instance)
      ereg("(Client host|Helo command) rejected", $to) ||

      // Any 4xx error also means we couldn't really check
      // except 450, which is explcitely a non-existing mailbox:
      // 450 = "Requested mail action not taken: mailbox unavailable"
      ereg("^4", $to) && !ereg("^450", $to)) {

    // In those cases, accept the email, but log a warning
    watchdog('email_verify', "Could not verify email address at host $host: $to");
    return;
  }

  if (!ereg ("^250", $to)) {
    watchdog('email_verify', "Rejected email address: $mail. Reason: $to");
    return t('%mail is invalid, please contact us for clarification.', array('%mail' => "$mail"));
  }

  // Everything OK
  return;
}
