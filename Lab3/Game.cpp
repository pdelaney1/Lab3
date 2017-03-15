#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Game.hpp"

Game::Game() {
    // for non-automatized version – asks for board size, num players, num of computer players,
    // and then initializes everything
	int Size;
	int numOfPlayers;
	int numOfComps;
    std::cout << "What board size would you like? (between 3 - 11): ";
    std::cin >> Size;
    std::cout << std::endl;
    size = Size;
    std::cout << "How many people are playing?: ";
    std::cin >> numOfPlayers;
    std::cout << std::endl;
    numPlayers = numOfPlayers;
    std::cout << "How many computer players?: ";
    std::cin >> numOfComps;
    std::cout << std::endl;
    compplayers = numOfComps;
    turn = 0;
    boardFull = false;
    board = makeBoard();
    printBoard();
//    while (numPlayers + compplayers > 5) {
//        std::cout << "Error! There are too many players on the board"
//                << std::endl;
//        std::cout << "How many people are playing?: ";
//        std::cin >> numPlayers;
//        std::cout << std::endl;
//        std::cout << "How many computer players?: ";
//        std::cin >> compplayers;
//        std::cout << std::endl;
//    }
    //size = Size;
    //numPlayers = numOfPlayers;
    //compplayers = numOfComputers;
    getPlayers();
    playGame();
}

Game::Game(bool b) {
    //for the automated version – if b is true, randomly generate the size of the board, set the num of players and the
    //num of compplayers to 2, and the, of course initialize everything
    if (b == true) {
        int Size = (rand() % 9) + 3; // generates random number between 3 and 11
        size = Size;
        numPlayers = 2;
        compplayers = 2;
        turn = 0;
        boardFull = false;
        makeBoard();
        getPlayers();
        playGame();
    }
}

void Game::makeBoard() {
    // dynamically generates the board to be size by size, with each cell initially set to ‘.’
    //your code goes here
	char *tmp[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tmp[i][j] = ',';
        }
        board = &tmp[i];
    }
}

