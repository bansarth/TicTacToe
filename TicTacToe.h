#include <iostream>
#include <vector>
using namespace std;

class TTT {
	private:
		vector<char> board;

	public:
		TTT() {
			board.resize(9, ' ');
		}

		void boardOutput() {
			cout << " " << board[0] << " |   |   \n-----------\n   |   |   \n-----------\n   |   |   \n";
		}
};