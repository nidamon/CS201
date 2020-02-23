/*tokenizertest.cpp
Nathan Damon
CS 201
2/22/2020
This program will test the tokenizer program.
*/

#include "tokenizer.h"

int main()
{
	string str;
	cout << "Please type in some text. When you are done, type \"End\", \"end\" or \"END\":" << endl;
	ReadLine(str);

	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}