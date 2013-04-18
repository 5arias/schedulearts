<?php

/**
 * Form callback for Multiplicate Event block.
 */
function schedulearts_repeating_events_block_multiplicate_form($form, &$form_state, $nid) {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Duplicate event'),
  );
  if (!empty($form_state['build_info']['args']['0'])) {
    //$current_nid = $form_state['build_info']['args']['0'];
    $form['#action'] = url('schedulearts_repeating/multiplicate/' . (int)$nid);
  }
  return $form;
}

/**
 * Form callback to choose between using node_clone or repeat by pattern.
 */
function schedulearts_repeating_events_multiplicate_method_selector_form($form, &$form_state, $nid) {
  $options = array(0 => t('Just once'), 1 => t('multiple times on a schedule'));
  $form['method'] = array(
    '#type' => 'radios',
    '#title' => t('I would like to duplicate this event:'),
    '#default_value' => 0,
    '#options' => $options,
    '#required' => TRUE,
  );
  $form['repeat_settings'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Repeat settings'),
    '#states' => array(
      'visible' => array(   // action to take.
        ':input[name="method"]' // element to evaluate condition on
          => array('value' => 1),  // condition
      ),
    ),
  );
  $form['repeat_settings']['start_date'] = array(
    '#type' => 'date_popup',
    '#title' => 'Start Date',
    '#date_format' => variable_get('date_format_short', 'm/d/Y - H:i'),
    '#default_value' => "2013-01-01 12:45:00",
    '#date_year_range' => '-1+3',
    '#required' => TRUE,
    '#tree' => TRUE,
  );
  $form['repeat_settings']['repeat'] = array(
    '#type' => 'date_repeat_rrule',
    '#default_value' => '',
    '#date_timezone' => date_default_timezone(),
    '#date_format' => variable_get('date_format_short', 'm/d/Y - H:i'),
    '#date_year_range' => '-1:+3',
    '#date_repeat_widget' => 'date_popup',
    '#date_repeat_collapsed' => TRUE,
    '#weight' => 2,
  );
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('schedulearts_repeating_events_multiplicate_method_selector_form_submit'),
    '#value' => t('Multiplicate'),
  );
  return $form;
}

function schedulearts_repeating_events_multiplicate_method_selector_form_submit($form, &$form_state) {
  if ($form_state['values']['method'] == 0) {
    // Prepopulate with node_clone.
    drupal_goto('node/ ' . (int)$form_state['values']['nid']. ' /clone');
  }
  else {
    $dates = date_repeat_calc($form_state['values']['repeat_settings']['repeat'], $form_state['values']['repeat_settings']['start_date'], NULL);
    drupal_set_message('Not implemented yet.');
  }
}