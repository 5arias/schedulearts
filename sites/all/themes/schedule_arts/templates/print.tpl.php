<?php

/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
  global $base_url;
  $print['site_name'] = variable_get('site_name', 'Drupal');
  
  $path = explode("/", current_path());
  $timestamp = strtotime($path['1']);
  $custom_css = $base_url . '/' . drupal_get_path('theme', 'schedule_arts') . '/css/print.css';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
  <head>
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title><?php print $print['title']; ?></title>
    <?php print $print['scripts']; ?>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <?php print $print['css']; ?>
    <style type="text/css" media="all">
      @import url("<?php print $custom_css; ?>");
    </style>
  </head>
  <body class="schedulearts-print">
    <div class="print-site_name"><?php print $print['site_name']; ?></div>
    <p />
    <div class="print-content"><?php print $print['content']; ?></div>
  </body>
</html>

