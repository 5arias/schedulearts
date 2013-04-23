/**
 * @file
 * Process Navigator links to display in Overlay properly.
 */
(function($){
  $(document).ready(function() {
    $.each($('a.fc-event'), function(i, event_link) {
      $(event_link).attr('href', decodeURIComponent($(event_link).attr('href')));
    });
  });
})(jQuery); //