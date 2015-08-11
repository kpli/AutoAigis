/**
 * Created by John on 2015/8/7.
 */


function getGameURL()
{
    var aigisFrame = document.getElementById("game_frame");
    var gameURL = aigisFrame.getAttribute("src");

    window.setTimeout("closeSelfTab()", 1000);
    window.open(gameURL);
}

function closeSelfTab()
{
    window.close();
}

function main() {

    var sDomain = window.document.domain;

    if (sDomain ==  "www.nutaku.net")
    {
        setTimeout("getGameURL()",1000);
    }

}

main();
