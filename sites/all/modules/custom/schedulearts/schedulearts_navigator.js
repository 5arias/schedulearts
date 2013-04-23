/**
 * @file
 * Process Navigator links to display in Overlay properly.
 */
(function($){
  $(document).ready(function() {
    $.each($('a.fc-event'), function(i, event_link) {
      var href= $(event_link).attr('href');  
      if (typeof(href.decodeURI) === 'function') {
        $(event_link).attr('href', href.decodeURI());
      }
    });
  });
})(jQuery); //