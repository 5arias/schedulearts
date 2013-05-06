<?php
/**
 * @file
 * schedulearts_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function schedulearts_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access admin theme.
  $permissions['access admin theme'] = array(
    'name' => 'access admin theme',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'admin_theme',
  );

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: access backup and migrate.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: access backup files.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access dashboard.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: access overlay.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'overlay',
  );

  // Exported permission: access print.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print',
  );

  // Exported permission: access private fields.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: access rules debug.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer add another.
  $permissions['administer add another'] = array(
    'name' => 'administer add another',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'addanother',
  );

  // Exported permission: administer backup and migrate.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'block',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer date tools.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'date_tools',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'features',
  );

  // Exported permission: administer feeds.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: administer field permissions.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer flags.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'image',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer menu attributes.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: administer print.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'print',
  );

  // Exported permission: administer rules.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: administer rules forms.
  $permissions['administer rules forms'] = array(
    'name' => 'administer rules forms',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'rules_forms',
  );

  // Exported permission: administer rules forms rules.
  $permissions['administer rules forms rules'] = array(
    'name' => 'administer rules forms rules',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'rules_forms',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'search',
  );

  // Exported permission: administer shortcuts.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: bypass rules access.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: clear users feeds.
  $permissions['clear users feeds'] = array(
    'name' => 'clear users feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: clone event.
  $permissions['clone event'] = array(
    'name' => 'clone event',
    'roles' => array(),
    'module' => 'schedulearts_clone_events',
  );

  // Exported permission: clone node.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'clone',
  );

  // Exported permission: clone own nodes.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(),
    'module' => 'clone',
  );

  // Exported permission: configure schedulearts_undeletables admin settings.
  $permissions['configure schedulearts_undeletables admin settings'] = array(
    'name' => 'configure schedulearts_undeletables admin settings',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'schedulearts_undeletables',
  );

  // Exported permission: create announcement content.
  $permissions['create announcement content'] = array(
    'name' => 'create announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create call content.
  $permissions['create call content'] = array(
    'name' => 'create call content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create conflict content.
  $permissions['create conflict content'] = array(
    'name' => 'create conflict content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create event content.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_group_structure.
  $permissions['create field_group_structure'] = array(
    'name' => 'create field_group_structure',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_organizational_role.
  $permissions['create field_organizational_role'] = array(
    'name' => 'create field_organizational_role',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_prod_color.
  $permissions['create field_prod_color'] = array(
    'name' => 'create field_prod_color',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_prod_tid.
  $permissions['create field_prod_tid'] = array(
    'name' => 'create field_prod_tid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_groups.
  $permissions['create field_user_groups'] = array(
    'name' => 'create field_user_groups',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_searchable_name.
  $permissions['create field_user_searchable_name'] = array(
    'name' => 'create field_user_searchable_name',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create location content.
  $permissions['create location content'] = array(
    'name' => 'create location content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create master_calendar_event content.
  $permissions['create master_calendar_event content'] = array(
    'name' => 'create master_calendar_event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create production content.
  $permissions['create production content'] = array(
    'name' => 'create production content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create schedule content.
  $permissions['create schedule content'] = array(
    'name' => 'create schedule content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'path',
  );

  // Exported permission: customize shortcut links.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: delete any announcement content.
  $permissions['delete any announcement content'] = array(
    'name' => 'delete any announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any call content.
  $permissions['delete any call content'] = array(
    'name' => 'delete any call content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any conflict content.
  $permissions['delete any conflict content'] = array(
    'name' => 'delete any conflict content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any event content.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any location content.
  $permissions['delete any location content'] = array(
    'name' => 'delete any location content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any master_calendar_event content.
  $permissions['delete any master_calendar_event content'] = array(
    'name' => 'delete any master_calendar_event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any production content.
  $permissions['delete any production content'] = array(
    'name' => 'delete any production content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any schedule content.
  $permissions['delete any schedule content'] = array(
    'name' => 'delete any schedule content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete backup files.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: delete own announcement content.
  $permissions['delete own announcement content'] = array(
    'name' => 'delete own announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own call content.
  $permissions['delete own call content'] = array(
    'name' => 'delete own call content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own conflict content.
  $permissions['delete own conflict content'] = array(
    'name' => 'delete own conflict content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own event content.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own location content.
  $permissions['delete own location content'] = array(
    'name' => 'delete own location content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own master_calendar_event content.
  $permissions['delete own master_calendar_event content'] = array(
    'name' => 'delete own master_calendar_event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own production content.
  $permissions['delete own production content'] = array(
    'name' => 'delete own production content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own schedule content.
  $permissions['delete own schedule content'] = array(
    'name' => 'delete own schedule content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5.
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6.
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7.
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8.
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9.
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: display drupal links.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: edit any announcement content.
  $permissions['edit any announcement content'] = array(
    'name' => 'edit any announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any call content.
  $permissions['edit any call content'] = array(
    'name' => 'edit any call content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any conflict content.
  $permissions['edit any conflict content'] = array(
    'name' => 'edit any conflict content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any event content.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any location content.
  $permissions['edit any location content'] = array(
    'name' => 'edit any location content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any master_calendar_event content.
  $permissions['edit any master_calendar_event content'] = array(
    'name' => 'edit any master_calendar_event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any production content.
  $permissions['edit any production content'] = array(
    'name' => 'edit any production content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any schedule content.
  $permissions['edit any schedule content'] = array(
    'name' => 'edit any schedule content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_group_structure.
  $permissions['edit field_group_structure'] = array(
    'name' => 'edit field_group_structure',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_organizational_role.
  $permissions['edit field_organizational_role'] = array(
    'name' => 'edit field_organizational_role',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_prod_color.
  $permissions['edit field_prod_color'] = array(
    'name' => 'edit field_prod_color',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_prod_tid.
  $permissions['edit field_prod_tid'] = array(
    'name' => 'edit field_prod_tid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_groups.
  $permissions['edit field_user_groups'] = array(
    'name' => 'edit field_user_groups',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_searchable_name.
  $permissions['edit field_user_searchable_name'] = array(
    'name' => 'edit field_user_searchable_name',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own announcement content.
  $permissions['edit own announcement content'] = array(
    'name' => 'edit own announcement content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own call content.
  $permissions['edit own call content'] = array(
    'name' => 'edit own call content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: edit own conflict content.
  $permissions['edit own conflict content'] = array(
    'name' => 'edit own conflict content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own event content.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_group_structure.
  $permissions['edit own field_group_structure'] = array(
    'name' => 'edit own field_group_structure',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_organizational_role.
  $permissions['edit own field_organizational_role'] = array(
    'name' => 'edit own field_organizational_role',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_prod_color.
  $permissions['edit own field_prod_color'] = array(
    'name' => 'edit own field_prod_color',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_prod_tid.
  $permissions['edit own field_prod_tid'] = array(
    'name' => 'edit own field_prod_tid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_groups.
  $permissions['edit own field_user_groups'] = array(
    'name' => 'edit own field_user_groups',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_searchable_name.
  $permissions['edit own field_user_searchable_name'] = array(
    'name' => 'edit own field_user_searchable_name',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own location content.
  $permissions['edit own location content'] = array(
    'name' => 'edit own location content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own master_calendar_event content.
  $permissions['edit own master_calendar_event content'] = array(
    'name' => 'edit own master_calendar_event content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own production content.
  $permissions['edit own production content'] = array(
    'name' => 'edit own production content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own schedule content.
  $permissions['edit own schedule content'] = array(
    'name' => 'edit own schedule content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5.
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6.
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7.
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8.
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9.
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: import users feeds.
  $permissions['import users feeds'] = array(
    'name' => 'import users feeds',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'features',
  );

  // Exported permission: node-specific print configuration.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'print',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: perform backup.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: restore from backup.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: schedule print page.
  $permissions['schedule print page'] = array(
    'name' => 'schedule print page',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'schedulearts_print',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: skip comment approval.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: switch shortcut sets.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: unlock users feeds.
  $permissions['unlock users feeds'] = array(
    'name' => 'unlock users feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: update any fullcalendar event.
  $permissions['update any fullcalendar event'] = array(
    'name' => 'update any fullcalendar event',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'fullcalendar',
  );

  // Exported permission: use PHP for settings.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'php',
  );

  // Exported permission: use PHP for title patterns.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: use add another.
  $permissions['use add another'] = array(
    'name' => 'use add another',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'addanother',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'search',
  );

  // Exported permission: use flag import.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format php_code.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: view date repeats.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'date_repeat_field',
  );

  // Exported permission: view field_group_structure.
  $permissions['view field_group_structure'] = array(
    'name' => 'view field_group_structure',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_organizational_role.
  $permissions['view field_organizational_role'] = array(
    'name' => 'view field_organizational_role',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_prod_color.
  $permissions['view field_prod_color'] = array(
    'name' => 'view field_prod_color',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_prod_tid.
  $permissions['view field_prod_tid'] = array(
    'name' => 'view field_prod_tid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_groups.
  $permissions['view field_user_groups'] = array(
    'name' => 'view field_user_groups',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_searchable_name.
  $permissions['view field_user_searchable_name'] = array(
    'name' => 'view field_user_searchable_name',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_group_structure.
  $permissions['view own field_group_structure'] = array(
    'name' => 'view own field_group_structure',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_organizational_role.
  $permissions['view own field_organizational_role'] = array(
    'name' => 'view own field_organizational_role',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_prod_color.
  $permissions['view own field_prod_color'] = array(
    'name' => 'view own field_prod_color',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_prod_tid.
  $permissions['view own field_prod_tid'] = array(
    'name' => 'view own field_prod_tid',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_groups.
  $permissions['view own field_user_groups'] = array(
    'name' => 'view own field_user_groups',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_searchable_name.
  $permissions['view own field_user_searchable_name'] = array(
    'name' => 'view own field_user_searchable_name',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Company Admin' => 'Company Admin',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'system',
  );

  return $permissions;
}
