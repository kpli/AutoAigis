/**
 * Created by John on 2015/8/7.
 */


function registNutaku()
{
    var mailAll = "";
    chrome.storage.local.get("nutakuMailString", function(valueArray) {

        mailAll = valueArray["nutakuMailString"];
        var mailUser = mailAll.substr(0,8);

        document.getElementById("s-username").value=mailUser;
        document.getElementById("s-password").value=mailUser;
        document.getElementById("s-email").value=mailAll;

        var theForm= document.getElementById("singupForm");
        theForm.submit();

    });

    if(mailAll == "")
    {
        setTimeout("registNutaku()",1000);
    }

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
        if(sURL == "https://www.nutaku.net/signup/")
        {
            setTimeout("registNutaku()",1000);
        }
        else if(sURL == "https://www.nutaku.net/signup/activation/")
        {
            window.setTimeout("closeSelfTab()", 1000);
        }
    }

}

main();
