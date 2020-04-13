/*caesar-cypher.cpp
Nathan Damon
CS 201
4/12/2020
This program will encrypt user input based on the value given.
*/

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;

unsigned StringToTokenWS(const string& user_string, vector<string>& tokens);

int main()
{
	vector<string> tokens;
	string user_string;
	string cypher_shift_str;
	int cypher_shift_val;
	cout << "Caesar Cypher" << endl;
	cout << endl;
	while (true)
	{
		// Takes users line
		cout << "Enter a message to cypher (blank line to end): ";
		std::getline(cin, user_string);
		if (user_string.size() == 0) // Checks if line is blank
			break;
		else
			StringToTokenWS(user_string, tokens);

		for (size_t i = 0; i < tokens.size(); i++)
			cout << tokens[i] << endl;

		// Asks for an amount to shift the characters over
		cout << "Enter an integer to use as the shift: ";
		while (true)
		{
			std::getline(cin, cypher_shift_str);
			istringstream instream(cypher_shift_str);
			instream >> cypher_shift_val;
			if (instream) // Confirms if there is an int value in cypher_shift_str
				break;
			else
				cout << "You need to enter an integer: ";
		}
		cout << cypher_shift_val << endl;

		// Divides the tokens into chars and outputs them onto the console
		char c;
		for (size_t i = 0; i < tokens.size(); i++)
		{
			istringstream instream(tokens[i]);
			for (size_t j = 0; j < tokens[i].size(); j++)
			{
				instream >> c;
				cout << c << " ";
			}
			cout << endl;
		}

	}


	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
}



 // Takes the inputted string and divides it into tokens.
unsigned StringToTokenWS(const string& user_string, vector<string>& tokens)
{
	istringstream instream(user_string);
	string s;
	int n = 0;
	while (n < user_string.size()) // This is used to add all of the parts of 
								   // the inputed string or line into the vector tokens.
	{
		instream >> s;
		tokens.push_back(s);
		n = n + s.size() + 1; // Here the part's size and the space after it are added to n.
	}						  // When (n > size of str) then the while loop stops.
	tokens.push_back("");
	return 0;
}