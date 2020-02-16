/*boxer.cpp
Nathan Damon
CS 201
2/15/2020
This program will take a string and integer input and output a box.
*/

#include <iostream>
#include "boxer.h"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void boxer(
	string str, //This string will be put into the middle of the box.
	int n //This integer determine the thickness of the box.
)
{
	cout << endl; /*This is an additional blank line to seperate the 
					outputted box from the prompt text of the main file*/

	for (int i = 0; i < n; i++){ //This for loop will output the top block of "*".
		for (int i = 0; i < 2 + 2 * n + str.size(); i++) 
			cout << "*";
		cout << endl;
	}

	vector <string> hold(n, "*");//This vector will contain some characters to lessen the number of for loops.
	hold.resize(2 + n + str.size(), " "); // Adds the spaces for the blank space in the box.
	hold.resize(2 + 2 * n + str.size(), "*"); // Adds the remaning "*" to the end.

	for (int i = 0; i < hold.size(); i++) // Prints the elements in the vector "hold".
		cout << hold[i];

	cout << endl;

	for (int i = 0; i < n; i++) // Prints the "*" before the string.
		cout << "*";

	cout << " " << str << " "; // The string with spacing.

	for (int i = 0; i < n; i++) // Adds the last "*" after the string.
		cout << "*";

	cout << endl;

	for (int i = 0; i < hold.size(); i++)// Prints the elements in the vector "hold" again.
		cout << hold[i];

	cout << endl;

	for (int i = 0; i < n; i++) { //This for loop will output the top block of "*".
		for (int i = 0; i < 2 + 2 * n + str.size(); i++)
			cout << "*";
		cout << endl;
	}
	cout << endl; //This is also an additional blank line for seperation in the output on the console.
}