/**
 * Created by John on 2015/8/7.
 */

var timerUpdateMail = null;

function validMailUpdate() {
    var mailstri = document.getElementById("mail_cur_name").value;
    var mailuser = document.getElementById("converts").value;
    if(mailstri == null || mailuser != mailstri.substr(0,11) ) {
        setTimeout("validMailUpdate()", 2000);
    }
    else {
        mailAll = mailstri;
        chrome.storage.local.set({"more2step": "false"}, function() {
            chrome.storage.local.set({"nutakuMailString": mailstri}, function() {
                timerUpdateMail = setInterval("updateNutakuMail()", 500);
                t_Signup();
            });
        });
    }
}

function getGameLoginUrl() {
	
    var mailContent = window.document.getElementById("mailview_data").innerText;

	var reKey=/(https.*)/gi;
	var urlSplit = mailContent.match(reKey);
	var posBlank = urlSplit[0].indexOf(" ");
	var verifiAccount = urlSplit[0].substr(0,posBlank);

	t_close();
	window.open(verifiAccount);
}

function updateNutakuMail() {
    var t = window.document.getElementById("maillist");
    var n = t.rows.length;
    var r = "";
    for (var a=0; a<n; a++) {
        var c = t.rows[a].cells.item(0).innerText;
        if(c.substr(0,3) == "DMM") {
            clearInterval(timerUpdateMail);
			
            var elementTarget = t.rows[a];
            elementTarget.setAttribute("class","success");      // important
            var ev = document.createEvent('HTMLEvents');
            ev.initEvent('click', true, true);
            elementTarget.cells.item(0).dispatchEvent(ev);

            setTimeout("getGameLoginUrl()",2000);
            return c;
        }
    }
    return "";
}

function randomMail() {
    t_clickClass("btn_1 f14",1);
    setTimeout("registMail()",1000);
}

function registMail() {
    //t_clickClass("btn_1 f14",2);
    setTimeout("validMailUpdate()",1000);
}

function main() {
    var sDomain = window.document.domain;
    if (sDomain == "24mail.chacuo.net")
    {
        setTimeout("randomMail()",2000);
    }
}

main();


