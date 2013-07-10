function addParamToURL(url, param) {
  _url = url;
  _url = (_url.indexOf("?") !== -1 ?
         _url.split("?")[0]+"?"+param+"&"+_url.split("?")[1] :
         (_url.indexOf("#") !== -1 ?
          _url.split("#")[0]+"?"+param+"#"+ _url.split("#")[1] : _url+'?'+param));
  return _url;
}

function replaceOverlay(date) {
  jQuery(window.top.document).bind('drupalOverlayBeforeClose', function() {
    window.top.location.href = addParamToURL(window.top.location.href, "date="+date);
  });
}