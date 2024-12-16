Action()
{

	lr_start_transaction("Registration");

	lr_start_transaction("GoToWebTours");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("GoToWebTours",LR_AUTO);

	lr_start_transaction("SignUpNow");

	web_add_cookie("07-Dec-2024 15:58:17 GMT; DOMAIN=localhost");

	web_add_cookie("MSO=SID&1733673497; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=; DOMAIN=localhost");

	lr_think_time(19);

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("SignUpNow",LR_AUTO);

	lr_start_transaction("CustomerProfile");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_form("login.pl_2", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value=Raj", ENDITEM, 
		"Name=password", "Value=Koothrappali", ENDITEM, 
		"Name=passwordConfirm", "Value=Koothrappali", ENDITEM, 
		"Name=firstName", "Value=Raj", ENDITEM, 
		"Name=lastName", "Value=Koothrappali", ENDITEM, 
		"Name=address1", "Value=56 Maple Dr", ENDITEM, 
		"Name=address2", "Value=Pasadena", ENDITEM, 
		"Name=password", "Value=", ENDITEM, 
		"Name=passwordConfirm", "Value=", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("CustomerProfile",LR_AUTO);

	lr_think_time(29);

	lr_start_transaction("ThankYou");

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Ordinal=1", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("ThankYou",LR_AUTO);

	lr_think_time(28);

	lr_start_transaction("SignOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);

	lr_end_transaction("Registration",LR_AUTO);

	return 0;
}