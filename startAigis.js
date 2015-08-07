/**
 * Created by John on 2015/8/7.
 */

function selectBirthday()
{
    var selForm= window.document.getElementById("selectAgeGender");
    if(selForm == null)
    {
        setTimeout("selectBirthday()",100);
        return;
    }

    chrome.storage.local.set({"more2step": "true"}, function() {
    });

    document.getElementById("gender-male").checked=true;
    document.getElementById("gender").setAttribute("class","gen-birth SuccessField");
    document.getElementById("birthYear").value="1977";
    document.getElementById("birthYear").setAttribute("class","SuccessField");
    document.getElementById("birthMonth").value="7";
    document.getElementById("birthMonth").setAttribute("class","SuccessField");
    document.getElementById("birthDay").value="7";
    document.getElementById("birthDay").setAttribute("class","SuccessField");

    var btnSubmit = document.getElementById("profile_enter")
    var ev = document.createEvent('HTMLEvents');
    ev.initEvent('click', true, true);
    btnSubmit.dispatchEvent(ev);

}

function playNow()
{
    var playnow = document.getElementById("playnow");
    var ev = document.createEvent('HTMLEvents');
    ev.initEvent('click', true, true);
    playnow.dispatchEvent(ev);


    setTimeout("selectBirthday()",100);
}
function main() {


    chrome.storage.local.get("more2step", function(valueArray) {
        var more2step = valueArray["more2step"];
        if(more2step == "true")
        {
            return;
        }

        var sDomain = window.document.domain;
        if (sDomain ==  "www.nutaku.net")
        {
            var sURL = window.document.documentURI;
            if(sURL == "http://www.nutaku.net/games/millennium-war-aigis/")
            {
                setTimeout("playNow()",1000);
            }
        }
    });
}

main();
