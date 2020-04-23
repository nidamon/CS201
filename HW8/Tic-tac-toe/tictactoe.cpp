/*tictactoe.cpp
Nathan Damon
CS 201
4/22/2020
This program will allow the user to play tic-tac-toe on hard difficulty.
It's predecessor was Grid.cpp from HW1.
*/

#include "tictactoe.h"

class Tactoe
{
public:
	Tactoe() : _board{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, _win{ false }, _loss{ false }{};
	void user_input(); // Gets user's input and checks if placement is available


	vector <int> _board; // Vector of all the places on the 3x3 game board
	
private:
	bool _win;
	bool _loss;

};

int main()
{

	Tactoe game;
	int turn = 0;
	while (turn < 9)
	{
		cout << "Pick a place (1-9): ";
		game.user_input();
		turn++;
	}

	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}


void Tactoe::user_input()
{
	string select_str;
	int select;
	while (true) // Gets the users selection
	{
		std::getline(cin, select_str);
		istringstream instream(select_str);
		instream >> select;
		if (instream)
			if (select > 0)
				if (select < 10)
					if (_board[select - 1] == 0)
					{
						_board[select - 1] = 1;
						break;
					}

		cout << "You need to enter an integer between 1-9 that has not been chosen yet: ";
	}
}