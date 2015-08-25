/**
 * Created by John on 2015/8/7.
 */


function selectAigis() {
    t_close();
    t_OpenGame();
}

function main() {
    var sDomain = window.document.domain;

    if (sDomain ==  "www.dmm.co.jp")
    {
        var sURL = window.document.documentURI;
            setTimeout("selectAigis()",1000);
    }

}

main();
