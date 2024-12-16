TicketSearch()
{
	
	lr_start_transaction("TicketSearch");
	
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
			"Snapshot=t35.inf", 
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
			"Snapshot=t36.inf", 
			"Mode=HTML", 
			ITEMDATA, 
				"Name=userSession", "Value={userSession}", ENDITEM,
					"Name=username", "Value={Username}", ENDITEM,
					"Name=password", "Value={Password}", ENDITEM,
				"Name=login.x", "Value=55", ENDITEM,
				"Name=login.y", "Value=6", ENDITEM,
				"Name=JSFormSubmit", "Value=off", ENDITEM,
			LAST);
	
	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(10);	
	
		
	
	lr_start_transaction("GotoFlights");

			web_reg_find("Text=No. of Passengers :",
				LAST);

		web_reg_save_param_ex(
			"ParamName=seatPref_r",
			"LB=\"seatPref\" value=\"",
			"RB=\"",
			"Ordinal=ALL",
			SEARCH_FILTERS,
			"Scope=BODY",
			LAST);
		
		web_reg_save_param_ex(
			"ParamName=seatType_r",
			"LB=\"seatType\" value=\"",
			"RB=\"",
			"Ordinal=ALL",
			SEARCH_FILTERS,
			"Scope=BODY",
			LAST);
		
		web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t37.inf", 
			"Mode=HTML", 
			LAST);

		lr_save_string(lr_paramarr_random("seatPref_r"), "seatPref");
		
		lr_save_string(lr_paramarr_random("seatType_r"), "seatType");
	
	lr_end_transaction("GotoFlights",LR_AUTO);

	lr_think_time(10);	
	
		
		
	lr_start_transaction("FindFlight");
	
			web_reg_find("Text=<blockquote>Flight departing from <B>{depart}</B> to",
				LAST);

		web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t38.inf", 
			"Mode=HTML", 
			ITEMDATA, 
				"Name=advanceDiscount", "Value=0", ENDITEM,
					"Name=depart", "Value={depart}", ENDITEM,
					"Name=departDate", "Value={departDate}", ENDITEM,
					"Name=arrive", "Value={arrive}", ENDITEM,
					"Name=returnDate", "Value={returnDate}", ENDITEM,
				"Name=numPassengers", "Value=1", ENDITEM,
					"Name=seatPref", "Value={seatPref}", ENDITEM,
					"Name=seatType", "Value={seatType}", ENDITEM,
				"Name=findFlights.x", "Value=43", ENDITEM,
				"Name=findFlights.y", "Value=11", ENDITEM,
				"Name=.cgifields", "Value=roundtrip", ENDITEM,
				"Name=.cgifields", "Value=seatType", ENDITEM,
				"Name=.cgifields", "Value=seatPref", ENDITEM,
			LAST);
	
	lr_end_transaction("FindFlight",LR_AUTO);

	lr_think_time(10);
	
	
		
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

	// ������ ������ ���������� ��� �������
	
//		lr_output_message("Username: %s", lr_eval_string("{Username}"));
//		lr_output_message("Password: %s", lr_eval_string("{Password}"));
//		lr_output_message("Firstname: %s", lr_eval_string("{Firstname}"));
//		lr_output_message("Lastname: %s", lr_eval_string("{Lastname}"));
//		lr_output_message("StreetAddress (address1): %s", lr_eval_string("{StreetAddress}"));
//		lr_output_message("City (address2): %s", lr_eval_string("{City}"));
//		lr_output_message("pass1: %s", lr_eval_string("{Fullname}"));
//		lr_output_message("CrediCard: %s", lr_eval_string("{CreditCard}"));
//		lr_output_message("ExpDate: %s", lr_eval_string("{ExpiryDate}"));
//		lr_output_message("seatType: %s", lr_eval_string("{seatType}"));
//		lr_output_message("seatPref: %s", lr_eval_string("{seatPref}"));
//		lr_output_message("Depart city: %s", lr_eval_string("{depart}"));
//		lr_output_message("Arrive city: %s", lr_eval_string("{arrive}"));
//		lr_output_message("Depart date: %s", lr_eval_string("{departDate}"));
//		lr_output_message("Return date: %s", lr_eval_string("{returnDate}"));
//		lr_output_message("UserSession ID: %s", lr_eval_string("{userSession}"));
		
	// ����� ������ ���������� ��� �������	
	
	lr_end_transaction("TicketSearch",LR_AUTO);	
	
	return 0;
}