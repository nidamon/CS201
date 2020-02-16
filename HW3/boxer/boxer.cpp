/*boxer.cpp
Nathan Damon
CS 201
2/15/2020
This program will take a string and integer input and output a box.
*/

#include <iostream>
#include "boxer.h"
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void boxer(
	string str,
	int n
)
{
	cout << endl;
	for (int i = 0; i < n; i++){ //This for loop will output the top block of "*".
		for (int i = 0; i < 2 + 2 * n + str.size(); i++) 
			cout << "*";
		cout << endl;
	}

	vector <string> hold(n, "*");//This vector will hold some characters to lessen the number of for loops.
	hold.resize(2 + n + str.size(), " ");
	hold.resize(2 + 2 * n + str.size(), "*");

	for (int i = 0; i < hold.size(); i++)
		cout << hold[i];

	cout << endl;

	for (int i = 0; i < n; i++)
		cout << "*";

	cout << " " << str << " ";

	for (int i = 0; i < n; i++)
		cout << "*";

	cout << endl;

	for (int i = 0; i < hold.size(); i++)
		cout << hold[i];

	cout << endl;

	for (int i = 0; i < n; i++) { //This for loop will output the top block of "*".
		for (int i = 0; i < 2 + 2 * n + str.size(); i++)
			cout << "*";
		cout << endl;
	}
	cout << endl;
}