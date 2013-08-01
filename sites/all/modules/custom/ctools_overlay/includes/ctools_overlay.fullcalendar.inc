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
//      'parent' => 'fullcalendar_options',
    ),
  );
}
