<?php
// Caching settings which are common to all sites

// Enable cache systems
$conf['cache_backends'][] = 'sites/all/modules/memcache/memcache.inc';
$conf['cache_backends'][] = 'sites/all/modules/apc/drupal_apc_cache.inc';

// Key prefixing
$conf['cache_prefix'] = $databases['default']['default']['database']; // APC prefix. Based on the db name because that's internal and unique to the site
$conf['memcache_key_prefix'] = $conf['cache_prefix'];

// What gets cached where
$conf['cache_default_class'] = 'MemCacheDrupal';
//$conf['cache_default_class'] = 'DrupalAPCCache';

$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
$conf['cache_class_cache'] = 'DrupalAPCCache';
$conf['cache_class_cache_bootstrap'] = 'DrupalAPCCache';
$conf['cache_class_cache_views_data'] = 'DrupalDatabaseCache'; // Having this cached makes the biggest difference to frontpage loads

$conf['cache_class_cache_menu'] = 'DrupalAPCCache'; 
?>
