<?php
// $Id: graphstat_statistics.inc,v 1.2.2.1 2009/01/25 14:32:28 profix898 Exp $

/**
 * Implementation of hook_graphstat().
 */
function graphstat_graphstat() {
  $graphs = graphstat_statistics_history();
  $graphs = array_merge($graphs, graphstat_statistics_nodes());
  $graphs = array_merge($graphs, graphstat_statistics_user_activity());
  // Daily statistics are only available if 'access_log' is enabled
  if (variable_get('statistics_enable_access_log', 0)) {
    $graphs = array_merge($graphs, graphstat_statistics_daily());
  }

  return $graphs;
}

/**
 * Function graphstat_statistics_nodes().
 */
function graphstat_statistics_nodes() {
  $graphs = array();
  
  // Node type distribution
  $node_types = array();
  $node_types_nodes = array('');
  $result = db_query("SELECT type, COUNT(nid) AS nodes FROM {node} WHERE nid <> 0 GROUP BY type ORDER BY nodes DESC", $_SERVER['HTTP_HOST']);
  while ($object = db_fetch_object($result)) {
    $node_types[] = db_result(db_query("SELECT name FROM {node_type} WHERE type = '%s'", $object->type));
    $node_types_nodes[] = $object->nodes;
  }

  // Node details (total, published, queued) of the last two weeks
  $start_date = time() - (60*60*24*14);
  $nodes_details_total = graphstat_statistics_tablehistory('node', 'nid', '', 14, $start_date);
  $nodes_details_published = graphstat_statistics_tablehistory('node', 'nid', ' AND status=1', 14, $start_date);
  $nodes_details_queued = graphstat_statistics_tablehistory('node', 'nid', ' AND moderate=1', 14, $start_date);
  $nodes_details_all = array();
  foreach (array_keys($nodes_details_total) as $date) {
    $nodes_details_all[] = array(
      $date,
      $nodes_details_total[$date],
      $nodes_details_published[$date],
      $nodes_details_queued[$date]
    );
  }

  $graphs['nodes'] = array(
    'title' => t('Nodes'),
    'graph_node_types' => array(
      'type' => 'pie',
      'title' => t('Node Type Distribution'),
      'legend' => $node_types,
      'data' => array($node_types_nodes),
      'description' => t('Number of nodes for each node type.')
    ),
    'graph_nodes_details' => array(
      'type' => 'bars',
      'title' => t('Number of Nodes (last 2 weeks)'),
      'xlabel' => t('Date (MM/DD/YYYY)'),
      'ylabel' => t('# Nodes'),
      'legend' => array(t('total'), t('published'), t('queued')),
      'data' => $nodes_details_all,
      'description' => t('Number of total/published/queued nodes in the last two weeks.')
    )
  );

  return $graphs;
}

/**
 * Function graphstat_statistics_history().
 */
function graphstat_statistics_history() {
  $graphs = array();
  $graphs['history'] = array(
    'title' => t('History'),
    'graph_nodes' => array(
      'title' => t('Number of Nodes'),
      'xlabel' => t('Date (MM/DD/YYYY)'),
      'ylabel' => t('# Nodes'),
      'data' => graphstat_statistics_tablehistory()
    ),
    'graph_users' => array(
      'title' => t('Number of Users'),
      'xlabel' => t('Date (MM/DD/YYYY)'),
      'ylabel' => t('# Users'),
      'data' => graphstat_statistics_tablehistory('users', 'uid')
    )
  );
  
  if (module_exists('comment')) {
    $graphs['history']['graph_comments'] = array(
      'title' => t('Number of Comments'),
      'xlabel' => t('Date (MM/DD/YYYY)'),
      'ylabel' => t('# Comments'),
      'data' => graphstat_statistics_tablehistory('comments', 'cid')
    );
  }

  return $graphs;
}

/**
 * Function graphstat_statistics_user_activity().
 */
