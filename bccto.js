/**
 * Created by John on 2015/8/7.
 */

var timerUpdateMail = null;

function validMailUpdate() {
    var mailstri = document.getElementById("showmail").innerText;
    var mailuser = document.getElementById("mailuser").value;
    if(mailstri == null || mailuser != mailstri.substr(0,8) )
    {
        setTimeout("validMailUpdate()", 100);
    }
    else
    {
        mailAll = mailstri;

        chrome.storage.local.set({"more2step": "false"}, function() {
        });

        chrome.storage.local.set({"nutakuMailString": mailstri}, function() {
            timerUpdateMail = setInterval("updateNutakuMail()", 500);
            gotoNutakuSignup();
        });
    }
}

function getGameLoginUrl()
{
    var btnClose = window.document.getElementById("btn-ok");
    if(btnClose == null)
    {
        setTimeout("getGameLoginUrl()",100);
        return;
    }

    var t = window.document.getElementById("inbox");
    var n = t.rows.length;
    var mailContent = "";
    for (var a=0; a<n; a++)
    {
        var c = t.rows[a].cells.item(2).innerText;
        if(c == "Nutaku - Verify Your Email")
        {
            mailContent = t.rows[a+1].cells.item(0).innerText;

            var reKey=/(http.*This)/gi;
            var urlSplit = mailContent.match(reKey);
            var nLen = urlSplit[0].length;
            var gameLoginUrl = urlSplit[0].substr(0,nLen - 5);

            window.setTimeout("closeSelfTab()", 1000);
            window.open(gameLoginUrl);

            break;
        }
    }
}

function closeSelfTab()
{
    window.close();
}

function registMail() {

    var btnRand = window.document.getElementById("randMail");
    var ev = document.createEvent('HTMLEvents');
    ev.initEvent('click', true, true);
    btnRand.dispatchEvent(ev);

    var btnApply = window.document.getElementById("applyMail");
    var ev = document.createEvent('HTMLEvents');
    ev.initEvent('click', true, true);
    btnApply.dispatchEvent(ev);

    setTimeout("validMailUpdate()",1000);
}


function updateNutakuMail()
{
    var t = window.document.getElementById("inbox");

    var n = t.rows.length;
    var r = "";
    for (var a=0; a<n; a++)
    {
        var c = t.rows[a].cells.item(2).innerText;
        if(c == "Nutaku - Verify Your Email")
        {
            clearInterval(timerUpdateMail);

            var elementTarget = t.rows[a];
            elementTarget.setAttribute("class","success");      // important
            var ev = document.createEvent('HTMLEvents');
            ev.initEvent('click', true, true);
            elementTarget.cells.item(2).dispatchEvent(ev);

            setTimeout("getGameLoginUrl()",100);
            return c;
        }
    }
    return "";
}

function gotoNutakuSignup()
{
    window.open("https://www.nutaku.net/signup/");
}

function main() {

    var sDomain = window.document.domain;

    if (sDomain == "www.bccto.me")
    {
        setTimeout("registMail()",1000);
    }
}

main();
