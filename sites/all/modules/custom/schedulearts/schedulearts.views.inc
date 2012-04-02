<?php

/*
 * Implements hook_views_query_alter
 */

function schedulearts_views_query_alter(&$view, &$query) {
  if ($view->name == 'taxonomy_term_calendar' && $view->current_display == 'page_1') {
    // set TID filters to the user's TIDs
    $url_uid = arg(1);
    $userfields = user_load($url_uid);
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
  if ($view->name == 'taxonomy_term_calendar' && $view->current_display == 'page_2') {
    // set TID filters to the user's TIDs
    krumo($view);
    $url_uid = $view->args[1];
    $userfields = user_load($url_uid);
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
