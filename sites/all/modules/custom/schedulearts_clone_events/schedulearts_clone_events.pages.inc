<?php

/**
 * Form callback for Clone Event block.
 */
function schedulearts_clone_events_block_clone_form($form, &$form_state, $nid) {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Duplicate event'),
  );
  if (!empty($form_state['build_info']['args']['0'])) {
    //$current_nid = $form_state['build_info']['args']['0'];
    $form['#action'] = url('schedulearts_clone/clone/' . (int)$nid);
  }
  return $form;
}

/**
 * Form callback to choose between using node_clone or repeat by pattern.
 */
function schedulearts_clone_events_clone_method_selector_form($form, &$form_state, $nid) {
  $options = array(0 => t('Just once'), 1 => t('multiple times on a schedule'));
  $form['#validate'][] = 'schedulearts_clone_events_clone_method_selector_form_validate';
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
    '#submit' => array('schedulearts_clone_events_clone_method_selector_form_submit'),
    '#value' => t('Clone'),
  );
  return $form;
}

/**
 * Validate callback for schedulearts_clone_events_clone_method_selector_form.
 */
function schedulearts_clone_events_clone_method_selector_form_validate($form, &$form_state) {
  if (!_schedulearts_clone_events_is_repeat_range_valid($form_state['input']['repeat_settings']['repeat'])) {
    form_set_error('repeat_settings][repeat', t('DEBUG: Count/Until error'));
  }
}

/**
 * Submit callback for schedulearts_clone_events_clone_method_selector_form.
 * @todo Report Date module issue to drupal.org.
 */
function schedulearts_clone_events_clone_method_selector_form_submit($form, &$form_state) {
  if ($form_state['values']['method'] == 0) {
    // Prepopulate with node_clone.
    drupal_goto('node/ ' . (int)$form_state['values']['nid']. ' /clone');
  }
  else {
    // Without setting the end date, Date module throws a fatal even if "Until" field is set in the rule.
    $end_date = ($form_state['input']['repeat_settings']['repeat']['until_child']['datetime']['date']) ?
    $form_state['input']['repeat_settings']['repeat']['until_child']['datetime']['date'] : NULL;
    $dates = date_repeat_calc($form_state['values']['repeat_settings']['repeat'], $form_state['values']['repeat_settings']['start_date'], strtotime($end_date));
    schedulearts_clone_events_mass_clone_events($form_state['values']['nid'], $dates);

  }
}

/**
 * If both repeat count and repeat until date is empty, the repeat range is invalid.
 *
 * @param $repeat Array Input values of the repeat block of a date repeat form.
 * @return bool
 */
function _schedulearts_clone_events_is_repeat_range_valid($repeat) {
  return ($repeat['count_child'] || $repeat['until_child']['datetime']['date']);
}