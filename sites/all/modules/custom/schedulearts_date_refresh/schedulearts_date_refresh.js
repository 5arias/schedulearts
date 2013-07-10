function replaceOverlay(date) {
  jQuery(window.top.document).live('drupalOverlayBeforeClose', function() {
    if (window.location.href.indexOf('?', 0) === -1) {
      window.location.href =  window.location.href + '?date=' + date;
    }
    else {
      window.location.href =  window.location.href + '&date=' + date;
    }
  });
  //Drupal.overlay.isOpen; // This will generate a JS breakpoint that might be useful.
}