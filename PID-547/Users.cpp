#include<iostream>
#include<fstream>
#include<string>

#include"Users.h"

std::string USERS_FILE_LOCATION = "..\\database\\Users.txt";

int Users::login_form() // RETURNS [1] Auth Succesfull  ;  [-1] Incorrect Creds  ;  [404] File Not Found
{
	std::cout << "====================================================\n";
	std::cout << " [*] Username: ";
	std::cin >> __username__;
	std::cout << " [*] Password: ";
	std::cin >> __passwd__;

	std::ifstream FILE;
	FILE.open(USERS_FILE_LOCATION);

	if (!FILE.is_open())
	{
		return 404;
	}

	std::string filedata;
	std::string mydata = __username__ + ":" + __passwd__;
	while (getline(FILE, filedata))
	{
		if (mydata == filedata)
		{
			return 1;
		}
	}

	return -1;

}

int Users::register_form() // return [2] Reg Successful  ;  [404] File not Found 
{
	std::cout << "====================================================\n";
	std::cout << " [*] Username: ";
	std::cin >> __username__;
	std::cout << " [*] Password: ";
	std::cin >> __passwd__;


	std::ofstream FILE(USERS_FILE_LOCATION, std::ios::app);
	if (!FILE.is_open())
	{
		return 404;
	}

	std::string data = __username__ + ":" + __passwd__ + "\n";
	FILE << data;

	return 2;

}