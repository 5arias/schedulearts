function replaceOverlay(date) {
  jQuery(document).live('drupalOverlayBeforeClose', function() {
    if (window.location.href.indexOf('?', 0) === -1) {
      window.location.href =  window.location.href + '?date=' + date;
    }
    else {
      window.location.href =  window.location.href + '&date=' + date;
    }
  });
}