function graphstat_statistics_user_activity() {
  $graphs = array();

  // Most active users (page hits)
  if (variable_get('statistics_enable_access_log', 0)) {
    $top_users_hits = array('');
    $top_users_hits_legend = array();
    $result = db_query_range("SELECT uid, COUNT(DISTINCT(url)) AS hits FROM {accesslog} WHERE url <> '' GROUP BY uid ORDER BY hits DESC", $_SERVER['HTTP_HOST'], 0, 10);
    while ($object = db_fetch_object($result)) {
      $top_users_hits_legend[] = graphstat_statistics_uid2username($object->uid);
      $top_users_hits[] = $object->hits;
    }
    $total_hits = max(array_sum($top_users_hits), 1);
    foreach ($top_users_hits as $pos => $hits) {
      $top_users_hits[$pos] = round($hits / $total_hits * 100, 1);
    }
  }

  // Most active users (number of nodes)
  $top_users_nodes = array('');
  $top_users_nodes_legend = array();
  $result = db_query_range("SELECT uid, COUNT(nid) AS nodes FROM {node} WHERE nid <> 0 GROUP BY uid ORDER BY nodes DESC", $_SERVER['HTTP_HOST'], 0, 10);
  while ($object = db_fetch_object($result)) {
    $top_users_nodes_legend[] = graphstat_statistics_uid2username($object->uid);
    $top_users_nodes[] = $object->nodes;
  }
  $total_nodes = max(array_sum($top_users_nodes), 1);
  foreach ($top_users_nodes as $pos => $nodes) {
    $top_users_nodes[$pos] = round($nodes / $total_nodes * 100, 1);
  }
  
  $graphs['activity'] = array(
    'title' => t('User Activity'),
    'graph_user_hits' => array(
      'type' => 'pie',
      'title' => t('Most active users (page hits)'),
      'legend' => isset($top_users_hits_legend) ? $top_users_hits_legend : NULL,
      'data' => isset($top_users_hits) ? array($top_users_hits) : NULL
    ),
    'graph_user_nodes' => array(
      'type' => 'pie',
      'title' => t('Most active users (number of nodes)'),
      'legend' => $top_users_nodes_legend,
      'data' => array($top_users_nodes)
    )
  );

  // Most active users (number of comments)
  if (module_exists('comment')) {
    $top_users_comments = array('');
    $top_users_comments_legend = array();
    $result = db_query_range("SELECT uid, COUNT(cid) AS comments FROM {comments} WHERE cid <> 0 GROUP BY uid ORDER BY comments DESC", $_SERVER['HTTP_HOST'], 0, 10);
    while ($object = db_fetch_object($result)) {
      $top_users_comments_legend[] = graphstat_statistics_uid2username($object->uid);
      $top_users_comments[] = $object->comments;
    }
    $total_comments = max(array_sum($top_users_comments), 1);
    foreach ($top_users_comments as $pos => $comments) {
      $top_users_comments[$pos] = round($comments / $total_comments * 100, 1);
    }
    
    $graphs['activity']['graph_user_comments'] = array(
      'type' => 'pie',
      'title' => t('Most active users (number of comments)'),
      'legend' => $top_users_comments_legend,
      'data' => (count($top_users_comments) > 1) ? array($top_users_comments) : NULL
    );
  }

  return $graphs;
}

/**
 * Function graphstat_statistics_daily().
 */
function graphstat_statistics_daily() {
  global $user;
  if (variable_get('configurable_timezones', 1) && $user->uid && strlen($user->timezone)) {
    $timezone = $user->timezone;
  }
  else {
    $timezone = variable_get('date_default_timezone', 0);
  }
  // Get oldest record and current date
  $min = db_result(db_query('SELECT MIN(timestamp) FROM {accesslog}'));
  if ($min) {
    $now = time();
    // Figure out which local dates correspond with these timestamps - can be different between timezones
    $min_date = format_date($min, 'custom', 'm/d/Y');
    $now_date = format_date($now, 'custom', 'm/d/Y');
    // Figure out the (UNIX Epoch) timestamp that corresponds to when the first day began locally
    // Figure out the (UNIX Epoch) timestamp that corresponds to when today ends locally
    $min_date_frag = explode('/', $min_date);
    $now_date_frag = explode('/', $now_date);
    $gm_timestamp_min = gmmktime(0, 0, 0, $min_date_frag[0], $min_date_frag[1], $min_date_frag[2]);
    $gm_timestamp_now = gmmktime(23, 59, 59, $now_date_frag[0], $now_date_frag[1], $now_date_frag[2]);
    if ($timezone > 0) {
      $local_timestamp_min = $gm_timestamp_min - $timezone;
      $local_timestamp_now = $gm_timestamp_now - $timezone;
    }
    elseif ($timezone < 0) {
      $local_timestamp_min = $gm_timestamp_min + abs($timezone);
      $local_timestamp_now = $gm_timestamp_now + abs($timezone);
    }
    else {
      $local_timestamp_min = $gm_timestamp_min;
      $local_timestamp_now = $gm_timestamp_now;
    }
    // Build the filter options array with all dates
    $options = array('<'. t('Select a date') .'>');
    while ($local_timestamp_min < $local_timestamp_now) {
      $options[$local_timestamp_min] = format_date($local_timestamp_min, 'custom', 'm/d/Y');
      $local_timestamp_min = $local_timestamp_min + 86400;
    }
  }
  else {
    $options = array(NULL => t('No items available'));
  }
  
  $graphs = array();
  $graphs['daily'] = array(
    'title' => t('Daily'),
    'filter' => array(
      'options' => $options,
      'callback' => 'graphstat_statistics_daily_filter'
    ),
    // The empty data arrays will be filled in the filter callback
    'graph_page_generation' => array(
      'title' => t('Average page generation time'),
      'xlabel' => t('Time (hh:mm)'),
      'ylabel' => t('Page generation / ms'),
      'legend' => array(t('avg'), t('avg + stddev'), t('avg - stddev')),
      'data' => array(),
      'description' => t('Average (avg) page generation time +/- standard deviation (stddev).')
    ),
    'graph_pages' => array(
      'title' => t('Number of pages served (total)'),
      'xlabel' => t('Time (hh:mm)'),
      'ylabel' => t('# Pages'),
      'data' => array()
    ),
    'graph_unique_pages' => array(
      'title' => t('Number of unique pages served'),
      'xlabel' => t('Time (hh:mm)'),
      'ylabel' => t('# Pages'),
      'data' => array()
    ),
    'graph_visitors' => array(
      'title' => t('Number of unique visitors'),
      'xlabel' => t('Time (hh:mm)'),
      'ylabel' => t('# Visitors'),
      'data' => array()
    )
  );
  
  return $graphs;
}

