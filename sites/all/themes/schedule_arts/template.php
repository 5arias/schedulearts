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
}
?>