/*tokenizer.cpp
Nathan Damon
CS 201
2/22/2020
This program will take input from the user and will output an analysis on the characters.
*/

#include "tokenizer.h"

bool ReadLine(std::string& str) // Gets a line of text from the user and determines if the is anything in the line.
{
	string line;
	std::getline(cin, line);
	if (line.size() == 0)
		return false;
	else
		return true;
}
