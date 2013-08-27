<?php
/**
 * Declares your FullCalendar configuration extender.
 *
 * @return array
 *   An associative array, keyed by your module's machine name, containing an
 *   associative array with the following key-value pairs:
 *   - name: The translated name of your module.
 *   - parent: (optional) The machine name of your module if you are providing
 *     functionality on behalf of another module.
 *   - css: (optional) TRUE if the module provides a CSS file.
 *   - js: (optional) TRUE if the module provides a JS file.
 *   - weight: (optional) A number defining the order in which the includes are
 *     processed and added to the form.
 *   - no_fieldset: (optional) TRUE if the module provides its own fieldset.
 */
function ctools_overlay_fullcalendar_options_info() {
  // Colorbox integration is currently provided by fullcalendar_options, and it
  // provides a JS file.
  return array(
    'ctools_overlay' => array(
      'name' => t('CTools Overlay'),
      'js' => TRUE,
    ),
  );
}

/**
 * Implements hook_fullcalendar_options_definition().
 */
function ctools_overlay_fullcalendar_options_definition() {
  $options['ctools_overlay']['contains'] = array(
    'ctools_overlay' => array(
      'default' => FALSE,
      'bool' => TRUE,
    ),
  );
  return $options;
}

/**
 * Implements hook_fullcalendar_options_form().
 */
function ctools_overlay_fullcalendar_options_form(&$form, &$form_state, &$view) {
  $form['ctools_overlay']['ctools_overlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open events with CTools Overlay'),
    '#default_value' => $view->options['ctools_overlay']['ctools_overlay'],
    '#data_type' => 'bool',
  );

  $form['sameWindow']['#dependency'] = array('edit-style-options-ctools-overlay-ctools-overlay' => array(0));
}

/**
 * Implements hook_fullcalendar_options_process().
 */
function ctools_overlay_fullcalendar_options_process(&$variables, &$settings) {
  if (empty($settings['ctools_overlay']['ctools_overlay'])) {
    unset($settings['ctools_overlay']);
  }
}
