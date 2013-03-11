<?php

/**
 * @file
 * Administration functions for schedulearts_undeletables
 */

/**
 * Admin settings form
 */
function schedulearts_undeletables_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Undeletables'),
  );
  
  //Build the list of vocabulary options.
  $vocabularies = taxonomy_get_vocabularies();
  foreach ($vocabularies as $vocabulary) {
    $key = $vocabulary->vid;
    $value = $vocabulary->name;
    $vocabulary_options[$key] = $value;
  } 

  $form['settings']['schedulearts_undeletables_reserved_eventtypes_vocab'] = array(
    '#type' => 'select',
    '#title' => t('Event types vocabulary'),
    '#description' => t('The vocabulary which contains event types. If you change this, make sure to save the form before setting "Reserved Event Types" below'),
    '#options' => $vocabulary_options,
    '#default_value' => variable_get('schedulearts_undeletables_reserved_eventtypes_vocab', '6'),
    '#required' => TRUE,
  );

  // Build the list of term options
  $terms = taxonomy_get_tree(variable_get('schedulearts_undeletables_reserved_eventtypes_vocab', '6'));
  foreach ($terms as $term) {
    $key = $term->tid;
    $value = $term->name;
    $term_options[$key] = $value;
  }

  $form['settings']['schedulearts_undeletables_reserved_eventtypes'] = array(
    '#type' => 'select',
    '#title' => t('Reserved Event Types'),
    '#description' => t('These Event Types cannot be modified or deleted by anyone.'),
    '#options' => $term_options,
    '#default_value' => variable_get('schedulearts_undeletables_reserved_eventtypes'),
    '#required' => TRUE,
    '#multiple' => TRUE,
    '#size' => 10,
  );

    return system_settings_form($form);
    
}
