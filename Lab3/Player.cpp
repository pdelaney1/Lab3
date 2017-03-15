#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Player.hpp"
#include "cell.hpp"

Player::Player() {
// constructor for an actual human, that uses cin to ask the user for their name and the character they want to
//use in the game, and initializes the name and c fields to the entered information.  It also initializes score to 0, and
//isComputer to false.
	std::cout << "What is your name?: ";
	std::string n;
	std::cin >> n;
	std::cout << std::endl;
	name = n;
	std::cout
			<< "What character would like to use? (input a letter that is not a, b, c, d, or e): ";
	char t;
	std::cin >> t;
	std::cout << std::endl;
	c = t;
	score = 0;
	isComputer = false;
}

Player::Player(std::string n, char ic, bool x) {
// constructor that takes as input parameters a name string, a character ic, and a Boolean value x and sets the name, the c, and the isComputer fields accordingly.  It initializes the score to 0
	name = n;
	c = ic;
	score = 0;
	isComputer = x;
}
