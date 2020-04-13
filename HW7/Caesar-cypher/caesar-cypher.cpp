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
	int cypher_shift;
	cout << "Caesar Cypher" << endl;
	cout << endl;
	while (true)
	{

		cout << "Enter a message to cypher (blank line to end): ";
		std::getline(cin, user_string);
		if (user_string.size() == 0)
			break;
		else
			StringToTokenWS(user_string, tokens);
		for (size_t i = 0; i < tokens.size(); i++)
			cout << tokens[i] << endl;

		//while 
		cout << "Enter an integer to use as the shift: ";
		cin >> cypher_shift;
	}

}

unsigned StringToTokenWS(const string& user_string, vector<string>& tokens) // Takes the inputted string and divides it into tokens.
{
	istringstream instream(user_string);
	string s;
	int n = 0;
	while (n < user_string.size()) // This is used to add all of the parts of the inputed string or line into the vector tokens.
	{
		instream >> s;
		tokens.push_back(s);
		n = n + s.size() + 1; // Here the part's size and the space after it are added to n.
	}						  // When (n > size of str) then the while loop stops.
	tokens.push_back("");
	return 0;
}