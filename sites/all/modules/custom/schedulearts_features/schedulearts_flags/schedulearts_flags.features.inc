<?php
/**
 * @file
 * schedulearts_flags.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function schedulearts_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Conflict Approved".
  $flags['conflict_approved'] = array(
    'content_type' => 'node',
    'title' => 'Conflict Approved',
    'global' => '1',
    'types' => array(
      0 => 'conflict',
    ),
    'flag_short' => 'Approve',
    'flag_long' => '',
    'flag_message' => 'Conflict Approved',
    'unflag_short' => 'Unapprove this conflict',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Conflict approved',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => '4',
        1 => '3',
      ),
      'unflag' => array(
        0 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'schedulearts_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Postpone Conflict".
  $flags['conflict_postponed'] = array(
    'content_type' => 'node',
    'title' => 'Postpone Conflict',
    'global' => '1',
    'types' => array(
      0 => 'conflict',
    ),
    'flag_short' => 'Postpone',
    'flag_long' => 'Postpone this conflict for 2 hours',
    'flag_message' => 'Conflict postponed',
    'unflag_short' => 'Unpostpone',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Conflict postponed',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => '4',
        1 => '3',
      ),
      'unflag' => array(
        0 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'schedulearts_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Hard conflict".
  $flags['hard_conflict'] = array(
    'content_type' => 'node',
    'title' => 'Hard conflict',
    'global' => '1',
    'types' => array(
      0 => 'conflict',
    ),
    'flag_short' => 'Hard conflict',
    'flag_long' => '',
    'flag_message' => 'Hard conflict',
    'unflag_short' => 'Remove hard conflict',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Remove hard conflict',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => '4',
        1 => '3',
      ),
      'unflag' => array(
        0 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'schedulearts_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Schedule Approved".
  $flags['schedule_approved'] = array(
    'content_type' => 'node',
    'title' => 'Schedule Approved',
    'global' => '1',
    'types' => array(
      0 => 'schedule',
    ),
    'flag_short' => 'Approve and send this schedule',
    'flag_long' => '',
    'flag_message' => 'Schedule sent!',
    'unflag_short' => 'Revoke this schedule',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Email sent!',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => '4',
        1 => '3',
      ),
      'unflag' => array(),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'schedulearts_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
