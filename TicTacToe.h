#include <iostream>
#include <vector>
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

		void twoPlayerMode() {
			int square;
			char result;
			while (true) {
				boardOutput();
				cout << "Player One: Make your turn by selecting the square you wish to play on\n";
				cin >> square;
				cout << '\n';
				turn(square - 1, 1);

				result = checkForWin();
				if (result == 'X') {
					boardOutput();
					cout << "Player One Wins!\n";
					break;
				}

				boardOutput();
				cout << "Player Two: Make your turn by selecting the square you wish to play on\n";
				cin >> square;
				cout << '\n';
				turn(square - 1, 2);

				result = checkForWin();
				if (result == 'O') {
					cout << "Player Two Wins!\n";
					break;
				}
			}
		}



};