Action1()
{

	lr_start_transaction("Del");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Priority", 
		"u=4");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(56);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=169148942-802-LW", ENDITEM, 
		"Name=flightID", "Value=169150825-1559-LW", ENDITEM, 
		"Name=removeFlights.x", "Value=50", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		LAST);

	lr_end_transaction("Del",LR_AUTO);

	return 0;
}