(function($) {

Drupal.fullcalendar.plugins.overlay = {
  options: function (fullcalendar, settings) {
    if (!settings.overlay) {
      return;
    }
    settings = settings.overlay;

    var options = {
      eventClick: function(calEvent, jsEvent, view) {
        // Use overlay only for events based on entities
        if (calEvent.eid !== undefined) {
          var url = calEvent.url;
          url = '#overlay=' + url;
          $.overlay({
            href: url
          });
        }
        return false;
      }
    };
    return options;
  }
};

}(jQuery));
