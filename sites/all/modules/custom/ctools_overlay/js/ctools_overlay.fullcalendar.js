(function($) {


Drupal.fullcalendar.plugins.ctools_overlay = {
  options: function (fullcalendar, settings) {
    if (!settings.ctools_overlay) {
      return false;
    }
    // Set ctools modal weight to process fullcalendar too.
    Drupal.behaviors["ZZCToolsModal.weight"] = 100;

    settings = settings.ctools_overlay;
    var options = {
      eventClick: function(calEvent, jsEvent, view) {
        // Use overlay only for events based on entities
        return false;
      }
    };
    return options;
  }
};

}(jQuery));
