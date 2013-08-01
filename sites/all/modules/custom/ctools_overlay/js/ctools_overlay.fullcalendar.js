(function($) {

Drupal.behaviors["ZZCToolsModal.weight"] = 100;

Drupal.fullcalendar.plugins.CToolsOverlay = {
  options: function (fullcalendar, settings) {
    // if (!settings.overlay) {
    //   return;
    // }
    // settings = settings.overlay;

    var options = {
      eventClick: function(calEvent, jsEvent, view) {
        // Use overlay only for events based on entities
        console.log(calEvent);
        console.log(jsEvent);
        alert("a");
        return false;
      }
    };
    return options;
  }
};

}(jQuery));
