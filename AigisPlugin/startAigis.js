/**
 * Created by John on 2015/8/7.
 */


function playNow()
{
    t_clickTag("span", "Game Start");
}

function submitInfo(){
    if(t_valid("commit_submit"))
        t_clickId("commit_submit");
    else if(t_valid("detail"))
        t_clickId("detail");
    else
        t_submit("form1");
}

function main() {

    chrome.storage.local.get("more2step", function(valueArray) {
        var more2step = valueArray["more2step"];
        if(more2step == "true") {
            alert(false);
            return;
        }

        var sDomain = window.document.domain;
        if (sDomain ==  "www.dmm.co.jp") {
            var sURL = window.document.documentURI;
            if(sURL == "http://www.dmm.co.jp/netgame_s/aigis/") {
                setTimeout("playNow()",1000);
            }
            else {
                setTimeout("submitInfo()", 2000);
            }
        }
    });
}

main();
