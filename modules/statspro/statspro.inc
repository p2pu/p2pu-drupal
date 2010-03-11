<?php
// $Id: statspro.inc,v 1.3 2009/04/19 10:15:13 mr3dblond Exp $

/**
 * @file
 *   User defined functions for statistics pro module
 *
 */

class statspro {

  private $start_date;
  private $end_date;
  private $period;

  private $last_run;
  private $current_field;
  protected $fields;

  public $absolute_amounts = array('pi', 'upi', 'error', 'uerror', 'warning', 'uwarning');

  /*
   * Day results
   *
   */
  private $days;

  function __construct() {
    $this->set_fields();
  }

  /**
   * Set all available data field to member variable
   *
   */
  private function set_fields() {

    $this->fields = array(  'nuser'     => user_access('administer users')? l(t('User registrations'), 'admin/user/user') : t('User registrations'),
                            'auser'     => t('User online'),
                            'nnode'     => user_access('administer nodes')? l(t('New nodes'), 'admin/content/node') : t('New nodes'),
                            'cnode'     => user_access('administer nodes')? l(t('Changed nodes'), 'admin/content/node') : t('Changed nodes'),
                            'comment'   => user_access('administer comments')? l(t('Comments'), 'admin/content/comment') : t('Comments'),
                            'pi'        => l(t('Page impressions'), 'admin/reports/hits'),
                            'upi'       => l(t('Page impressions, users'), 'admin/reports/hits'),
                            'error'     => user_access('access site reports')? l(t('Errors'), 'admin/reports/dblog') : t('Errors'),
                            'uerror'    => user_access('access site reports')? l(t('Errors, users'), 'admin/reports/dblog') : t('Errors, users'),
                            'warning'   => user_access('access site reports')? l(t('Warnings'), 'admin/reports/dblog') : t('Warnings'),
                            'uwarning'  => user_access('access site reports')? l(t('Warnings, users'), 'admin/reports/dblog') : t('Warnings, users'),
                          );
  }

  /**
   * Get data fields
   *
   */
  public function get_fields() {
    return $this->fields;
  }

  private function get_calc_fields($whitelist, $blacklist) {

    if ((is_array($whitelist)) && (is_array($blacklist))) {
      die('whitelist and blacklist cannot be used togther.');
    }
    else if (is_array($whitelist)) {
      $fields = array();
      foreach ($this->fields AS $field => $desc) {
        if (in_array($field, $whitelist)) {
          $fields[$field] = $desc;
        }
      }
    }
    else if (is_array($blacklist)) {
      $fields = array();
      foreach ($this->fields AS $field => $desc) {
        if (!in_array($field, $blacklist)) {
          $fields[$field] = $desc;
        }
      }
    }
    else {

      // all fields
      $fields = $this->fields;
    }

    return $fields;
  }

  public function get_aggregate_stat($mode) {

    $rc = FALSE;

    if (in_array($mode, $this->absolute_amounts)) {
      $rc = array('subject' => strip_tags($this->fields[$mode]),
                  'amount'  => db_result(db_query("SELECT SUM(%s) FROM {statspro}", $mode)));
    }
    else if ($mode=='users') {
      $rc = array('subject' => t('Amount of users'),
                  'amount'  => db_result(db_query("SELECT COUNT(*) FROM {users}")));
    }
    else if ($mode=='terms') {
      $rc = array('subject' => t('Terms'),
                  'amount'  => $this->generate_term_stats());
    }
    else if ($mode=='nodes') {
      $rc = array('subject' => t('Amount of nodes'),
                  'amount'  => db_result(db_query("SELECT COUNT(*) FROM {node} WHERE status=1")));
    }
    else if ($mode=='node_types') {
      $rc = array('subject' => t('Amount of node types'),
                  'amount'  => db_result(db_query("SELECT COUNT(*) FROM {node_type}")));
    }
    else if ($mode=='comments') {
      $rc = array('subject' => t('Amount of comments'),
                  'amount'  => db_result(db_query("SELECT COUNT(*) FROM {comments}")));
    }
    else if ($mode=='aliases') {
      $rc = array('subject' => t('Amount of aliases'),
                  'amount'  => db_result(db_query("SELECT COUNT(*) FROM {url_alias}")));
    }
    else if ($mode=='sessions') {
      $rc = array('subject' => t('Amount of sessions'),
                  'amount'  => db_result(db_query("SELECT COUNT(*) FROM {sessions}")));
    }
    else if ($mode=='modules') {
      $modules = module_rebuild_cache();
      $amount = 0;
      foreach ($modules AS $values) {
        if ($values->status) {
          $amount++;
        }
      }

      $rc = array('subject' => t('Amount of modules'),
                  'amount'  => $amount);
    }

    return $rc;
  }

