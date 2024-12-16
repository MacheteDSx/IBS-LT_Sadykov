ItineraryList()
{

	lr_start_transaction("ItineraryList");	
	
	lr_start_transaction("GotoWebTours");
	
			web_reg_find("Text=Welcome to the Web Tours site",
				LAST);
	
		web_reg_save_param("userSession",
		    "LB=name=\"userSession\" value=\"", 
		    "RB=\"", 
		    "Ord=1", 
		    LAST);
	
		web_url("welcome.pl", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/WebTours/", 
			"Snapshot=t29.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("GotoWebTours",LR_AUTO);

	lr_think_time(15);
	
	
	
	lr_start_transaction("Login");
	
			web_reg_find("Text=Welcome, <b>{Username}</b>, to the Web Tours reservation pages.",
				LAST);
	
	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
			"Name=userSession", "Value={userSession}", ENDITEM, 
			"Name=username", "Value={Username}", ENDITEM, 
			"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=23", ENDITEM, 
		"Name=login.y", "Value=15", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	lr_think_time(20);
	
	
	
	lr_start_transaction("GotoItinerary");

			web_reg_find("Text={Fullname}\n 's Flight Transaction Summary",
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

	lr_end_transaction("GotoItinerary",LR_AUTO);
	
	
	
	lr_start_transaction("GotoHome");

			web_reg_find("Text=Welcome, <b>{Username}</b>, to the Web Tours reservation pages.",
				LAST);
	
		web_url("Home Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
			"Snapshot=t41.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("GotoHome",LR_AUTO);

	lr_think_time(10);
	
	
	
	lr_start_transaction("Logout");

			web_reg_find("Text=Welcome to the Web Tours site",
				LAST);	
	
		web_url("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t42.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("Logout",LR_AUTO);
	
	// Начало вывода переменных для отладки
	
//		lr_output_message("Username: %s", lr_eval_string("{Username}"));
//		lr_output_message("Password: %s", lr_eval_string("{Password}"));
//		lr_output_message("Firstname: %s", lr_eval_string("{Firstname}"));
//		lr_output_message("Lastname: %s", lr_eval_string("{Lastname}"));
//		lr_output_message("Lastname: %s", lr_eval_string("{Fullname}"));
//		lr_output_message("StreetAddress (address1): %s", lr_eval_string("{StreetAddress}"));
//		lr_output_message("UserSession ID: %s", lr_eval_string("{userSession}"));
		
	//  Конец вывода переменных для отладки	
	
	lr_end_transaction("ItineraryList",LR_AUTO);
	
	return 0;
}