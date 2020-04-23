/*tictactoe.h
Nathan Damon
CS 201
4/22/2020
This header will declare the needs of tictactoe.cpp.
*/

#ifndef tictactoe_H
#define tictactoe_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <Windows.h>

class Tactoe
{
public:
	Tactoe() : _board{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, _blue_win{ false }, _red_win{ false }, _turn{ 0 }{};
	void user_input(); // Gets user's input and checks if placement is available
	void game_display(); // Displays the game board
	void win_loss_check(); // Checks for three in a row
	void run(); // Runs the game

	vector <int> _board; // Vector of all the places on the 3x3 game board

private:
	bool _blue_win;
	bool _red_win;
	int _turn;

};

#endif