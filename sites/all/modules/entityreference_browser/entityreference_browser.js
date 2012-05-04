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
    }
  };

  $(document).ready(function() {
    var data = {};
    // Add view settings to the data.
    for (var key in Drupal.settings.views.ajaxViews[0]) {
      data[key] = Drupal.settings.views.ajaxViews[0][key];
    }

    $.ajax({
      url: Drupal.settings.views.ajax_path,
      type: 'GET',
      data: data,
      success: function(response) {
        var viewDiv = '.view-dom-id-' + data.view_dom_id;
        var target = $('div.entityreference-browser-view-widget');
        if (response[2] != null) {
          target.html(response[2].data);
        }
        if (Drupal.settings && Drupal.settings.views && Drupal.settings.views.ajaxViews) {
          $.each(Drupal.settings.views.ajaxViews, function(i, settings) {
            // @todo: Figure out where to store the object.
            new Drupal.views.ajaxView(settings);
          });
        }

        // put a listener on the drag / drop UL item
        var $select = $(".entityreference-browser-selected");
        $select.sortable({
          update: entityreference_browser_update
        });
      },
      error: function(xhr) {
        // Show an error to the user.
        var target = $('div.entityreference-browser-view-widget');
        target.html('<p>The view didn\'t load properly. Please refresh page to try again.</p>');
      },
      dataType: 'json'
    });

    $('body').delegate('a.picker', 'click', function(event) {
      event.preventDefault;

      var entityId = $(this).attr('data-id');
      var label = $(this).text();
      
      // Check cardinality to see if user is allowed to add any more items 
      // if it is -1 then the user is allowed to add unlimited items
      var cardinality = Drupal.settings.entityreference_browser.cardinality;
      if (cardinality > 0) {
        // Get the count of the current selected items.
        var selectedItemCount = $('ul.entityreference-browser li').length;
        if (selectedItemCount >= cardinality) {
          // Don't allow the user to add any more items.
          return false;
        }
      }

      // Add entity only one time.
      if(!$('li[data-id="' + entityId + '"]').length) {
        // We should support more than only nodes.
        var entityItemRemove = $('<a />').attr('href', Drupal.settings.basePath + 'node/' + entityId).attr('class', 'remove').attr('data-id', entityId).html('[' + Drupal.t('remove') + ']');
        var entityItem = $('<li />').attr('data-id', entityId).html(label + ' ').append(entityItemRemove);

        $('ul.entityreference-browser').append(entityItem);

        entityreference_browser_update();
      }

      return false;
    });

    $('body').delegate('a.remove', 'click', function(event) {
      event.preventDefault;

      var entityId = $(this).attr('data-id');

      $('li[data-id="' + entityId + '"]').remove();

      entityreference_browser_update();
      return false;
    });

  });

  function entityreference_browser_update(event, ui) {
    var items = [];
    $(".entityreference-browser-selected li").each(function(index) {
      items.push($(this).attr('data-id'));
    });

    $("input.entityreference-browser-values").val(items.join(','));
  }

})(jQuery);
