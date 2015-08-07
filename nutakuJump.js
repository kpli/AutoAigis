/**
 * Created by John on 2015/8/7.
 */

function validMaillAndLogin()
{
    var btnLogin= document.getElementsByClassName("submit");

    var ev = document.createEvent('HTMLEvents');
    ev.initEvent('click', true, true);
    btnLogin[0].dispatchEvent(ev);
}

function main() {

    var sDomain = window.document.domain;

    if (sDomain ==  "www.nutaku.net")
    {
        setTimeout("validMaillAndLogin()",1000);
    }

}

main();
