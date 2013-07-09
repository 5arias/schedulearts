(function ($) {
  function replaceOverlay(date) {
    /*jQuery(document).bind('drupalOverlayBeforeClose', function() {
      if (window.location.href.indexOf('?', 0) === -1) {
        window.location.href =  window.location.href + '?date=' + date;
      }
      else {
        window.location.href =  window.location.href + '&date=' + date;
      }
    });*/
    // Hack.
    Drupal.overlay.eventhandlerRefreshPage = function (event) {
      alert('evhandler running');
      if (window.location.href.indexOf('?', 0) === -1) {
        window.location.href =  window.location.href + '?date=' + date;
      }
      else {
        window.location.href =  window.location.href + '&date=' + date;
      }
    };
  }
})(jQuery);