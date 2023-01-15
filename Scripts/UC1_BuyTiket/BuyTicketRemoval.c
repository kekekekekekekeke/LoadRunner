BuyTicketRemoval()
{
	lr_start_transaction("UC6_BuyTicketRemoval");

	lr_start_transaction("open_site");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_header("sec-ch-ua", 
		"\"Not?A_Brand\";v=\"8\", \"Chromium\";v=\"108\", \"Google Chrome\";v=\"108\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	web_add_header("sec-ch-ua-platform", 
		"\"Windows\"");

/*Correlation comment - Do not change!  Original value='135437.009801539zQzzftVpVQVzzzzHtVHQQpctHVf' Name ='userSession' Type ='ResponseBased'*/
//	web_reg_save_param_attrib(
//		"ParamName=userSession",
//		"TagName=input",
//		"Extract=value",
//		"Name=userSession",
//		"Type=hidden",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		"RequestUrl=*/nav.pl*",
//		LAST);
	

	web_reg_save_param("userSession",
		"LB/IC=\" value=\"",
		"RB/IC=\"",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	lr_end_transaction("open_site", LR_AUTO);

	/* Login step */

	lr_start_transaction("login"); // авторизация
	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not?A_Brand\";v=\"8\", \"Chromium\";v=\"108\", \"Google Chrome\";v=\"108\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(117);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=47", ENDITEM,
		"Name=login.y", "Value=5", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);
	
	lr_start_transaction("Flightts");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(136);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Flightts",LR_AUTO);
	
	
	lr_start_transaction("ticket");
	
	
	web_reg_find("Text/IC=<B>{depart}</B> to <B>{arrive}</B>", LAST);
	web_reg_find("Text/IC=<B>{arrive}</B> to <B>{depart}</B>",	LAST);

	lr_think_time(4);


	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(45);
	
	web_reg_save_param("outboundFlight",
		"LB=outboundFlight\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);
	
	web_reg_save_param("returnFlight",
		"LB=returnFlight\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);

	web_submit_data("reservations.pl_5", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=2", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=44", ENDITEM, 
		"Name=findFlights.y", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("ticket",LR_AUTO);

	lr_think_time(47);

	lr_start_transaction("from_to");
	
	
	
	lr_save_string(lr_paramarr_random("outboundFlight"), "outboundFlight_random");
	lr_save_string(lr_paramarr_random("returnFlight"), "returnFlight_random");

	web_submit_data("reservations.pl_6", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight_random}", ENDITEM, 
		"Name=returnFlight", "Value={returnFlight_random}", ENDITEM, 
		"Name=numPassengers", "Value=2", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=66", ENDITEM, 
		"Name=reserveFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("from_to",LR_AUTO);
	

	lr_start_transaction("payment_details");
	
	web_reg_find("Text/IC=Reservation Requests", LAST);
	web_reg_find("Text/IC=from {depart} to {arrive}", LAST);
	web_reg_find("Text/IC=<B>{generatorName}{login}{generatorPart}{generatorBlock}{generatorBlock_2}{lastName}'s Flight Invoice</B>", LAST);
	
	//lr_save_string("Value={generatorName}{generatorPart}{generatorBlock}{generatorBlock_2}", "firstName");

	
	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(42);
	
	web_submit_data("reservations.pl_7", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		//"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=firstName", "Value={generatorName}{login}{generatorPart}{generatorBlock}{generatorBlock_2}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address}{expDateYear}", ENDITEM, 
		"Name=address2", "Value={depart}", ENDITEM, 
		"Name=pass1", "Value={generatorPart}{generatorBlock}{generatorBlock_2}{login}", ENDITEM, 
		"Name=pass2", "Value={generatorPart}{generatorBlock}{generatorBlock_2}{login}", ENDITEM, 
		"Name=creditCard", "Value={creditCardHome}{creditCardEnd}", ENDITEM, 
		"Name=expDate", "Value={expDateMonth}/{expDateYear}", ENDITEM, 
		"Name=oldCCOption", "Value=on", ENDITEM, 
		"Name=numPassengers", "Value=2", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight_random}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={returnFlight_random}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=62", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("payment_details",LR_AUTO);

	
	
	lr_start_transaction("invoice");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(19);

	web_submit_data("reservations.pl_8", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=45", ENDITEM, 
		"Name=Book Another.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("invoice",LR_AUTO);



	lr_start_transaction("del");
	
	web_reg_find("Text/IC={generatorName}{login}{generatorPart}{generatorBlock}{generatorBlock_2}", LAST);
	
	web_reg_save_param("flightID",
		"LB/IC=\" value=\"",
		"RB/IC=\"",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(9);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(33);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value={flightID}", ENDITEM, 
		"Name=removeFlights.x", "Value=64", ENDITEM, 
		"Name=removeFlights.y", "Value=15", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		LAST);

	lr_end_transaction("del",LR_AUTO);
	
	lr_start_transaction("Logout");
	
	web_reg_find("Text/IC=Welcome to the Web Tours site", LAST);

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(185);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);
	
	lr_end_transaction("UC6_BuyTicketRemoval",LR_AUTO);
	return 0;
}
