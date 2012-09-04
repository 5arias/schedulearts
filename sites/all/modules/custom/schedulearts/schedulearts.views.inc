<?php

/*
 * Implements hook_views_query_alter
 */

function schedulearts_views_query_alter(&$view, &$query) {
  if ($view->name == 'taxonomy_term_calendar' && $view->current_display == 'page_1') {
    // set TID filters to the user's TIDs
    $url_uid = arg(1);
    $userfields = user_load($url_uid);
    if (isset($userfields->field_user_groups['und'])) {
      $ugroups = $userfields->field_user_groups['und'];
      foreach ($ugroups as $ugroup) {
          $ugroups_array[$ugroup['tid']] = $ugroup['tid'];
      }
      foreach ($query->where as &$condition_group) {
        foreach ($condition_group['conditions'] as &$condition) {
          if ($condition['field'] == 'field_data_field_event_groups_tax.field_event_groups_tax_tid') {
            $condition['value'] = $ugroups_array;
          }
          // set UID filter to the user's UID
          if ($condition['field'] == 'field_data_field_event_individuals.field_event_individuals_target_id') {
            $condition['value']['0'] = $url_uid;
          }
        }
      }
    }
  }
  if ($view->name == 'taxonomy_term_calendar' && $view->current_display == 'page_2') {
    // set TID filters to the user's TIDs
    $url_uid = $view->args[1];
    $userfields = user_load($url_uid);
    $ugroups = $userfields->field_user_groups['und'];
    $daterange = $view->args[0];
    foreach ($ugroups as $ugroup) {
        $ugroups_array[$ugroup['tid']] = $ugroup['tid'];
    }
    foreach ($query->where as &$condition_group) {
      foreach ($condition_group['conditions'] as &$condition) {
        if ($condition['field'] == 'field_data_field_event_groups_tax.field_event_groups_tax_tid') {
          $condition['value'] = $ugroups_array;
        }
        // set UID filter to the user's UID
        if ($condition['field'] == 'field_data_field_event_individuals.field_event_individuals_target_id') {
          $condition['value']['0'] = $url_uid;
        }
        // Set date range filter from argument
        if ($condition['field'] == 'DATE_FORMAT(field_data_field_event_date.field_event_date_value, \'%Y-%m-%d\') >= :node_date_filter AND DATE_FORMAT(field_data_field_event_date.field_event_date_value, \'%Y-%m-%d\') <= :node_date_filter1' && $view->args[0] !== 'none') {
          $condition['value'][':node_date_filter'] = $daterange['value'];
          $condition['value'][':node_date_filter1'] = $daterange['value2'];
        }
      }
    }
  }
}

/*
 * hook_views_pre_render(&$view)
 */
function schedulearts_views_pre_render(&$view) {
//  dpm($view);
  if ($view->name == 'events_schedule') {
    // events type - id: 450, meeting; 70, performance.
    foreach ($view->result as $key => $fields) {
      $event_type_tids[$key] = $fields->field_field_event_type['0']['raw']['tid'];
    }
    //dpm($event_type_tids);

    // type based function calls
    foreach ($event_type_tids as $key => $tid) {
      switch ($tid) {
        case '450':
          display_meeting_rows($key, $view->result);
          break;
        case '70':
          display_performance_rows($key, $view->result);
          break;
        default:
          display_default_rows($key, $view->result);
      }
    }
  }
}

// all calls are displayed in the same format. Start and end times are always displayed.
 function display_meeting_rows($key, $data) {
  //dpm($datas);
}

// all calls are displayed in the same format. Only the start time is displayed, the end time is never displayed.
function display_performance_rows($key, $data) {
  //dpm($datas);
  $timestamp = strtotime($data[$key]->field_field_event_date['0']['raw']['value']);
  $time = date('h:ia', $timestamp);
  $output = '<span class="date-display-single"><span class="date-display-start" property="dc:date" datatype="xsd:dateTime" content="'
            . $data[$key]->field_field_event_date['0']['raw']['value'] . '">' . $time . '</span></span>';
  $data[$key]->field_field_event_date['0']['rendered']['#markup'] = $output;
}

// Start and End times should be on separate rows of the table.
// If the call start time parent event start time, do not display the start time row.
// If the call end time parent event end time, do not display the end time row.
// On call start rows, the users/groups called should be prefixed with "ADD: "
// On call end rows, the users/groups called should be prefixed with "REL: "
// If a call has the same start AND end times as the parent event, it should be displayed in a single row with no time listed.
function display_default_rows($key, $data) {
  //dpm(func_get_args());
  $called = array();
  if (isset($data[$key]->field_field_event_individuals['0']['rendered']['#markup'])) {
    foreach ($data[$key]->field_field_event_individuals as $values) {
      $called[] = $values['rendered']['#markup'];
    }
  }
  dpm($called);
  $event_start = $data[$key]->field_field_event_date_1['0']['raw']['value'];
  $event_end = $data[$key]->field_field_event_date_1['0']['raw']['value2'];
  $call_start = $data[$key]->field_field_event_date['0']['raw']['value'];
  $call_end = $data[$key]->field_field_event_date['0']['raw']['value2'];

  if ($call_start == $event_start) {
    $data[$key]->field_field_event_date['0']['rendered']['#markup'] = '';
    $data[$key]->field_field_event_individuals['0']['rendered']['#markup'] = $data[$key]->field_body['0']['rendered']['#markup'];
    $data[$key]->field_field_event_individuals['0']['rendered']['#markup'] .= '<br />' . implode(', ', $called);
  }
  else {
    $timestamp = strtotime($call_start);
    $time = date('h:ia', $timestamp);
    $output = '<span class="date-display-single"><span class="date-display-start">' . $time . '</span></span>';
    $data[$key]->field_field_event_date['0']['rendered']['#markup'] = $output;

    $data[$key]->field_field_event_individuals['0']['rendered']['#markup'] .= '<br />ADD: ' . implode(', ', $called);

  }
  if ($call_end < $event_end) {
    $timestamp = strtotime($call_end);
    $time = date('h:ia', $timestamp);
    $output = '<span class="date-display-single"><span class="date-display-end">' . $time . '</span></span>';
    $data[$key]->field_field_event_date['0']['rendered']['#markup'] = $output;

    $data[$key]->field_field_event_individuals['0']['rendered']['#markup'] .= '<br />REL: ' . implode(', ', $called);

  }

}
