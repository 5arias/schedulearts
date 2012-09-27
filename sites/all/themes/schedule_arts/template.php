<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */


function schedule_arts_alpha_preprocess_html(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['content']['content']['sidebar_first']) && !empty($variables['page']['content']['content']['sidebar_second'])) {
    $variables['attributes_array']['class'][] = 'two-sidebars';
  }
  elseif (!empty($variables['page']['content']['content']['sidebar_first'])) {
    $variables['attributes_array']['class'][] = 'one-sidebar sidebar-first';
  }
  elseif (!empty($variables['page']['content']['content']['sidebar_second'])) {
    $variables['attributes_array']['class'][] = 'one-sidebar sidebar-second';
  }
  else {
    $variables['attributes_array']['class'][] = 'no-sidebars';
  }
	
	if (overlay_get_mode() == 'child') {
		drupal_add_css(path_to_theme() . '/css/overlay-child.css', array('group' => CSS_THEME, 'weight' => 115, 'browsers' => array(), 'preprocess' => FALSE));
	}
}


/*
 * Implementation of theme_preprocess_page().
 */

function schedule_arts_preprocess_page(&$variables) {
  foreach ($variables['secondary_menu'] as $key => $item) {
    if ($item['href'] == 'date-print') {
      $variables['secondary_menu'][$key]['attributes']['class'] = 'date_select';
    }
  }
   
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_library('system', 'ui.position');
}
