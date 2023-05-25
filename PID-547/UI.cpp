#include<iostream>

#include "Users.h"
#include "UI.h"

void mainWindow()
{
	std::cout << "\t\t Welcome to Gullible \n";
	std::cout << "====================================================\n";
	std::cout << " [1] Check Out Gullible \n";
	std::cout << " [2] Buy Gullible \n";
	std::cout << " [3] What Is Gullible \n";
	std::cout << " [4] About Us \n";
	std::cout << "====================================================\n";

}

int login_register_form()
{

	// return values:
	//  [1] Login Successfull 
	//	[2] Registration Successfull

	//  [-1] Invalid Username or Password
	//  [-2] Invalid Choice

	// [404] User.txt is missing

	system("cls");

	int opt;

	std::cout << "\t\t Welcome to Gullible \n";
	std::cout << "====================================================\n";
	std::cout << " [1] Login \n";
	std::cout << " [2] Register \n";
	std::cout << "====================================================\n";

	try
	{
		std::cin >> opt;
		if (opt != 1 && opt != 2) { throw opt; }
	}
	catch (int ex) { std::cout << "[!!!] " << ex << " is an Invalid Choice [!!!]\n"; system("pause"); return -2; }

	Users users;
	switch (opt)
	{
	case 1:
	{
		int auth = users.login_form();

		switch (auth)
		{
		case 1:
		{
			std::cout << " (+) Logged In Succesfully (+) \n";
			system("pause");
		}break;

		case -1:
		{
			std::cout << " (-) Credentials Incorrect (-) \n";
			system("pause");
		}break;

		case 404:
		{
			std::cerr << "[!!!] FILE Users.txt is Missing [!!!] \n";
			system("pause");
		}

		}


		return auth;
	}break;

	case 2:
	{
		int if_reg = users.register_form();

		switch (if_reg)
		{
		case 2:
		{
			std::cout << " (+) Registered Succesfully (+) \n";
			system("pause");
		}break;

		case 404:
		{
			std::cerr << "[!!!] FILE Users.txt is Missing [!!!] \n";
			system("pause");
		}
		}

		return if_reg;
	}break;
	}
}

