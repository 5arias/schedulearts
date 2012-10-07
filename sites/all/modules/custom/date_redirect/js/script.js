
/**
 * @file
 * Display the datepicker.
 */

jQuery(document).ready(function($) {
  $("#block-system-user-menu").append('<div id="hidden-field"></div>');
});

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.DateRedirect = {
    attach:
      function(context, settings) {
        $('a[title="Date popup redirect"]').addClass('date-select');
        var $dp = $('<input type="text" />').hide().datepicker({
          onSelect: function(dateText, inst) {
            $('#hidden-field').text(dateText);
            window.open(Drupal.settings.date_redirect.base_url + '/print/schedule/' + dateText + '/print', '_blank');
          }
        }).appendTo('#block-system-user-menu');
        $('a.date-select').click(function(e) {
        e.preventDefault();
        if ($dp.datepicker('widget').is(':hidden')) {
          $dp.datepicker('option', 'dateFormat', 'yy-mm-dd');
          $dp.datepicker('show');
          $dp.datepicker('widget').position({
            my: 'center top',
            at: 'center bottom',
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

