/**
 * Created by John on 2015/8/7.
 */

function submitReal() {
    t_clickName("submit",0);
    //setTimeout("submitReal()", 1000);
}

function submitCloseAD() {
    var btnClose = window.document.getElementById("popup-close");
    if(btnClose == null  )
    {
        setTimeout("submitReal()", 1000);
        //setTimeout("submitCloseAD()", 100);
    }
    else
    {
        setTimeout("submitReal()", 1000);
        t_clickId("popup-close");
    }
}

function registNutaku() {
    chrome.storage.local.get("nutakuMailString", function(valueArray) {

        var mailAll = valueArray["nutakuMailString"];
        var mailUser = mailAll.substr(0,8);

        document.getElementById("mailaddress").value=mailAll;
        document.getElementById("password").value=mailUser;

        setTimeout("submitCloseAD()",1000);
        t_submit("form1");
    });
}

function main() {
    var sDomain = window.document.domain;

    if (sDomain ==  "www.dmm.co.jp")
    {
        var sURL = window.document.documentURI;
        if(sURL == "https://www.dmm.co.jp/my/-/register/")
        {
            setTimeout("registNutaku()",1000);
        }
        else if(sURL == "https://www.dmm.co.jp/my/-/register/apply/")
        {
            t_close();
        }
    }
}

main();
