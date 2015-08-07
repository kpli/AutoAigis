/**
 * Created by John on 2015/8/7.
 */


function selectAigis()
{
    window.setTimeout("closeSelfTab()", 1000);
    window.open("http://www.nutaku.net/games/millennium-war-aigis/");
}

function closeSelfTab()
{
    window.close();
}

function main() {
    var sDomain = window.document.domain;

    if (sDomain ==  "www.nutaku.net")
    {
        var sURL = window.document.documentURI;
        if(sURL == "http://www.nutaku.net/home/")
        {
            setTimeout("selectAigis()",1000);
        }
    }

}

main();
