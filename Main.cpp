#ifndef MAIN_CPP
#define MAIN_CPP

/*

Project :   Universe
By      :   Mast
Date    :   August '14

*/

#include "Universe.hpp"

struct Planet;
struct Universe;

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
			<< "Or pick a coordinate/building to sort on:" << '\n'
			<< '\n'
			<< "1. X" << '\n'
			<< "2. Y." << '\n'
			<< "3. Z." << '\n'
			<< '\n'
			<< "4. Metal Mine." << '\n'
			<< "5. Crystal Mine." << '\n'
			<< "6. Deuterium Synthesizer." << '\n'
			<< '\n'
			<< "7. Metal Storage." << '\n'
			<< "8. Crystal Storage." << '\n'
			<< "9. Deuterium Storage." << '\n'
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
		case 7:
			Uno.sort_Mstor();
			break;
		case 8:
			Uno.sort_Cstor();
			break;
		case 9:
			Uno.sort_Dstor();
			break;
		case 999:
			exit = true;
			break;
		default:
			break;
		}

	}

}

#endif