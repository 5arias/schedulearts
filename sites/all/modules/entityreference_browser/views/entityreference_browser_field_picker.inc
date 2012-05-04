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
    return l($values->node_title, 'node/' . $values->nid, array('attributes' => array('class' => 'picker', 'data-id' => $values->nid)));
  }
}