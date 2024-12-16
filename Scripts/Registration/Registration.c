Registration()
{

	lr_start_transaction("Registration");
	
	lr_start_transaction("GotoWebTours");

			web_reg_find("Text=Welcome to the Web Tours site",
				LAST);
	
	web_reg_save_param("MSO_Value",
    "LB=MSO=SID&", 
    "RB=;", 
    "Ord=1", 
    LAST);

	lr_save_datetime("%d-%b-%Y %H:%M:%S GMT", DATE_NOW, "CookieDateTime");
	
	web_reg_save_param("UserSession", 
    "LB=name=\"userSession\" value=\"", 
    "RB=\"", 
    "Ord=1", 
    LAST);
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("GotoWebTours",LR_AUTO);
	
	lr_think_time(20);
	
		
	
	lr_start_transaction("ToSignUpNow");
	
			web_reg_find("Text=First time registering",
				LAST);

	web_add_cookie("{CookieDateTime} GMT; DOMAIN=localhost");

	web_add_cookie("MSO=SID&{MSO_Value}; DOMAIN=localhost");
	
	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("ToSignUpNow",LR_AUTO);

	lr_think_time(50);
	
		
	
	lr_start_transaction("ToRegister");

			web_reg_find("Text=<blockquote>Thank you, <b>{Username}</b>,",
				LAST);
	
	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_form("login.pl_2", 
		"Snapshot=t25.inf", 
		ITEMDATA, 
		"Name=username", "Value={Username}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=passwordConfirm", "Value={Password}", ENDITEM, 
		"Name=firstName", "Value={Firstname}", ENDITEM, 
		"Name=lastName", "Value={Lastname}", ENDITEM, 
		"Name=address1", "Value={StreetAddress}", ENDITEM, 
		"Name=address2", "Value={City}", ENDITEM,
		"Name=register.x", "Value=57", ENDITEM, 
		"Name=register.y", "Value=15", ENDITEM, 
		LAST);
	
	lr_end_transaction("ToRegister",LR_AUTO);

	lr_think_time(30);
	
		

	lr_start_transaction("ThankYouForRegister");

			web_reg_find("Text=Welcome, <b>{Username}</b>, to the Web Tours reservation pages",
				LAST);
	
	web_image("button_next.gif",
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t26.inf", 
		LAST);

	lr_end_transaction("ThankYouForRegister",LR_AUTO);

	lr_think_time(10);
	
	
	
	lr_start_transaction("Logout");

		web_reg_find("Text=Welcome to the Web Tours site",
			LAST);

	web_image("SignOff Button",
		"Alt=SignOff Button", 
		"Snapshot=t27.inf", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);
	
	// Ќачало вывода переменных дл€ отладки
	
//		lr_output_message("Username: %s", lr_eval_string("{Username}"));
//		lr_output_message("Password: %s", lr_eval_string("{Password}"));
//		lr_output_message("Firstname: %s", lr_eval_string("{Firstname}"));
//		lr_output_message("Lastname: %s", lr_eval_string("{Lastname}"));
//		lr_output_message("StreetAddress (address1): %s", lr_eval_string("{StreetAddress}"));
//		lr_output_message("City (address2): %s", lr_eval_string("{City}"));
//		lr_output_message("pass1: %s", lr_eval_string("{Fullname}"));
//		lr_output_message("CrediCard: %s", lr_eval_string("{CreditCard}"));
//		lr_output_message("ExpDate: %s", lr_eval_string("{ExpiryDate}"));
//		lr_output_message("UserSession ID: %s", lr_eval_string("{userSession}"));
		
	//  онец вывода переменных дл€ отладки

	lr_end_transaction("Registration",LR_AUTO);
	
	return 0;
}