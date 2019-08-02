CXX = g++
CXXFLAGS = -std=c++1z -Wconversion -Wall -Wextra -pedantic -g

TTT: TicTacToe.o
	$(CXX) $(CXXFLAGS) -o TTT TicTacToe.o
	
TicTacToe.o: TicTacToe.h