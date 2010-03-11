<?php
// $Id: statspro_date.inc,v 1.1 2008/12/31 19:53:29 mr3dblond Exp $

/**
 * @file
 *   Date functions for statistics pro module
 *
 */

function statspro_from_timestamp($timestamp) {
  $date = format_date($timestamp, 'custom', statspro_date_format());
  return $date;
}

function statspro_date_format() {

  $format = variable_get('date_format_short', 'm/d/Y - H:i');
  $date = strtok($format, '-');

  return trim($date);
}

function statspro_get_stamp($date) {

  $ftime = strptime($date, '%Y-%m-%d %H:%M:%S');

  $stamp = mktime(
                    $ftime['tm_hour'],
                    $ftime['tm_min'],
                    $ftime['tm_sec'],
                    1,
                    $ftime['tm_yday'] + 1,
                    $ftime['tm_year'] + 1900);

  return $stamp;
}

/**
 * Parse a time/date generated with strftime().
 *
 * This function is the same as the original one defined by PHP (Linux/Unix only),
 *  but now you can use it on Windows too.
 *  Limitation : Only this format can be parsed %S, %M, %H, %d, %m, %Y
 *
 * @author Lionel SAURON
 * @version 1.0
 * @public
 *
 * @param $s_date(string)    The string to parse (e.g. returned from strftime()).
 * @param $s_format(string)  The format used in date  (e.g. the same as used in strftime()).
 * @return (array)          Returns an array with the <code>$s_date</code> parsed, or <code>false</code> on error.
 */
if (function_exists("strptime") == FALSE) {
    function strptime($s_date, $s_format) {
        $a_result = array(
            'tm_sec'   => 0,
            'tm_min'   => 0,
            'tm_hour'  => 0,
            'tm_mday'  => 1,
            'tm_mon'   => 0,
            'tm_year'  => 0,
            'tm_wday'  => 0,
            'tm_yday'  => 0,
            'unparsed' => $s_date,
        );

        while ($s_format != '') {
            // ===== Search a %x element, Check the static string before the %x =====
            $n_idx_found = strpos($s_format, '%');
            if ($n_idx_found === FALSE) {

                // There is no more format. Check the last static string.
                $a_result['unparsed'] = ($s_format == $s_date) ? "" : $s_date;
                break;
            }

            $s_format_before = drupal_substr($s_format, 0, $n_idx_found);
            $s_date_before   = drupal_substr($s_date,   0, $n_idx_found);

            if ($s_format_before != $s_date_before) break;

            // ===== Read the value of the %x found =====
            $s_format = drupal_substr($s_format, $n_idx_found);
            $s_date   = drupal_substr($s_date,   $n_idx_found);

            $a_result['unparsed'] = $s_date;

            $s_format_current = drupal_substr($s_format, 0, 2);
            $s_format_after   = drupal_substr($s_format, 2);

            $n_value = -1;
            $s_date_after = "";
            switch ($s_format_current) {
                case '%S': // Seconds after the minute (0-59)

                    sscanf($s_date, "%2d%[^\\n]", $n_value, $s_date_after);

                    if (($n_value < 0) || ($n_value > 59)) return FALSE;

                    $a_result['tm_sec']  = $n_value;
                    break;

                // ----------
                case '%M': // Minutes after the hour (0-59)
                    sscanf($s_date, "%2d%[^\\n]", $n_value, $s_date_after);

                    if (($n_value < 0) || ($n_value > 59)) return FALSE;

                    $a_result['tm_min']  = $n_value;
                    break;

                // ----------
                case '%H': // Hour since midnight (0-23)
                    sscanf($s_date, "%2d%[^\\n]", $n_value, $s_date_after);

                    if (($n_value < 0) || ($n_value > 23)) return FALSE;

                    $a_result['tm_hour']  = $n_value;
                    break;

                // ----------
                case '%d': // Day of the month (1-31)
                    sscanf($s_date, "%2d%[^\\n]", $n_value, $s_date_after);

                    if (($n_value < 1) || ($n_value > 31)) return FALSE;

                    $a_result['tm_mday']  = $n_value;
                    break;

                // ----------
                case '%m': // Months since January (0-11)
                    sscanf($s_date, "%2d%[^\\n]", $n_value, $s_date_after);

                    if (($n_value < 1) || ($n_value > 12)) return FALSE;

                    $a_result['tm_mon']  = ($n_value - 1);
                    break;

                // ----------
                case '%Y': // Years since 1900
                    sscanf($s_date, "%4d%[^\\n]", $n_value, $s_date_after);

                    if ($n_value < 1900) return FALSE;

                    $a_result['tm_year']  = ($n_value - 1900);
                    break;

                // ----------
                default: break 2; // Break Switch and while
            }

            // ===== Next please =====
            $s_format = $s_format_after;
            $s_date   = $s_date_after;

            $a_result['unparsed'] = $s_date;

        } // END while($s_format != "")


        // ===== Create the other value of the result array =====
        $n_parsed_date_timestamp = mktime($a_result['tm_hour'], $a_result['tm_min'], $a_result['tm_sec'],
                                $a_result['tm_mon'] + 1, $a_result['tm_mday'], $a_result['tm_year'] + 1900);

        // Before PHP 5.1 return -1 when error
        if (($n_parsed_date_timestamp === FALSE)
        ||($n_parsed_date_timestamp === -1)) return FALSE;

        $a_result['tm_wday'] = (int) strftime("%w", $n_parsed_date_timestamp); // Days since Sunday (0-6)
        $a_result['tm_yday'] = (strftime("%j", $n_parsed_date_timestamp) - 1); // Days since January 1 (0-365)

        return $a_result;
    } // END of function

} // END if(function_exists("strptime") == false)
