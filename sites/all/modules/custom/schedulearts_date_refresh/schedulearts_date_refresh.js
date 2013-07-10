function replaceOverlay(date) {
  jQuery(window.top.document).bind('drupalOverlayBeforeClose', function() {
    _url = window.top.location.href;
    param = "date="+date;
    _url = (_url.indexOf("?") !== -1 ?
         _url.split("?")[0]+"?"+param+"&"+_url.split("?")[1] :
         (_url.indexOf("#") !== -1 ?
          _url.split("#")[0]+"?"+param+"#"+ _url.split("#")[1] : _url+'?'+param));
    window.top.location.href = _url;
  });
}