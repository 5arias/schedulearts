function replaceOverlay(date) {
  var eventClass = '.drupal-overlay.drupal-overlay-open';
  jQuery(document).unbind('drupalOverlayClose' + eventClass);
  jQuery(document).bind('drupalOverlayClose' + eventClass, function() {
    if (window.location.href.indexOf('?', 0) === -1) {
      window.location.href =  window.location.href + '?date=' + date;
    }
    else {
      window.location.href =  window.location.href + '&date=' + date;
    }
  });
}