#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class TTT {
	private:
		vector<char> board;

	public:
		TTT() {
			board.resize(9);
			char digits[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
			for (int i = 0; i < 9; ++i) {
				board[i] = digits[i];
			}
		}

		void boardOutput() {
			cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "  \n-----------\n " << board[3] << " | " << board[4] << " | " << board[5] << " \n-----------\n " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
		}

		void turn(int space, int player) {
			if (player == 1) {
				board[space] = 'X';
			}
			else {
				board[space] = 'O';
			}
		}

		char checkForWin() {
			if (board[0] == board[1] && board[1] == board[2]) {
				return board[0];
			}
			else if (board[3] == board[4] && board[4] == board[5]) {
				return board[3];
			}
			else if (board[6] == board[7] && board[7] == board[8]) {
				return board[6];
			}
			else if (board[0] == board[3] && board[3] == board[6]) {
				return board[0];
			}
			else if (board[1] == board[4] && board[4] == board[7]) {
				return board[1];
			}
			else if (board[2] == board[5] && board[5] == board[8]) {
				return board[2];
			}
			else if (board[0] == board[4] && board[4] == board[8]) {
				return board[4];
			}
			else if (board[2] == board[4] && board[4] == board[6]) {
				return board[4];
			}
			else {
				return 'N';
			}
		}

		char checkForWinBot2(vector<char> &cboard) {
			if (cboard[0] == cboard[1] && cboard[1] == cboard[2]) {
				return cboard[0];
			}
			else if (cboard[3] == cboard[4] && cboard[4] == cboard[5]) {
				return cboard[3];
			}
			else if (cboard[6] == cboard[7] && cboard[7] == cboard[8]) {
				return cboard[6];
			}
			else if (cboard[0] == cboard[3] && cboard[3] == cboard[6]) {
				return cboard[0];
			}
			else if (cboard[1] == cboard[4] && cboard[4] == cboard[7]) {
				return cboard[1];
			}
			else if (cboard[2] == cboard[5] && cboard[5] == cboard[8]) {
				return cboard[2];
			}
			else if (cboard[0] == cboard[4] && cboard[4] == cboard[8]) {
				return cboard[4];
			}
			else if (cboard[2] == cboard[4] && cboard[4] == cboard[6]) {
				return cboard[4];
			}
			else {
				return 'N';
			}
		}

		void twoPlayerMode() {
			vector<int> remainingMoves;
			remainingMoves.resize(9);
			for(int i = 0; i < 9; ++i){
				remainingMoves[i] = i;
			}
			int square;
			while (true) {
				boardOutput();
				cout << "Player One: Make your turn by selecting the square you wish to play on\n";
				cin >> square;
				while(square < 1 || square > 9 || remainingMoves[square - 1] == -1){
					cout << "This is not a valid move. Please reselect another square Player One.\n";
					boardOutput();
					cin >> square;
				}
				remainingMoves[square - 1] = -1;
				cout << '\n';
				turn(square - 1, 1);
				
				
				if (checkForWin() == 'X') {
					boardOutput();
					cout << "Player One Wins!\n";
					break;
				}
				else if(adjacent_find(remainingMoves.begin(), remainingMoves.end(), not_equal_to<>()) == remainingMoves.end()){
					boardOutput();
					cout << "This match is a draw.\n";
					break;
				}

				boardOutput();
				cout << "Player Two: Make your turn by selecting the square you wish to play on\n";
				cin >> square;
				while(square < 1 || square > 9 || remainingMoves[square - 1] == - 1){
					cout << "This is not a valid move. Please reselect another square Player Two.\n";
					boardOutput();
					cin >> square;
				}
				remainingMoves[square - 1] = -1;
				cout << '\n';
				turn(square - 1, 2);

				if (checkForWin() == 'O') {
					boardOutput();
					cout << "Player Two Wins!\n";
					break;
				}
				else if(adjacent_find(remainingMoves.begin(), remainingMoves.end(), not_equal_to<>()) == remainingMoves.end()){
					boardOutput();
					cout << "This match is a draw.\n";
					break;
				}
			}
		}

		void levelOneBot() {
			vector<int> remainingMoves;
			remainingMoves.resize(9);
			for (int i = 0; i < 9; ++i) {
				remainingMoves[i] = i;
			}
			int square;
			srand(time(0));
			while (true) {
				boardOutput();
				cout << "Player One: Make your turn by selecting the square you wish to play on\n";
				cin >> square;
				while (square < 1 || square > 9 || remainingMoves[square - 1] == -1) {
					cout << "This is not a valid move. Please reselect another square Player One.\n";
					boardOutput();
					cin >> square;
				}
				remainingMoves[square - 1] = -1;
				cout << '\n';
				turn(square - 1, 1);


				if (checkForWin() == 'X') {
					boardOutput();
					cout << "Player One Wins!\n";
					break;
				}
				else if (adjacent_find(remainingMoves.begin(), remainingMoves.end(), not_equal_to<>()) == remainingMoves.end()) {
					boardOutput();
					cout << "This match is a draw.\n";
					break;
				}

				boardOutput();
				cout << "The bot will make its move now.\n";
				square = (rand() % 9) + 1;
				while (remainingMoves[square - 1] == -1) {
					square = (rand() % 9) + 1;
				}
				remainingMoves[square - 1] = -1;
				cout << '\n';
				turn(square - 1, 2);

				if (checkForWin() == 'O') {
					boardOutput();
					cout << "The Bot Wins!\n";
					break;
				}
				else if (adjacent_find(remainingMoves.begin(), remainingMoves.end(), not_equal_to<>()) == remainingMoves.end()) {
					boardOutput();
					cout << "This match is a draw.\n";
					break;
				}
			}
		}

		int minMax(vector<char> currentBoard, vector<int> remMoves, int depth, bool isPlayerOne) {
			char digits[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			if (checkForWinBot2(currentBoard) == 'X') return -10;
			else if (checkForWinBot2(currentBoard) == 'O') return 10;
			else if (adjacent_find(remMoves.begin(), remMoves.end(), not_equal_to<>()) == remMoves.end()) {
				return 0;
			}

			if (!isPlayerOne) {
				int bestVal = -100;
				for (int i = 0; i < 9; ++i) {
					if (remMoves[i] != -1) {
						currentBoard[i] = 'O';
						remMoves[i] = -1;
						int value = minMax(currentBoard, remMoves, depth + 1, true);
						currentBoard[i] = digits[i];
						remMoves[i] = i;
						bestVal = max(bestVal, value - depth);
					}
				}
				return bestVal;
			}
			else {
				int bestVal = 100;
				for (int i = 0; i < 9; ++i) {
					if (remMoves[i] != -1) {
						currentBoard[i] = 'X';
						remMoves[i] = -1;
						int value = minMax(currentBoard, remMoves, depth + 1, false);
						currentBoard[i] = digits[i];
						remMoves[i] = i;
						bestVal = min(bestVal, value + depth);
					}
				}
				return bestVal;
			}

		}

		int getBestMove(vector<int> rMoves) {
			int best_val = -100;
			int bestMove;
			char digits[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

			vector<char> currentBoard = board;
			for (int i = 0; i < 9; ++i) {
				if (rMoves[i] != -1) {
					rMoves[i] = -1;
					currentBoard[i] = 'O';
					int value = minMax(currentBoard, rMoves, 0, true);
					rMoves[i] = i;
					currentBoard[i] = digits[i];

					if (value > best_val) {
						bestMove = i;
						best_val = value;
					}
				}
			}
			return bestMove;
		}

		void levelTwoBot() {
			vector<int> remainingMoves;
			remainingMoves.resize(9);
			for (int i = 0; i < 9; ++i) {
				remainingMoves[i] = i;
			}
			int square;
			while (true) {
				boardOutput();
				cout << "Player One: Make your turn by selecting the square you wish to play on\n";
				cin >> square;
				while (square < 1 || square > 9 || remainingMoves[square - 1] == -1) {
					cout << "This is not a valid move. Please reselect another square Player One.\n";
					boardOutput();
					cin >> square;
				}
				remainingMoves[square - 1] = -1;
				cout << '\n';
				turn(square - 1, 1);


				if (checkForWin() == 'X') {
					boardOutput();
					cout << "Player One Wins!\n";
					break;
				}
				else if (adjacent_find(remainingMoves.begin(), remainingMoves.end(), not_equal_to<>()) == remainingMoves.end()) {
					boardOutput();
					cout << "This match is a draw.\n";
					break;
				}

				boardOutput();
				cout << "The bot will make its move now.\n";
				square = getBestMove(remainingMoves);
				remainingMoves[square] = -1;
				cout << '\n';
				turn(square, 2);
			}
		}

};
