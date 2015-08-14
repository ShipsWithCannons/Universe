/*

Project	: Universe
By		: Mast
Date	: August '14

*/

#include "Universe.hpp"

int main()
{
	Universe Uno("Uno");
	Uno.readCSV();

	bool exit = false;
	while (!exit)
	{
		system("cls");
		std::cout << "Welcome to the Galaxy Management Unit (GMU)." << '\n'
			<< '\n'
			<< "0. Print." << '\n'
			<< '\n'
			<< "1. Sort X." << '\n'
			<< "2. Sort Y." << '\n'
			<< "3. Sort Z." << '\n'
			<< '\n'
			<< "4. Sort Mlvl." << '\n'
			<< "5. Sort Clvl." << '\n'
			<< "6. Sort Dlvl." << '\n'
			<< '\n'
			<< "999. Exit." << '\n'
			<< '\n'
			<< "Choice: "
			;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			Uno.printUniverse();
			std::cin.sync();
			std::cin.clear();
			std::cin.get();
			break;
		case 1:
			Uno.sort_x();
			break;
		case 2:
			Uno.sort_y();
			break;
		case 3:
			Uno.sort_z();
			break;
		case 4:
			Uno.sort_Mlvl();
			break;
		case 5:
			Uno.sort_Clvl();
			break;
		case 6:
			Uno.sort_Dlvl();
			break;
		case 999:
			exit = true;
			break;
		default:
			break;
		}

	}

}