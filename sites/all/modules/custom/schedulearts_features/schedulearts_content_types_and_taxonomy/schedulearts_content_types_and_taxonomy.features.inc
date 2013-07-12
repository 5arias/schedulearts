<?php
/**
 * @file
 * schedulearts_content_types_and_taxonomy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function schedulearts_content_types_and_taxonomy_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function schedulearts_content_types_and_taxonomy_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content to be sent to all members of a Group'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'call' => array(
      'name' => t('Call'),
      'base' => 'node_content',
      'description' => t('Each Event has Calls for each of the groups or individuals that are called.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'conflict' => array(
      'name' => t('Conflict'),
      'base' => 'node_content',
      'description' => t('A conflict between two calls or events. This kind of content should never be created manually'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An item to be placed on the schedule.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => t('A location for events, such as a rehearsal hall.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'master_calendar_event' => array(
      'name' => t('Master Calendar Event'),
      'base' => 'node_content',
      'description' => t('An event for the master calendar. Belongs to a Production, and inherits color from the production.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'production' => array(
      'name' => t('Production'),
      'base' => 'node_content',
      'description' => t('A production is an item for the Master Calendar. It does not appear elsewhere.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'schedule' => array(
      'name' => t('Schedule'),
      'base' => 'node_content',
      'description' => t('Send out a schedule to everyone mentioned'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Set the criteria for this schedule email, including the date range and who the recipients should be. After you save, you will be able to review your selections before actually sending the email.'),
    ),
  );
  return $items;
}