  /**
   *
   * Get statictics for output
   *
   */
  public function get_stats($period='today', $start_date, $end_date, $whitelist=NULL, $blacklist=NULL) {

    $this->period     = $period;
    $this->start_date = $start_date;
    $this->end_date   = $end_date;

    $with_data = FALSE;

    // build field list
    $fields = $this->get_calc_fields($whitelist, $blacklist);

    // initialize values
    $data = array();

    foreach ($fields AS $field => $desc) {
      $data[$field] = 0;
    }

    // get values
    $sql = 'SELECT * FROM {statspro} WHERE '. $this->get_period();
    $result = db_query($sql);
    while ($row = db_fetch_array($result)) {
      foreach ($fields AS $field => $desc) {
        $data[$field] += $row[$field];

        if ((!$with_data) && ($row[$field]>0)) {
          $with_data = TRUE;
        }
      }
    }

    if ($with_data) {
      // prepare return array
      $rows = array();
      foreach ($fields AS $field => $desc) {
        $rows[] = array($desc, $data[$field]);
      }
      return $rows;
    }
  }

  // not in use at the moment
  private function generate_results() {

    $sql = 'SELECT *, DATE(FROM_UNIXTIME(day)) AS day FROM {statspro} WHERE '. $this->get_period();

    drupal_set_message($sql);

    $result = db_query($sql);

    $row = db_fetch_array($result);

    if (is_array($row)) $this->results = $row;
    else                $this->results = array();
  }

  /**
   *
   * Generatte SQL fragment for period query
   *
   */
  private function get_period() {

    switch ($this->period) {

      case 'yesterday':

        return 'DATE(FROM_UNIXTIME(day)) = CURDATE()-1 ';
        break;

      case 'week_current':

        return 'WEEKOFYEAR(DATE(FROM_UNIXTIME(day))) = WEEKOFYEAR(CURDATE()) AND YEAR(DATE(FROM_UNIXTIME(day)))=YEAR(CURDATE())';
        break;

      case 'week_last':

        return 'DATE(FROM_UNIXTIME(day)) >= CURDATE()-WEEKDAY(CURDATE())-7 AND DATE(FROM_UNIXTIME(day)) <= CURDATE()-WEEKDAY(CURDATE())-1';
        break;

      case 'week_last2':

        return 'DATE(FROM_UNIXTIME(day)) >= CURDATE()-WEEKDAY(CURDATE())-14 AND DATE(FROM_UNIXTIME(day)) <= CURDATE()-WEEKDAY(CURDATE())-8';
        break;

      case 'month_current':

        return 'MONTH(DATE(FROM_UNIXTIME(day)))=MONTH(CURDATE()) AND YEAR(DATE(FROM_UNIXTIME(day)))=YEAR(CURDATE())';
        break;

      case 'month_last':

        return 'PERIOD_DIFF(EXTRACT(YEAR_MONTH FROM CURDATE()), EXTRACT(YEAR_MONTH FROM DATE(FROM_UNIXTIME(day))))=1';
        break;

      case 'month_last3':

        return 'PERIOD_DIFF(EXTRACT(YEAR_MONTH FROM CURDATE()), EXTRACT(YEAR_MONTH FROM DATE(FROM_UNIXTIME(day))))<3 AND DATE(FROM_UNIXTIME(day)) <= CURDATE()';
        break;

      case 'month_last6':

        return 'PERIOD_DIFF(EXTRACT(YEAR_MONTH FROM CURDATE()), EXTRACT(YEAR_MONTH FROM DATE(FROM_UNIXTIME(day))))<6 AND DATE(FROM_UNIXTIME(day)) <= CURDATE()';
        break;

      case 'quarter_current':

        return 'QUARTER(DATE(FROM_UNIXTIME(day)))=QUARTER(CURDATE()) AND YEAR(DATE(FROM_UNIXTIME(day)))=YEAR(CURDATE())';
        break;

      case 'quarter_last':

        return 'QUARTER(DATE(FROM_UNIXTIME(day)))=QUARTER(DATE_SUB(CURDATE(), INTERVAL 3 MONTH)) AND YEAR(DATE(FROM_UNIXTIME(day)))=YEAR(DATE_SUB(CURDATE(), INTERVAL 3 MONTH))';
        break;

      case 'year_current':

        return 'YEAR(DATE(FROM_UNIXTIME(day)))=YEAR(CURDATE())';
        break;

      case 'year_last':

        return 'YEAR(DATE(FROM_UNIXTIME(day)))=YEAR(CURDATE())-1';
        break;

      case 'today':

        return 'DATE(FROM_UNIXTIME(day)) = CURDATE()';
        break;

      default:

        return FALSE;
        break;
    }
  }

