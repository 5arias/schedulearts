<?php
/**
 * @file
 * Contains the views field handler.
 */

/**
 * Field handler used in the Browser View. It creates a selectable link.
 *
 * @ingroup views_field_handlers
 */
class entityreference_browser_field_picker extends views_handler_field {
  /**
   * Overridden to use a metadata wrapper.
   */
  public function get_value($values, $field = NULL) {
    return EntityFieldHandlerHelper::get_value($this, $values, $field);
  }

  function label() {
    return t('Select Content');
  }

  function render($values) {
    $entities = entity_get_info();
    foreach ($entities as $e_key => $e_value) {
      if ($e_value['base table'] == $this->table) {
        $entity_type = $e_key;
      }
    }

    $id_key = $this->real_field;
    $entity = reset(entity_load($entity_type, array($values->$id_key)));
    $entity_label = entity_label($entity_type, $entity);
    $entity_path = entity_uri($entity_type, $entity);
    return l($entity_label, $entity_path['path'], array('attributes' => array('class' => 'picker', 'data-id' => $values->$id_key)));
  }
}
