/*boxer.cpp
Nathan Damon
CS 201
2/15/2020
This program will take a string and integer input and return a box.
*/

#include <iostream>
#include "boxer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

string boxer(
	string str,
	int n
)
{
	for (int i = 0; i < 3 + 2 * n; i++) 
	{
		cout << "*";
	}
	cout << str;
	for (int i = 0; i < 3 + 2 * n; i++)
	{
		cout << "*";
	}
	cout << endl;
	return str;
}