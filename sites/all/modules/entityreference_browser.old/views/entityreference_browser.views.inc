<?php
/**
 * @file
 * Alters the table structure.
 */

/**
 * Implements hook_views_data_alter().
 */
function entityreference_browser_views_data_alter(&$data) {
  foreach (entity_get_info() as $entity_type => $info) {
    if (isset($info['base table']) && isset($data[$info['base table']]['table'])) {
      $data[$info['base table']]['entityreference_browser'] = array(
        'title' => $data[$info['base table']]['table']['group'],
        'group' => t('Entity Reference Browser'),
        'help' => t('Provide a field that allows for selecting of this entity within the widget'),
        'real field' => $info['entity keys']['id'],
        'field' => array(
          'handler' => 'entityreference_browser_field_picker',
          'click sortable' => FALSE,
        ),
      );
    }
  }
}