/**
 * Function graphstat_statistics_daily_filter().
 */
function graphstat_statistics_daily_filter(&$graphs, $start) {
  if (!$start) {
    return;
  }
  $stop = $start + 86400;
  // Average page generation time
  $loop = $start;
  while ($loop < $stop) {
    $stats = db_fetch_object(db_query('SELECT AVG(timer) AS avg, STDDEV(timer) AS dev FROM {accesslog} WHERE timestamp > %d AND timestamp <= %d', $loop, $loop + 3600));
    $avg = $stats->avg ? round($stats->avg , 0) : 0;
    $dev = $stats->dev ? round($stats->dev, 0) : 0;
    $graphs['graph_page_generation']['data'][] = array(format_date($loop, 'custom', 'H:i'), $avg, $avg + $dev, max($avg - $dev, 0));
    $loop += 3600;
  }
  // Number of pages served (total)
  $loop = $start;
  while ($loop < $stop) {
    $stats = db_fetch_object(db_query('SELECT COUNT(aid) AS count FROM {accesslog} WHERE timestamp > %d AND timestamp <= %d', $loop, $loop + 3600));
    $graphs['graph_pages']['data'][format_date($loop, 'custom', 'H:i')] = $stats->count ? $stats->count : 0;
    $loop += 3600;
  }
  // Number of unique pages served
  $loop = $start;
  while ($loop < $stop) {
    $stats = db_fetch_object(db_query('SELECT COUNT(DISTINCT(path)) AS count FROM {accesslog} WHERE timestamp > %d AND timestamp <= %d', $loop, $loop + 3600));
    $graphs['graph_unique_pages']['data'][format_date($loop, 'custom', 'H:i')] = $stats->count ? $stats->count : 0;
    $loop += 3600;
  }
  // Number of unique visitors
  $loop = $start;
  while ($loop < $stop) {
    $stats = db_fetch_object(db_query('SELECT COUNT(DISTINCT(hostname)) AS count FROM {accesslog} WHERE timestamp > %d AND timestamp <= %d', $loop, $loop + 3600));
    $graphs['graph_visitors']['data'][format_date($loop, 'custom', 'H:i')] = $stats->count ? $stats->count : 0;
    $loop += 3600;
  }
}

/**
 * Function graphstat_statistics_tablehistory().
 */
function graphstat_statistics_tablehistory($table = 'node', $id = 'nid', $qfragment = '', $points = 0, $timestamp = 0) {
  $data = array();
  
  $key = in_array($table, array('node', 'users')) ? 'created' : 'timestamp';
  $timestamp = $timestamp ? $timestamp : db_result(db_query('SELECT MIN(%s) FROM {%s} WHERE %s != 0', $key, $table, $id));
  if ($timestamp) {
    // one point per week (at least 15 points)
    if (!$points) {
      $points = max((time() - $timestamp) / (60*60*24*7), 15);
      while ($points > 30) {
        $points /= 2;
      }
    }
    $interval = round((time() - $timestamp) / ($points - 1), 0);
    $time = $timestamp;
    for ($i = 0; $i < $points; $i++) {
      $data[format_date($time, 'custom', 'm/d/Y')] = db_result(db_query('SELECT COUNT(DISTINCT(%s)) FROM {%s} WHERE %s <= %d AND %s != 0 %s', $id, $table, $key, $time, $id, $qfragment));
      $time += $interval;
    }
  }

  return $data;
}

/**
 * Function graphstat_statistics_uid2username().
 */
function graphstat_statistics_uid2username($uid) {
  if ($uid) {
    $user = user_load(array('uid' => $uid));
    return $user->name;
  }
  else {
    return variable_get('anonymous', t('anonymous'));
  }
}
