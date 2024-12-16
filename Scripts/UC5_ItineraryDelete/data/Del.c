Del()
{

	web_add_cookie("14-Dec-2024 17:55:24 GMT; DOMAIN=localhost");

	web_add_cookie("MSO=SID&1734285324; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=firstName&Amy&address2&Pasadena&username&Amy&hash&89&lastName&Farrah%20Fowler%0A&address1&34%20Palm%20Blvd&creditCard&&expDate&%0A; DOMAIN=localhost");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("14-Dec-2024 19:15:34 GMT; DOMAIN=localhost");

	web_add_cookie("MSO=SID&1734290134; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=; DOMAIN=localhost");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(21);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=140485.227541515HcczcAipiQVzzzzHtDDfHpcfDDf", ENDITEM, 
		"Name=username", "Value=Leonard", ENDITEM, 
		"Name=password", "Value=Hofstadter", ENDITEM, 
		"Name=login.x", "Value=68", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("Del");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(12);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=251445238-802-LH", ENDITEM, 
		"Name=flightID", "Value=251445238-1572-LH", ENDITEM, 
		"Name=flightID", "Value=210297090-2341-SC", ENDITEM, 
		"Name=flightID", "Value=2514444-30-LH", ENDITEM, 
		"Name=flightID", "Value=2514444-38-LH", ENDITEM, 
		"Name=6", "Value=on", ENDITEM, 
		"Name=flightID", "Value=251450386-4648-LH", ENDITEM, 
		"Name=removeFlights.x", "Value=19", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("Del",LR_AUTO);

	return 0;
}