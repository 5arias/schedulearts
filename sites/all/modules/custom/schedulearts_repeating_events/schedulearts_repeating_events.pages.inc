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
    '#default_value' => 1,
    '#options' => $options,
    '#required' => TRUE,
  );
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('schedulearts_repeating_events_multiplicate_method_selector_form_submit'),
    '#value' => t('Duplicate'));
  return $form;
}

function schedulearts_repeating_events_multiplicate_method_selector_form_submit($form, &$form_state) {
  if ($form_state['values']['method'] == 0) {
    // Prepopulate with node_clone.
    drupal_goto('node/ ' . (int)$form_state['values']['nid']. ' /clone');
  }
  else {
    dpm($form_state['values']);
    drupal_set_message('Not implemented yet.');
  }
}