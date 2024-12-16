LoginLogout()
{

	lr_start_transaction("LoginLogout");
	
	lr_start_transaction("GotoWebTours");

			web_reg_find("Text=Welcome to the Web Tours site",
				LAST);
	
		web_url("welcome.pl",
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/WebTours/", 
			"Snapshot=t7.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("GotoWebTours",LR_AUTO);

	lr_think_time(10);
	
	
	
	lr_start_transaction("Login");

			web_reg_find("Text=Welcome, <b>{Username}</b>, to the Web Tours reservation pages",
				LAST);

		web_submit_form("login.pl", 
			"Snapshot=t8.inf", 
			ITEMDATA, 
				"Name=username", "Value={Username}", ENDITEM, 
				"Name=password", "Value={Password}", ENDITEM, 
			LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(20);
	
		

	lr_start_transaction("Logout");

			web_reg_find("Text=Welcome to the Web Tours site",
				LAST);	
	
		web_image("SignOff Button",
			"Alt=SignOff Button", 
			"Snapshot=t9.inf", 
			LAST);

	lr_end_transaction("Logout",LR_AUTO);	

//	// Ќачало вывода переменных дл€ отладки
//	
//		lr_output_message("Username: %s", lr_eval_string("{Username}"));
//		lr_output_message("Password: %s", lr_eval_string("{Password}"));
//		
//	//  онец вывода переменных дл€ отладки	
	
	lr_end_transaction("LoginLogout",LR_AUTO);
	return 0;
}