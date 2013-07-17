<?php
/**
 * @file
 * schedulearts_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function schedulearts_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:schedulears_print/select-timeframe
  $menu_links['main-menu:schedulears_print/select-timeframe'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'schedulears_print/select-timeframe',
    'router_path' => 'schedulears_print/select-timeframe',
    'link_title' => 'Print',
    'options' => array(
      'attributes' => array(
        'title' => 'Print schedule.',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Print');


  return $menu_links;
}