void Game::printBoard() {
    //Note: I’m giving you this one
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Game::getPlayers() {
    //This method dynamically generates an array of players, and then, for each element in the array, creates a new
    //player object with a name and a character.  For the number of players that are computers, I used an array of names
    // and an array of characters, and then just selected the next name and character in the list for my player object.
    // for humans I called the Player constructor with no input parameters (that one asked the user for their name and
    // their prefered character.
    // your code goes here
    Player player[numPlayers + compplayers];
    for (int i = 0; i < numPlayers; i++) {
        player[i] = Player();
    }
    //char chars[] = "a";
    char chars[] = {'a','b','c','d','e'};
    for (int j = numPlayers; j < (numPlayers + compplayers); j++) {
    	std::string s(1,char(j));
        std::string n = "Computer" + s;
        // There are a maximum of 5 players on the board so we need only five letters for the computers
        // We will check to make sure the jth value in ic is not being used by a human player.
        // If it is not then we will use the jth char for compplayer, else we check the (j+1)th value... etc
        player[j] = Player(n, chars[j], true);
        players[j] = &player[j];
    }
}

void Game::printPlayers() {
    // this method is optional – I wrote it so I could test my getPlayers() method to make sure it generated all my Players
    // correctly.  If you choose not to include this method, that is fine.
    for (int i = 0; i < (numPlayers + compplayers); i++) {
        std::cout << players[i];
        std::cout << std::endl;
    }
}

void Game::playGame() {
    // This is the heart of the game.  I called this method directly from my Game constructor(s) as the very last thing.
    //This method loops until the board is full.
    // In each loop, the next player either chooses where to place their character (if human) or the x,y coordinates are
    // randomly generated (and checked to make sure the player isn’t overwriting a piece already on the board).
    //It checks to see if the new piece completes a square, and, if so, that player’s score goes up by 1 and that player
    // takes another turn.  At the end of each round, the board is printed out and each player’s name and score is printed.

    //Your code goes here
    int i = 0;
    while (boardFull != true) {
        printBoard();
        int move = turn;
        //temporarily assume the user makes a valid move;
        if (players[i % (numPlayers + compplayers)]->isComputer == true) {
            bool playerMove = true;
            int j = 0;
            while (playerMove == true) {
                while (j < size) {
                    int k = 0;
                    while (k < size) {
                        if (board[j][k] == ',') {
                            board[j][k] =
                                    players[i % (numPlayers + compplayers)]->c;
                            if (checkFour(j, k) == true) {
                                players[i % (numPlayers + compplayers)]->score =
                                        players[i % (numPlayers + compplayers)]->score
                                        + 1;
                                        turn = turn + 1;
                                        move = turn;
                            } else {
                                playerMove = false;
                                break;
                            }
                            move = move + 1;
                        }
                        k++;
                    }
                    if (move < turn || playerMove == false) {
                        break;
                    }
                    j++;
                }
            } //if
        } else {
            bool playerMove = true;
            while (playerMove == true) {
                std::cout << "Which x-coordinate would "
                        << players[i % (numPlayers + compplayers)]->name
                        << " like to use? (0 through " << size - 1 << ") ";
                int x;
                std::cin >> x;
                std::cout << std::endl;
                std::cout << "Which y-coordinate would "
                        << players[i % (numPlayers + compplayers)]->name
                        << " like to use? (0 through " << size - 1 << ") ";
                int y;
                std::cin >> y;
                std::cout << std::endl;
                board[x][y] = players[i % (numPlayers + compplayers)]->c;
                if (checkFour(x, y) == true) {
                    players[i % (numPlayers + compplayers)]->score = players[i
                            % (numPlayers + compplayers)]->score + 1;
                    turn = turn+1;
                    move = turn;
                } else {
                    playerMove = false;
                    turn = turn+1;
                }
            }
        } //else
        if (turn == (size * size)) {
            boardFull = true;
        }

    }
    printBoard();
    //Note: for the extra credit version, the findMoves method returns a dynamically created array of 3 different moveLists.
    // The first of the 3  contains the list of moves that would complete a square. The second of the 3 contains a list of
    // neutral moves, and the third of the 3 contains the list of moves that place a third corner on a square (which are bad
    // moves because the next player will then be able to complete a square.
    // In this version, the next move is chosen by first trying to pick (randomly) among potential moves that would
    // complete a square, and then by trying to pick a move that is, in essence, neutral, and then last, it chooses from the
    // list of bad moves as a last resort.
    getWinner();
    std::cout << std::endl;
}

//bool findMoves(char v);
//    Regular version, this method continues to generate random x,y values until that cell on the
//    board is empty, then places the player's character v on the board, and checks to see if a
//    square is completed using checkFour.  If so, true is returned and that player’s score goes up by 1 in the
//    playGame method, and that player gets to take another turn (so turn does not increase by 1).

// movesList * Game::findMoves(char v) {
// The extra credit version of this method – this method dynamically creates a list of 3 movesList objects.  It then goes
// through the entire board and classifies each possible move left on the board as being either good (will complete a
// square, in which case it’s added to the new list of movesLists at [0], neutral (doesn’t do anything), in which it’s
// added to the second of the movesLists, or bad (3/4 of a square), in which case it’s added to the third of the
// movesLists.
// This method uses checkFour() method to determine whether a move is good, checkThree to determine if a move is
// bad, and if neither of those is true, then the move is considered neutral.
// This method returns the list of three movesList objects.
//}

bool Game::checkFour(int x, int y) {
    // this method checks to see if placing a piece at x and y on the board will complete a square, and, if so, it
    // returns true.  Otherwise it returns false.
    if (x == 0) {
        if (y == 0) {
            if ((board[0][1] != ',') && (board[1][0] != ',')
                    && (board[1][1] != ',')) {
                return true;
            }//if((board[0][1]....
            else {
                return false;
            } //else
        }//if(y==0)
        else if (y == size) {
            if ((board[0][size - 1] != ',') && (board[1][size] != ',')
                    && (board[1][size - 1] != ',')) {
                return true;
            }//if((board[0][size-1]....
            else {
                return false;
            } //else
        }//else if
        else {
            if (((board[0][y - 1] != ',') && (board[1][y] != ',')
                    && (board[1][y - 1] != ','))
                    || ((board[0][y + 1] != ',') && (board[1][y] != ',')
                    && (board[1][y + 1] != ','))) {
                return true;
            }//if((board[0][size-1]....
            else {
                return false;
            } //else
        }
    } else if (x == size) {
        if (y == 0) {
            if ((board[size][1] != ',') && (board[size - 1][0] != ',')
                    && (board[size - 1][1] != ',')) {
                return true;
            }//if((board[size][1]....
            else {
                return false;
            } //else
        }//if(y==0)
        else if (y == size) {
            if ((board[size][size - 1] != ',') && (board[size - 1][size] != ',')
                    && (board[size - 1][size - 1] != ',')) {
                return true;
            }//if((board[size][size-1]....
            else {
                return false;
            } //else
        } else {
            if (((board[size][y - 1] != ',') && (board[size - 1][y] != ',')
                    && (board[size - 1][y - 1] != ','))
                    || ((board[size][y + 1] != ',')
                    && (board[size - 1][y] != ',')
                    && (board[size - 1][y + 1] != ','))) {
                return true;
            }//if((board[0][size-1]....
            else {
                return false;
            } //else
        }
    }
    return false;
}

void Game::getWinner() {
    // This method determines which of the players in the array of Players has the highest score, and prints out
    // that player’s name and their score.
    int pos = 0;
    int highScore = players[0]->score;
    for (int i = 0; i < (numPlayers + compplayers); i++) {
        if ((players[i]->score) > highScore) {
            highScore = players[i]->score;
            pos = i;
        }
    }
    std::cout << "The winner is " << players[pos]->name << " with a score of "
            << highScore << "!";
    std::cout << std::endl;
}

//bool Game::checkThree(int x, int y) {
// Only needed for Extra Credit
// This method determines whether placing a piece on the board at x and y will complete ¾ of a square and, if so, it
// returns true.  Otherwise it returns false.
//}
