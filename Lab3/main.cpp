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
#include "Game.hpp"
//#include "Player.hpp"
//#include "cell.hpp"
//#include "movesList.hpp"

//using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

	char whichConstructor;
	std::cout << "Would you like to play the default game? or the custom game?(y for default, n for custom)";
	std::cin >> whichConstructor;
	std::cout << std::endl;
	if(whichConstructor == 'y'){
		Game game(true);
	}
	else if(whichConstructor == 'n'){
		Game game;
	}
	std::cout << "Game Over!" << std::endl;
    return 0;
}
