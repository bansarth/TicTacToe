#include "TicTacToe.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Hello, welcome to TicTacToe\n"
		"Which version of TicTacToe would you like to play:\n"
		"1. Two Player Mode\n"
		"2. Player vs. Bot (Easy Mode)\n"
		"3. Player vs. Bot (Hard Mode)\n";
	int version;
	cin >> version;
	TTT board;
	if (version == 1) {
		board.twoPlayerMode();
	}
	else if (version == 2) {
		board.levelOneBot();
	}
	else if (version == 3) {
		board.levelTwoBot();
	}
}