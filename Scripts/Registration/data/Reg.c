Reg()
{

	lr_start_transaction("GotoWebTours");

	web_add_cookie("12-Dec-2024 17:08:49 GMT; DOMAIN=localhost");

	web_add_cookie("MSO=SID&1734109729; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=; DOMAIN=localhost");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("GotoWebTours",LR_AUTO);

	lr_start_transaction("ToSignUpNow");

	web_add_cookie("12-Dec-2024 17:18:09 GMT; DOMAIN=localhost");

	web_add_cookie("MSO=SID&1734110289; DOMAIN=localhost");

	lr_think_time(22);

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("ToSignUpNow",LR_AUTO);

	lr_start_transaction("ToRegister");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(50);

	web_submit_form("login.pl_2", 
		"Snapshot=t25.inf", 
		ITEMDATA, 
		"Name=username", "Value=User1", ENDITEM, 
		"Name=password", "Value=qwer1234", ENDITEM, 
		"Name=passwordConfirm", "Value=qwer1234", ENDITEM, 
		"Name=firstName", "Value=Name", ENDITEM, 
		"Name=lastName", "Value=Last", ENDITEM, 
		"Name=address1", "Value=Street", ENDITEM, 
		"Name=address2", "Value=City", ENDITEM, 
		"Name=password", "Value=", ENDITEM, 
		"Name=passwordConfirm", "Value=", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("ToRegister",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("ThankYouForRegister");

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t26.inf", 
		LAST);

	lr_end_transaction("ThankYouForRegister",LR_AUTO);

	lr_think_time(11);

	lr_start_transaction("Logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t27.inf", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	return 0;
}