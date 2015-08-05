/**
This is the script run when the browser starts up and is not associated
with any tab. Here we create a add-on icon in the add-on bar to display
the options.
*/

'use strict';

/**
* Main function where all the action starts
*/
var main = function() {


    // Add icon to add-on bar
    chrome.browserAction.setTitle({title: "regist the bccto mail"});
    chrome.browserAction.setPopup({popup:"popup.html"});
    chrome.browserAction.setIcon({path:'ToolExt.png'});
    
    // Query configuration from PNR service
    queryConfig();
};

main();
