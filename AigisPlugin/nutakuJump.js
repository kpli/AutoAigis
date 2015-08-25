/**
 * Created by John on 2015/8/7.
 */

function validMaillAndLogin()
{
    t_clickClass("d-btn-xhi-st", 0);
}

function main() {

    var sDomain = window.document.domain;

    if (sDomain ==  "www.dmm.co.jp")
    {
        setTimeout("validMaillAndLogin()",1000);
    }

}

main();
