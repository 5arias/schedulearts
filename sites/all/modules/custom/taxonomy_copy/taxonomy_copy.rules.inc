<?php
/** 
 * Implementation of hook_rules_action_info()
 * Provides a Rules action for "copy term and children"
 * Provides a Rules action for "copy vocabulary"
 */
function taxonomy_copy_rules_action_info() {
  return array(
    'taxonomy_copy_copy_term' => array( 
      'group' => t('Taxonomy Copy'),
      'label' => t('Copy term and children'),
      'module' => 'taxonomy_copy',
      'parameter' => array(
        'oldtid' => array(
          'type' => 'taxonomy_term',
          'label' => t('Term to be copied'),
        ),
        'newvid' => array(
          'type' => 'taxonomy_vocabulary',
          'label' => t('Destination vocabulary'),
        ),
        'newparent' => array(
          'type' => 'taxonomy_term',
          'label' => 'Destination parent term',
        ),
        'newname' => array(
          'type' => 'text',
          'label' => 'New term name',
        ),
      ),
      'provides' => array(
        'created_term' => array(
          'type' => 'taxonomy_term',
          'label' => t('Created term'),
        ),
      ),
    ),
  );
}
?>
