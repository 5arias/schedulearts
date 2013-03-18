(function($) {
  Drupal.behaviors.entityreferenceBrowser = {
    attach: function (context, settings) {
      // Get the params from the hash.
      if (location.hash) {
        var q = decodeURIComponent(location.hash.substr(1));
        var o = {'f':function(v){return unescape(v).replace(/\+/g,' ');}};
        $.each(q.match(/^\??(.*)$/)[1].split('&'), function(i,p) {
          p = p.split('=');
          p[1] = o.f(p[1]);
          data[p[0]] = data[p[0]]?((data[p[0]] instanceof Array)?(data[p[0]].push(p[1]),data[p[0]]):[data[p[0]],p[1]]):p[1];
        });
      }

    $('.entityreference-browser-wrapper', context).once('entityreference-browser-view-added', function() {
      var element = $(this),
        viewInfo = $.grep(settings.views.ajaxViews, function(e) {
          return e.entityreference_browser_id == element.attr('id');
        })[0],
        target = $('div.entityreference-browser-view-widget', element);

        $.ajax({
          url: settings.views.ajax_path,
          type: 'GET',
          data: viewInfo,
          success: function(response) {
            if (response[2] !== null) {
              target.html(response[2].data);
            }
            // put a listener on the drag / drop UL item
            $('.entityreference-browser-selected', element).sortable({
              update: Drupal.behaviors.entityreferenceBrowser.browserUpdate
            });
            // This init call causes duplicate entries in the picker list.
            //Drupal.behaviors.entityreferenceBrowser.init(element);
            Drupal.attachBehaviors(target);
          },
          error: function(xhr) {
            // Show an error to the user.
            target.html('<p>The view didn\'t load properly. Please refresh page to try again.</p>');
          },
          dataType: 'json'
        });
    });

    $('body', context).delegate('a.picker', 'click', function(event) {
      event.preventDefault;

      var instance = $(this).closest('.entityreference-browser-wrapper'),
        instanceId = instance.attr('id'),
        instanceSettings = settings.entityreference_browser[instanceId],
        entityId = $(this).attr('data-id');

      // Check cardinality to see if user is allowed to add any more items
      // if it is -1 then the user is allowed to add unlimited items
      if (instanceSettings.cardinality > 0) {
        // Get the count of the current selected items.
        var selectedItemCount = $('ul.entityreference-browser li', instance).length;
        if (selectedItemCount >= instanceSettings.cardinality) {
          // Don't allow the user to add any more items.
          return false;
        }
      }

      // Add entity only one time.
      if(!$('li[data-id="' + entityId + '"]', instance).length) {
        Drupal.behaviors.entityreferenceBrowser.addItem(entityId, instance);
      }

      return false;
    });

    $('body', context).delegate('a.remove', 'click', function(event) {
      event.preventDefault;

      var element = $(this).closest('div.entityreference-browser-wrapper'),
        entityId = $(this).attr('data-id'),
        item = $('#' + element.attr('id') + ' li[data-id="' + entityId + '"]'),
        list = item.closest('[id^=entityreference-browser]');

      Drupal.detachBehaviors(item);
      item.remove();
      Drupal.behaviors.entityreferenceBrowser.browserUpdate('', {item: list});

      return false;
    });
    },

    init: function(element) {
      // Initialize the browser once.
      $('ul.entityreference-browser-selected', element).once('entityreference-browser-selected', function() {
        // @TODO use the proper field-type- class. See browserUpdate.
        var field = element.closest('.field-type-entityreference'),
          hidden = field.find('input.entityreference-browser-values'),
          values = hidden.val();

        if (values !== '') {
          values = values.split(',');
          $.each(values, function(index, value) {
                  Drupal.behaviors.entityreferenceBrowser.addItem(value, element);
          });
        }
      });
    },

    addItem: function(entityId, instance) {
      var label = $('#' + instance.attr('id') + ' a[data-id="' + entityId + '"]').text(),
        entityItemRemove = $('<a />').attr('href', Drupal.settings.basePath + 'node/' + entityId).attr('class', 'remove').attr('data-id', entityId).html('[' + Drupal.t('remove') + ']'),
        entityItem = $('<li />').attr('data-id', entityId).html(label + ' ').append(entityItemRemove);

      $('ul.entityreference-browser', instance).append(entityItem);
      Drupal.behaviors.entityreferenceBrowser.browserUpdate('', {item: instance});
      Drupal.attachBehaviors(instance);
    },

    browserUpdate: function (event, ui) {
      var items = [],
      instanceId = ui.item.attr('id'),
      instanceSettings = Drupal.settings.entityreference_browser[instanceId];
      field = ui.item.closest('.field-type-' + instanceSettings.field_type);

      $(".entityreference-browser-selected li", field).each(function(index) {
              items.push($(this).attr('data-id'));
      });

      $("input.entityreference-browser-values", field).val(items.join(','));
     }
  };
})(jQuery);