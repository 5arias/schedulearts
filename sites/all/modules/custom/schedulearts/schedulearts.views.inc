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
    }
    else {
      // If the user has no groups, set impossible TID '0' for the filter
      $ugroups_array[] = '0';
    } 
    foreach ($query->where as &$condition_group) {
      foreach ($condition_group['conditions'] as &$condition) {
        if ($condition['field'] == 'field_data_field_event_groups_tax.field_event_groups_tax_tid') {
          $condition['value'] = $ugroups_array;
          $condition['operator'] = 'IN';
        }
        // set UID filter to the user's UID
        if ($condition['field'] == 'field_data_field_event_individuals.field_event_individuals_target_id') {
          $condition['value']['0'] = $url_uid;
        }
      }
    }
  }
  if ($view->name == 'taxonomy_term_calendar' && $view->current_display == 'page_2') {
    $daterange = $view->args[0]; // Date is argument 0
    $url_uid = $view->args[1]; // UID is argument 1
    // Set TID filters to the user's TIDs
    $userfields = user_load($url_uid);
    if (isset($userfields->field_user_groups['und'])) {
      $ugroups = $userfields->field_user_groups['und']; 
      foreach ($ugroups as $ugroup) {
        $ugroups_array[$ugroup['tid']] = $ugroup['tid'];
      }
    }
    else {
      // If the user has no groups, set impossible TID '0' for the filter
      $ugroups_array[] = '0';
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
