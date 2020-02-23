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

void AnalyzeTokens(const vector<string>& tokens)
{
	for (int i = 0; i < tokens.size(); i++)
	{
		int notint = 0;
		string::size_type pos1 = tokens[i].find_first_of("0123456789"); // pos will be really large if 0-9 is not in the string.
		string::size_type pos2 = tokens[i].substr(0, 1).find_first_of("_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"); 
									// pos will be really large if any of these characters are not in the string.
		string::size_type pos3 = tokens[i].find_first_of("\"");
		if (pos1 > 1000)
			notint++;
		else
			for (int j = 0; j < tokens[i].size(); j++) // if a number 0-9 is found somewhere, check if all chars are 0-9.
			{
			
				if (tokens[i].substr(j, 1).find_first_of("0123456789") > 1)
					notint++;
			}
		if (notint == 0)
			cout << "[integer]          \"" << tokens[i] << "\"" << endl;
		else if (tokens[i].size() == 0)
			cout << "[whitespace]       \"\"" << endl;
		else if (pos3 < 10)
				cout << "[string]           \"\\" << tokens[i] << "\\\"" << endl;
		else if (pos2 < 10)  
			cout << "[identifier]       \"" << tokens[i] << "\"" << endl;
		else
			cout << "[other]            \"" << tokens[i] << "\"" << endl;
	}
	
}