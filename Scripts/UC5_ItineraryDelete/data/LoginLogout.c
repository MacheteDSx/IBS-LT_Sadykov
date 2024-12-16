LoginLogout()
{

	lr_start_transaction("GotoWebTours");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("12-Dec-2024 20:51:08 GMT; DOMAIN=localhost");

	web_add_cookie("MSO=SID&1734123068; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=; DOMAIN=localhost");

	lr_end_transaction("GotoWebTours",LR_AUTO);

	lr_start_transaction("Login");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(8);

	web_submit_form("login.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=username", "Value=Sheldon", ENDITEM, 
		"Name=password", "Value=Cooper", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(19);

	lr_start_transaction("Logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t9.inf", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	return 0;
}