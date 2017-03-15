#include "cell.hpp"

cell::cell() { //initializes x and y to -1 (not on board)
	x = -1;
	y = -1;
}

cell::cell(int a, int b) {  // initializes x to a and y to b
	x = a;
	y = b;
}
void cell::resetCell(int a, int b) {  // resets x to a and y to b
	x = a;
	y = b;
}
