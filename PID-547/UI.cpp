#include<iostream>

#include "NewsAPI.h"
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
	std::cout << " [7] Exit \n";
	std::cout << "====================================================\n";

	try
	{
		std::cin >> opt;
		if (opt != 1 && opt != 2 && opt != 7) { throw opt; }
	}
	catch (int ex) { std::cout << "[!!!] " << ex << " is an Invalid Choice [!!!]\n"; system("pause"); return -2; }

	Users users;
	switch (opt)
	{
		case 1: // LOGIN FUNCTION
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

		case 2: // REGISTER FUNCTION
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

		case 7: // Exit
		{
			std :: cout << "Exited Successfully \n";
			system("pause");

			return 7;
		}
	}
}

int loggedinWindow()
{
	
	// RETURN VALUES :
	// [1] News Checking Complete
	// [2] Submit a review
	// [3] Manual
	
	// [7] Exit


	int opt;

	std::cout << "\t\t Welcome to Gullible \n";
	std::cout << "====================================================\n";
	std::cout << " [1] Check News \n";
	std::cout << " [2] Submit A Review \n";
	std::cout << " [3] Manual \n";
	std::cout << " [7] Exit \n";
	std::cout << "====================================================\n";
	std::cin >> opt;

	switch (opt)
	{
		case 1:
		{
			NewsAPI newsapi;
			std::string news;
			
			news = newsapi.getNews();
			news = newsapi.cleanstring(news);

			std::cout << news + '\n';


			return 1;

		}break;

		case 7:
		{
			return 7;
		}
	}

}