  /**
   *
   * Get data out of drupal source tables
   *
   */
  public function get_days_data($last_run=0) {

    // set last run
    $this->last_run = $last_run;

    // reset days
    $this->days = array();

    foreach ($this->fields AS $field => $desc) {
      $this->current_field = $field;
      $method = 'get_data_'. $this->current_field;
      $this->$method();
    }

    return $this->days;
  }

  /**
   * Add day data
   *
   * @param string  $date
   * @param int     $amount
   */
  private function add_day_data($date, $amount) {

    if (!empty($date)) {

      $amount = intval($amount);

      if ((isset($this->days[$date][$this->current_field])) &&
        ($this->days[$date][$this->current_field]>0)) {

        $this->days[$date][$this->current_field] +=  $amount;
      }
      else {
        $this->days[$date][$this->current_field] = $amount;
      }
    }
  }

  /**
   *
   * Calculate new users
   *
   */
  private function get_data_nuser() {



    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(created)) AS dategroup
                        FROM {users}
                        WHERE uid>0
                        AND created >=%d
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate access list for users
   *
   */
  private function get_data_auser() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(access)) AS dategroup
                        FROM {users}
                        WHERE uid>0
                        AND access >= %d
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate new created nodes
   *
   */
  private function get_data_nnode() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(created)) AS dategroup
                        FROM {node}
                        WHERE created >=%d
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate changed nodes
   *
   */
  private function get_data_cnode() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(changed)) AS dategroup
                        FROM {node}
                        WHERE changed >=%d
                        AND created<>changed
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
    * Count nodes for terms
    *
    * @return int
    */
  public function generate_term_stats() {

    // get nodes
    db_query('INSERT INTO {statspro_term} (tid, ncount)
                SELECT tid, COUNT(*) AS num
                FROM {term_node}
                GROUP BY tid');

    return db_affected_rows();
  }

  /**
   *
   * Calculate new comments
   *
   */
  private function get_data_comment() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(timestamp)) AS dategroup
                        FROM {comments}
                        WHERE timestamp >=%d
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate page impressions
   *
   */
  private function get_data_pi() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(timestamp)) AS dategroup
                        FROM {accesslog}
                        WHERE timestamp >=%d
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate page impressions
   *
   */
  private function get_data_upi() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(timestamp)) AS dategroup
                        FROM {accesslog}
                        WHERE timestamp >=%d
                        AND uid>0
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate occured warnings
   *
   */
  private function get_data_warning() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(timestamp)) AS dategroup
                        FROM {watchdog}
                        WHERE severity=3
                        AND timestamp >=%d
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate occured warnings
   *
   */
  private function get_data_uwarning() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(timestamp)) AS dategroup
                        FROM {watchdog}
                        WHERE severity=3
                        AND timestamp >=%d
                        AND uid>0
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate occured errors
   *
   */
  private function get_data_error() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(timestamp)) AS dategroup
                        FROM {watchdog}
                        WHERE severity=5
                        AND timestamp >=%d
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   *
   * Calculate occured errors with registered users
   *
   */
  private function get_data_uerror() {

    $result = db_query('SELECT COUNT(*) AS num, DATE(FROM_UNIXTIME(timestamp)) AS dategroup
                        FROM {watchdog}
                        WHERE severity=5
                        AND timestamp >=%d
                        AND uid>0
                        GROUP BY dategroup', $this->last_run);

    while ($row = db_fetch_array($result)) {
      $this->add_day_data($row['dategroup'], $row['num']);
    }
  }

  /**
   * Save day information to database
   *
   * @param string  $date
   * @param array   $values
   */
  public function store_day($date, $values) {

    $found = db_result(db_query("SELECT COUNT(*) FROM {statspro}
                                  WHERE day=UNIX_TIMESTAMP('%s 00:00:00')", $date));

    if ($found) { // update row

      $sql_fields = array();
      $sql_values = array();

      foreach ($this->fields AS $field => $desc) {
        $sql_fields[] = $field .' = '. $field .' + %d';
        $sql_values[] = intval($values[$field]);
      }

      // add date to argument array
      $sql_values[] = $date;

      db_query("UPDATE {statspro} SET
                  ". implode(', ', $sql_fields) ."
                  WHERE day=UNIX_TIMESTAMP('%s 00:00:00')", $sql_values);
    }
    else {        // new row

      $sql_fields = array();
      $sql_values = array($date);
      $sql_vars   = array();
      foreach ($this->fields AS $field => $desc) {
        $sql_fields[] = $field;
        $sql_values[] = intval($values[$field]);
        $sql_vars[]   = '%d';
      }

      db_query("INSERT INTO {statspro}
                  (day, ". implode(',', $sql_fields) .")
                  VALUES(UNIX_TIMESTAMP('%s 00:00:00'), ". implode(', ', $sql_vars) .")",
                  $sql_values);
    }
  }
}
