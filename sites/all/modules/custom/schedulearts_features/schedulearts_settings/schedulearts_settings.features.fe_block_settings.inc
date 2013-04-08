<?php
/**
 * @file
 * schedulearts_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function schedulearts_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['print-print-links'] = array(
    'cache' => 4,
    'custom' => '0',
    'delta' => 'print-links',
    'module' => 'print',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'acquia_marina' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'acquia_marina',
        'weight' => '0',
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'garland' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'garland',
        'weight' => '0',
      ),
      'schedule_arts' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'schedule_arts',
        'weight' => '0',
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['print-print-top'] = array(
    'cache' => 8,
    'custom' => '0',
    'delta' => 'print-top',
    'module' => 'print',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'acquia_marina' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'acquia_marina',
        'weight' => '0',
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'garland' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'garland',
        'weight' => '0',
      ),
      'schedule_arts' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'schedule_arts',
        'weight' => '0',
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
