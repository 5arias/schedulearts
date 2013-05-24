<?php

/**
 * Form callback for selecting a timeframe to print.
 */
function schedulearts_select_timeframe_form($form, &$form_state) {
  $form['timeframe_selector'] = array(
    '#type' => 'radios',
    '#title' => t('Timeframe'),
    '#options' => array(
      'day' => t('Day'),
      'month' => t('Month'),
    ),
    '#default_value' => '',
    '#description' => t('What timeframe would you like to print?'),
    '#required' => TRUE,
    '#ajax' => array(
      'event' => 'change',
      'callback' => 'schedulearts_print_timeframe_select',
      'wrapper' => 'replace_model_div',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['#attached']['css'] = array(
    // Hide day selector of drupal date field.
    drupal_get_path('module', 'schedulearts_print') . '/css/schedulearts_print_timeframe_form.css',
  );

  $form['timeframes'] = array(
    '#tree' => TRUE,
    '#prefix' => '<div id="replace_model_div">',
    '#suffix' => '</div>',
  );
  if (isset($form_state['values']['timeframe_selector'])) {
    switch ($form_state['values']['timeframe_selector']) {
      case 'month':
        $form['timeframes']['print_month'] = array(
          '#type' => 'date',
          '#title' => t('Select month'),
          '#required' => TRUE,
        );
        $form['timeframes']['production'] = array(
          '#type' => 'select',
          '#title' => t('Production'),
          '#options' => array(0 => '- Select - ') + _schedulearts_print_production_options(),
        );
        break;
      case 'day':
        $form['timeframes']['print_day'] = array(
          '#type' => 'date_popup',
          '#title' => t('Select day'),
          '#date_format' => 'Y-m-d',
          '#date_year_range' => '-100:+0',
          '#required' => TRUE,
        );
        break;
    }
    $form['timeframes']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Print')
    );
  }
  return $form;
}

/**
 * Ajax callback of schedulearts_select_timeframe_form.
 */
function schedulearts_print_timeframe_select($form, $form_state) {
  return $form['timeframes'];
}

/**
 * Submit callback for schedulearts_select_timeframe_form.
 */
function schedulearts_select_timeframe_form_submit($form, &$form_state) {
  switch ($form_state['values']['timeframe_selector']) {
    case 'month':
        $redirect = 'print/calendar-node-field-event-date/month/' . $form_state['values']['timeframes']['print_month']['year']
          . '-' . $form_state['values']['timeframes']['print_month']['month']
          .($form_state['values']['timeframes']['production'] ? ('/' . $form_state['values']['timeframes']['production']) : '');
      break;
    case 'day':
      $redirect = 'print/schedule/' . urlencode($form_state['values']['timeframes']['print_day']) . '/print';
      break;
  }
  $form_state['redirect'] = $redirect;
}

/**
 * Generates a select list of all 'production' bundle node.
 *
 * @return array
 * 1 => Label for the first node
 * 2 => Label for the second node
 * ...
 */
function _schedulearts_print_production_options() {
  $nodes = node_load_multiple(array(), array('type' => 'production'));
  $list = array();
  foreach ($nodes as $node) {
    $list[$node->nid] = check_plain($node->title);
  }
  return $list;
}