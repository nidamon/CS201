/*tokenizer.cpp
Nathan Damon
CS 201
2/22/2020
This program will take input from the user and will output an analysis on the characters.
*/

#include "tokenizer.h"

bool ReadLine(string& str) // Gets a line of text from the user and determines if the is anything in the line.
{
	std::getline(cin, str);
	if (str.size() == 0)
		return false;
	else
		return true;
}

unsigned StringToTokenWS(const string& str, vector<string>& tokens) // Takes the inputted string and divides it into tokens.
{
	istringstream instream(str);
	string s;
	int n = 0;
	while (n < str.size()) // This is used to add all of the parts of the inputed string or line into the vector tokens.
	{
		instream >> s;
		tokens.push_back(s);
		n = n + s.size() + 1; // Here the part's size and the space after it are added to n.
	}						  // When (n > size of str) then the while loop stops.
	tokens.push_back("");
	return 0;
}