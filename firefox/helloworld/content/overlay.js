window.addEventListener("load", function(e) { HelloWorld.onLoad(e); }, false); 

var HelloWorld = {
  onLoad: function() {
    // initialization code
    this.initialized = true;

    var appcontent = document.getElementById("appcontent");
    if(appcontent){
      alert("appcontent is true");
      appcontent.addEventListener("DOMContentLoaded", HelloWorld.onMenuItemCommand, true);
    }
  },

  onMenuItemCommand: function() {
//window.open("chrome://helloworld/content/hello.xul", "", "chrome");
//var ww = Components.classes["@mozilla.org/embedcomp/window-watcher;1"].getService(Components.interfaces.nsIWindowWatcher);
//ww.openWIndow is return before the window is fully loaded, 
//make sure win is fully initialize before calling method on it. 
//var win = ww.openWindow(null, "chrome://helloworld/content/hello.xul","aboutMyExtension", "chrome,centerscreen", null);

//if (win) alert("ok win in overlay.js");
//else alert("no ok win in overlay.js");
//alert("child window's title is"+win.document.title);

//var wm = Components.classes["@mozilla.org/appshell/window-mediator;1"].getService(Components.interfaces.nsIWindowMediator);  
//var win = wm.getMostRecentWindow("navigator:browser");  
//win.gBrowser.addTab("http://google.com");
//alert(win.document.title);

//var wm = Components.classes["@mozilla.org/appshell/window-mediator;1"].getService(Components.interfaces.nsIWindowMediator);
//var mainWindow = wm.getMostRecentWindow("navigator:browser");
//mainWindow.gBrowser.addTab("http://www.google.com");


//gBrowser.addTab("http://www.google.com");
//alert(gBrowser.contentDocument.title);
//gBrowser.contentDocument.title = "lalala";
//alert(gBrowser.contentDocument.title);

//var newStyle = document.createElement('style');
//newStyle.setAttribute('background-color:blue');
//gBrowser.contentDocument.body.appendChild(newStyle);

//alert(gBrowser.contentDocument.URL);
gBrowser.contentDocument.body.setAttribute('style', 'background-color:black');
//alert(gBrowser.contentDocument.body.innerHTML);
  }
};

