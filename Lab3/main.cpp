/* Debra Yarrington
 * Taghreed Bagies
 * 3/16/17
 * Logan Montrone, Peter Delaney CISC 220
 * This file contains functions for lab 3.  The functions are not necessarily related
 * in any way other than that they are required for lab 3.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Game.hpp"
//#include "Player.hpp"
//#include "cell.hpp"
//#include "movesList.hpp"

//using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

	std::cout << "888888ba             dP                  d88b        888888ba\n";
	std::cout << "88    `8b            88                  8`'8        88    `8b\n";
	std::cout << "88     88 .d8888b. d8888P .d8888b.       d8b        a88aaaa8P' .d8888b. dP.  .dP .d8888b. .d8888b.\n";
	std::cout << "88     88 88'  `88   88   Y8ooooo.     d8P`8b        88   `8b. 88'  `88  `8bd8'  88ooood8 Y8ooooo.\n";
	std::cout << "88    .8P 88.  .88   88         88     d8' `8bP      88    .88 88.  .88  .d88b.  88.  ...       88\n";
	std::cout << "8888888P  `88888P'   dP   `88888P'     `888P'`YP     88888888P `88888P' dP'  `dP `88888P' `88888P'\n";
	std::cout << "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n";
	std::cout << std::endl;
	std::cout << "       ____  _  _  _    __     __    ___   __   __ _     ___    ____  ____  ____  ____  ____\n";
	std::cout << "      (  _ \\( \\/ )(_)  (  )   /  \\  / __) / _\\ (  ( \\   ( _ \\  (  _ \\(  __)(_  _)(  __)(  _ \\\n";
	std::cout << "       ) _ ( )  /  _   / (_/\\(  O )( (_ \\/    \\/    /  / _  /   ) __/ ) _)   )(   ) _)  )   /\n";
	std::cout << "      (____/(__/  (_)  \\____/ \\__/  \\___/\\_/\\_/\\_)__)  \\__\\_)  (__)  (____) (__) (____)(__\\_)\n";

	bool play = true;
	char whichConstructor;
	while(play == true){
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Would you like to play the default game? or a custom game?" << std::endl;
		std::cout << "type y for default or n for custom (choose y/n): ";
		std::cin >> whichConstructor;
		std::cout << std::endl;
		bool invalid = (whichConstructor == 'y' || whichConstructor == 'n');
		while(invalid != true){
			std::cout << "I'm sorry, I did not understand that. Try again. (choose y/n): ";
			std::cin >> whichConstructor;
			std::cout << std::endl;
			invalid = (whichConstructor == 'y' || whichConstructor == 'n');
		}
		if(whichConstructor == 'y'){
			Game game(true);
		}
		else if(whichConstructor == 'n'){
			Game game;
		}

		std::cout << " _______  _______  __   __  _______    _______  __   __  _______  ______    __\n";
		std::cout << "|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  |  |\n";
		std::cout << "|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  |  |\n";
		std::cout << "|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ |  |\n";
		std::cout << "|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  ||__|\n";
		std::cout << "|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | | __\n";
		std::cout << "|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_||__|\n";
		std::cout << std::endl;
		std::cout << "Play again? (choose y/n)" << std::endl;
		std::cin >> whichConstructor;
		std::cout << std::endl;
		invalid = (whichConstructor == 'y' || whichConstructor == 'n');
		while(invalid != true){
			std::cout << "I'm sorry, I did not understand that. Try again. (choose y/n): ";
			std::cin >> whichConstructor;
			std::cout << std::endl;
			invalid = (whichConstructor == 'y' || whichConstructor == 'n');
		}
		if(whichConstructor == 'n'){
			play = false;
		}
	//std::cout << "Game Over!" << std::endl;
	}
    return 0;


}
