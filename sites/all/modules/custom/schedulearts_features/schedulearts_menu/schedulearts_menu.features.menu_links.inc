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

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:admin/people/create
  $menu_links['main-menu:admin/people/create'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/people/create',
    'router_path' => 'admin/people/create',
    'link_title' => 'Create user',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'manage/users',
  );
  // Exported menu link: main-menu:admin/structure/taxonomy/group
  $menu_links['main-menu:admin/structure/taxonomy/group'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/structure/taxonomy/group',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => 'Manage Groups 3',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:admin/structure/taxonomy_manager/voc/group
  $menu_links['main-menu:admin/structure/taxonomy_manager/voc/group'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/structure/taxonomy_manager/voc/group',
    'router_path' => 'admin/structure/taxonomy_manager/voc/%',
    'link_title' => 'Groups',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:date-print
  $menu_links['main-menu:date-print'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'date-print',
    'router_path' => 'date-print',
    'link_title' => 'Print',
    'options' => array(
      'attributes' => array(
        'title' => 'Date popup redirect',
      ),
    ),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: main-menu:import/users
  $menu_links['main-menu:import/users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'import/users',
    'router_path' => 'import/%',
    'link_title' => 'Import Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'manage/users',
  );
  // Exported menu link: main-menu:manage-groups
  $menu_links['main-menu:manage-groups'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'manage-groups',
    'router_path' => 'manage-groups',
    'link_title' => 'Manage Groups 2',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:master-calendar
  $menu_links['main-menu:master-calendar'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'master-calendar',
    'router_path' => 'master-calendar',
    'link_title' => 'Master Calendar',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:node/185
  $menu_links['main-menu:node/185'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/185',
    'router_path' => 'node/%',
    'link_title' => 'Productions',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/203
  $menu_links['main-menu:node/203'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/203',
    'router_path' => 'node/%',
    'link_title' => 'Conflicts',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/267
  $menu_links['main-menu:node/267'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/267',
    'router_path' => 'node/%',
    'link_title' => 'Locations',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/268
  $menu_links['main-menu:node/268'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/268',
    'router_path' => 'node/%',
    'link_title' => 'Event Types',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/273
  $menu_links['main-menu:node/273'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/273',
    'router_path' => 'node/%',
    'link_title' => 'Seasons',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-42',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/add/event
  $menu_links['main-menu:node/add/event'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Event',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/add/location
  $menu_links['main-menu:node/add/location'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/location',
    'router_path' => 'node/add/location',
    'link_title' => 'Location',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/add/master-calendar-event
  $menu_links['main-menu:node/add/master-calendar-event'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/master-calendar-event',
    'router_path' => 'node/add/master-calendar-event',
    'link_title' => 'Master Calendar Event',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/add/production
  $menu_links['main-menu:node/add/production'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/production',
    'router_path' => 'node/add/production',
    'link_title' => 'Production',
    'options' => array(
      'attributes' => array(),
      'query' => array(
        'destination' => 'master-calendar',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:node/add/schedule
  $menu_links['main-menu:node/add/schedule'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/schedule',
    'router_path' => 'node/add/schedule',
    'link_title' => 'Send',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: main-menu:print/calendar-node-field-event-date/month/
  $menu_links['main-menu:print/calendar-node-field-event-date/month/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'print/calendar-node-field-event-date/month/',
    'router_path' => 'print',
    'link_title' => 'Monthly',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'date-print',
  );
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
  // Exported menu link: main-menu:user
  $menu_links['main-menu:user'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My Profile',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: main-menu:user-groups
  $menu_links['main-menu:user-groups'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user-groups',
    'router_path' => 'user-groups',
    'link_title' => 'Users',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => '<front>',
  );
  // Exported menu link: main-menu:user/logout
  $menu_links['main-menu:user/logout'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log Out',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-42',
  );
  // Exported menu link: user-menu:<front>
  $menu_links['user-menu:<front>'] = array(
    'menu_name' => 'user-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: user-menu:master-calendar
  $menu_links['user-menu:master-calendar'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'master-calendar',
    'router_path' => 'master-calendar',
    'link_title' => 'Master Calendar',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: user-menu:user
  $menu_links['user-menu:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: user-menu:user/logout
  $menu_links['user-menu:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Conflicts');
  t('Create user');
  t('Event');
  t('Event Types');
  t('Groups');
  t('Home');
  t('Import Users');
  t('Location');
  t('Locations');
  t('Log Out');
  t('Log out');
  t('Manage Groups 2');
  t('Manage Groups 3');
  t('Master Calendar');
  t('Master Calendar Event');
  t('Monthly');
  t('My Profile');
  t('Print');
  t('Production');
  t('Productions');
  t('Seasons');
  t('Send');
  t('User account');
  t('Users');


  return $menu_links;
}
