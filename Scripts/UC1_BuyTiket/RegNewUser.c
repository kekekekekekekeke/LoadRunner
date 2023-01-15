RegNewUser()
{
	lr_start_transaction("UC7_RegNewUser");

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
		
	web_reg_find("Fail=NotFound",
		"Text/IC=<b>sign up now</b>",
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
	
	lr_start_transaction("reg_new_user");
	
	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(6);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("reg_new_user",LR_AUTO);

	lr_start_transaction("Customer_Profile");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Thank you, <b>{generatorName}{generatorPart}{generatorBlock}{generatorBlock_2}</b>", // не понял в чем косяк
//  		"Text/IC=Thank you,",
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(77);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={generatorName}{generatorPart}{generatorBlock}{generatorBlock_2}", ENDITEM, 
		"Name=password", "Value=12345", ENDITEM, 
		"Name=passwordConfirm", "Value=12345", ENDITEM, 
		"Name=firstName", "Value={generatorName}{generatorPart}{generatorBlock}{generatorBlock_2}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address}{expDateYear}", ENDITEM, 
		"Name=address2", "Value={depart}", ENDITEM, 
		"Name=register.x", "Value=66", ENDITEM, 
		"Name=register.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("Customer_Profile",LR_AUTO);

	lr_start_transaction("Thank");
	
//	web_reg_find("Fail=NotFound",
//		"Text/IC=Thank you,<b>{generatorName}{generatorPart}{generatorBlock}{generatorBlock_2}</b>",
//		LAST);
	

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(28);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Thank",LR_AUTO);

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
	
	lr_end_transaction("UC7_RegNewUser",LR_AUTO);
	return 0;
}
