
/**
 * @file
 * A JavaScript file for the theme.
 */

jQuery(document).ready(function($) {
  $("#block-system-user-menu").append('<div id="hidden-field" style="display"></div>');
});

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.DateRedirect = {
    attach:
      function(context, settings) {
        $('a[title="Date popup redirect"]').addClass('date-select');
        var $dp = $('<input type="text" />').hide().datepicker({
          onSelect: function(dateText, inst) {
            $('#hidden-field').text(dateText);
            window.location.replace(Drupal.settings.date_redirect.base_url + '/print/schedule/' + dateText + '/print');
          }
        }).appendTo('#block-system-user-menu');
        $('a.date-select').click(function(e) {
        e.preventDefault();
        if ($dp.datepicker('widget').is(':hidden')) {
          $dp.datepicker('option', 'dateFormat', 'yy-mm-dd');
          $dp.datepicker('show');
          $dp.datepicker('widget').position({
            my: 'left bottom',
            at: 'left bottom',
            of: this
          });
        }
        else {
          $dp.hide();
        }
      });
    }
  }
})(jQuery, Drupal, this, this.document);

