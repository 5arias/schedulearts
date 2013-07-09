(function($) {
  function replaceOverlay(date) {
    var eventClass = '.drupal-overlay.drupal-overlay-open';
   // $(window).unbind('drupalOverlayClose' + eventClass, $.proxy(Drupal.overlay, 'eventhandlerRefreshPage'));
    $(window).bind('drupalOverlayClose' + eventClass, function() {
      if (window.location.href.indexOf('?', 0) == -1) {
        window.location.href =  window.location.href + '?date=' + date;
      }
      else {
        window.location.href =  window.location.href + '&date=' + date;
      }
    });
  }
})(jQuery);