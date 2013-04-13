<?php
/**
 * @file
 * schedulearts_settings.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function schedulearts_settings_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'users';
  $feeds_importer->config = array(
    'name' => 'Users',
    'description' => 'Import users from a spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Email',
            'target' => 'mail',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'FirstName',
            'target' => 'field_user_fname',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'LastName',
            'target' => 'field_user_lname',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Fach',
            'target' => 'field_user_fach',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Username',
            'target' => 'name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 1,
        'input_format' => 'plain_text',
        'skip_hash_check' => FALSE,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['users'] = $feeds_importer;

  return $export;
}
