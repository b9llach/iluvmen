#include "gui.h"

void gui::printGUI(std::string weapon, std::string scope, std::string barrel)
{
	system("cls");
	std::cout << "================================================================================\n\n";

	std::cout << " (_) |_   ___   ___ __ ___   ___ _ __  \n";
	std::cout << " | | | | | \\ \\ / / '_ ` _ \\ / _ \\ '_ \\ \n";
	std::cout << " | | | |_| |\\ V /| | | | | |  __/ | | |\n";
	std::cout << " |_|_|\\__,_| \\_/ |_| |_| |_|\\___|_| |_|\n\n";

	std::cout << "================================================================================\n\n";

	std::cout << "@b9llach on ig | @172.16.1.1 on tiktok\n\n";

	std::cout << "================================================================================\n\n";

	std::cout << "AK - F2          | MP5 - F5\n";
	std::cout << "LR - F3          | CUSTOM - F6\n";
	std::cout << "TOMMY - F4       | IRONSIGHT - F10\n";
	std::cout << "HOLO - UP        | HANDMADE - LEFT\n";
	std::cout << "8x - RIGHT       | 16x - DOWN\n\n";		

	std::cout << "================================================================================\n\n";

	std::cout << "Weapon: " << weapon << "\n";
	std::cout << "Scope: " << scope << "\n";
	std::cout << "Barrel: " << barrel << "\n";
}
