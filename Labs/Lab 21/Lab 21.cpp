/*Lab 21.cpp
Nathan Damon
CS 201
3/31/2020
This file will use a function "trunc8" defined within truncstruct.cpp.
*/

#include "truncstruct.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

int main()
{
	string str;
	cout << "Enter a string: ";
	cin >> str;

	int len = -1;

	//cout << "Enter a positive number: ";
	//cin >> len;
	//while (len < 0)
	//{
	//	cout << "Please enter a positive number: ";
	//	cin >> len;
	//}

	cout << endl;

	StringInfo User_string;

	if (len > 0)
	{
		StringInfo User_input{ str, len };
		User_string = trunc(User_input);
	}
	else
	{
		User_string = trunc8(str);
	}
	
	string s = User_string.str;
	len = User_string.len;

	cout << "Your new string is: " << s 
		 << " And your string's new length is: " << len 
		 << "." << endl;

	int q;
	cin >> q;
}