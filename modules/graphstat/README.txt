// $Id: README.txt,v 1.2.2.1 2007/11/14 22:40:52 profix898 Exp $

*****************************************************************************
                            G R A P H S T A T
*****************************************************************************
Name: graphstat module
Author: Thilo Wawrzik <drupal at profix898 dot de>
Original Author (Drupal 4.7): Dries Knapen
Drupal: 6.0
*****************************************************************************
DESCRIPTION:

Graphstat uses data from the statistics, user, node, and comment
modules to generate statistical graphs.

It uses PHPLOT library (http://www.phplot.com/) to render the
graphs, which is available under GPL License and PHP License.
PHPLOT requires the GD library available with PHP.

*****************************************************************************
INSTALLATION:

1. Place whole graphstat folder into your Drupal modules/ directory.

2. Enable the graphstat module by navigating to
     Administer > Site Building > Modules (admin/build/modules)
     
3. View the graphs at
    Administer > Reports > Graphs (admin/reports/graphs)

*****************************************************************************
API:

Graphstat provides an easy way to add additional graphs and graph
groups/pages. It introduces the new hook_graphstat() which takes a
simple data structure specifying all graph parameters.

The following function is a commented sample implementation of
hook_graphstat():

function mymodule_graphstat() {
  $graphs = array();
  $graphs['sample'] = array(
    // Title of the graph group/page
    'title' => t('Sample Graphs'),
    // Content added above the graphs on the page (optional)
    'pre' => t('Pre graphs comment'),
    // Content added below the graphs on the page (optional)
    'post' => t('Post graphs comment'),
    // Filter definition (optional)
    'filter' => array(
      // Array containing all possible filter options
      'options' => array('keyA' => 'optionA', ...),
      // A callback function invoked when the user changes
      // the filter settings. (see below for details)
      'callback' => 'filter_callback'
    ),
    // The first sample graph
    'graph_sample1' => array(
      // Plot style of this graph (optional)
      // possible values:  bars, lines, linepoints (default), area,
      //                   points, pie, thinbarline, squared
      'type' => 'bars',
      // Title of this graph
      'title' => t('Graph Daily 1'),
      // Label on the X-Axis
      'xlabel' => t('X Label'),
      // Label on the Y-Axis
      'ylabel' => t('Y Label'),
      // Legend for pie/bars plots (optional)
      'legend' => array(t('dataA'), t('dataB')),
      // Array containing the data points
      // possible formats:  1. array('x1' => 'y1', ...)
      //                    2. array(array('x1', 'y1'), ...)
      //                    3. array(array('x1', 'y1', 'y2'), ...)
      'data' => array('x1' => 'y1', 'x2' => 'y2'),
      // Description for this graph (optional)
      'description' => t('description for the graph')
    ),
    // The second sample graph
    'graph_sample2' => array(
      ...
    )
  );
  
  return $graphs;
}

In case the structure returned in hook_graphstat() defines a filter
the filter callback function is invoked everytime the user chooses
a different filter option from the filter dropdown.
Two parameters are passed into the callback function:
 1. The $graphs structure (by reference)
 2. The selected filter option (e.g. 'keyA', ...)
The callback function modifies the $graphs structure based on the
selected $filter option. For example it replaces the 'data' field
with a data array matching the filter option. But it can also alter
the labels, plot style, etc. of the graphs.

function filter_callback(&$graphs, $filter) {
  $graph['graph_sample1'] = array( ... );
  $graph['graph_sample2']['data'] = array( ... );
}

You may also take a look at graphstat_statistics.inc for some
sample functions, e.g. graphstat_statistics_nodes().
Function graphstat_statistics_daily() additionally shows the use of
filters, where graphstat_statistics_daily_filter() is the filter
callback.

*****************************************************************************
Have fun with graphstat, Thilo.
