/*money
Nathan Damon
CS 201
2/9/2020
This program will ask for a number of different kinds of cents and will then add them up.
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int pennies;
int nickels;
int dimes;
int quarters;
int half_dollars;

int main()
{
	cout << "Enter a number of pennies: ";
	cin >> pennies;
	cout << "Enter a number of nickels: ";
	cin >> nickels;
	cout << "Enter a number of dimes: ";
	cin >> dimes;
	cout << "Enter a number of quarters: ";
	cin >> quarters;
	cout << "Enter a number of half dollars: ";
	cin >> half_dollars;


	return 0;
}