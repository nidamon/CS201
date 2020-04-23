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
	void game_display(); // Displays the game board

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
		game.game_display();
		turn++;
	}

	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}

// Gets user's input and checks if placement is available
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

// Displays the game board and made use of some lambda functions in this member function
void Tactoe::game_display()
{
	system("cls"); // refreshes the console screen.

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Makes it possible to color text
	auto num_no = [](const vector<int>& _board, const int& square, HANDLE& hConsole) // Prints the appropriate O, X or number
	{
		cout << " | ";
		if (_board[square - 1] != 0)
		{
			if (_board[square - 1] == 1)
			{
				SetConsoleTextAttribute(hConsole, 11); // Blue
				cout << 'O';
			}

			else
			{
				SetConsoleTextAttribute(hConsole, 12); // Red
				cout << 'X';
			}
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 8); // Grey/Gray
			cout << square;
		}
		SetConsoleTextAttribute(hConsole, 7); // Default white, I think
	};

	auto horizontal_line = []() // Prints a line of "-"
	{
		cout << "  -------------" << endl;
	};

	for (int i = 0; i < 3; i++)
	{
		horizontal_line();
		cout << " ";
		num_no(_board, 1 + (3 * i), hConsole);
		num_no(_board, 2 + (3 * i), hConsole);
		num_no(_board, 3 + (3 * i), hConsole);
		cout << " |" << endl;
	}
	horizontal_line();
	cout << endl;
}