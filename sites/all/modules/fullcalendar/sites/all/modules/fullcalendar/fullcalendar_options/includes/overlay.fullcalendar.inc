<?php

/**
 * @file
 * Provides extra FullCalendar configuration options for Overlay.
 */

/**
 * Implements hook_fullcalendar_options_info().
 */
function overlay_fullcalendar_options_info() {
  return array(
    'overlay' => array(
      'name' => t('Overlay'),
      'js' => TRUE,
      'parent' => 'fullcalendar_options',
    ),
  );
}

/**
 * Implements hook_fullcalendar_options_definition().
 */
function overlay_fullcalendar_options_definition() {
  $options['overlay']['contains'] = array(
    'overlay' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
  );
  return $options;
}

/**
 * Implements hook_fullcalendar_options_form().
 */
function overlay_fullcalendar_options_form(&$form, &$form_state, &$view) {
  $form['overlay']['overlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open events with Overlay'),
    '#default_value' => $view->options['overlay']['overlay'],
    '#data_type' => 'bool',
  );

  $form['sameWindow']['#dependency'] = array('edit-style-options-overlay-overlay' => array(0));
}

/**
 * Implements hook_fullcalendar_options_process().
 */
function overlay_fullcalendar_options_process(&$variables, &$settings) {
  if (empty($settings['overlay']['overlay'])) {
    unset($settings['overlay']);
  }
}
