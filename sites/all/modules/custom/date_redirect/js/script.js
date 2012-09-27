jQuery(document).ready(function($) {
  // Code that uses jQuery's $ can follow here.
  $("#secondary-menu-links").append("<div id='selected'></div>");
});

/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */


// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {
 Drupal.behaviors.DateRedirect = {
      attach:
          function(context, settings) {
               var $dp = $("<input type='text' />").hide().datepicker({
                 onSelect: function(dateText, inst) {
                   $('#selected').text(dateText);
                   var l = window.location;
                   var base_url = l.protocol + "//" + l.host + "/" + l.pathname.split('/')[1];
                   window.location.replace(base_url + "/print/schedule/" + dateText + "/print");
                 }
               }).appendTo('#secondary-menu-links');

               $(".date_select").click(function(e) {
               e.preventDefault();
               if ($dp.datepicker('widget').is(':hidden')) {
                  $dp.datepicker( "option", "dateFormat", 'yy-mm-dd' );
                  $dp.datepicker("show");
                  $dp.datepicker("widget").position({
                    my: "right top",
                    at: "right top",
                    of: this
                  });
                  
              } else {
                $dp.hide();
              }

             });
 
        }
     }
})(jQuery, Drupal, this, this.document);

