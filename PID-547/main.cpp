#include<iostream>
#include<windows.h>

#include"UI.h"

int main()
{
	int opt;

	do
	{
		system("cls");
		mainWindow();  // From UI 

		try
		{
			std::cin >> opt;

			if (opt >= 4 && opt != 7)
			{
				throw opt;
			}

			switch (opt)
			{
			case 1:
			{
				int choice;
				do
				{
					choice = login_register_form();

				} while (choice != 1);

				if (choice == 1)
				{
					std::cout << " (+) Logged In Succesfully (+) \n";
					system("pause");
				}

			}break;

			}


		}

		catch (int ex)
		{
			std::cout << "[!!!] " << ex << " is an Invalid Option" << "[!!!] \n";
			system("pause");
		}
	} while (opt != 7);

	return 0;

}