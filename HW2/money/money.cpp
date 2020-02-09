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
	cout << "How many pennies do you have? ";
	cin >> pennies;
	cout << "How many nickels do you have? ";
	cin >> nickels;
	cout << "How many dimes do you have? ";
	cin >> dimes;
	cout << "How many quarters do you have? ";
	cin >> quarters;
	cout << "How many half dollars do you have? ";
	cin >> half_dollars;
	cout << endl;

	if (pennies == 1){ //gives the number of pennies
		cout << "You have 1 penny." << endl;
	}
	else{
		cout << "You have " << pennies << " pennies." << endl;
	}

	if (nickels == 1){ //gives the number of nickels
		cout << "You have 1 nickel." << endl;
	}
	else{
		cout << "You have " << nickels << " nickels." << endl;
	}

	if (dimes == 1){ //gives the number of dimes
		cout << "You have 1 dime." << endl;
	}
	else{
		cout << "You have " << dimes << " dimes." << endl;
	}

	if (quarters == 1){ //gives the number of quarters
		cout << "You have 1 quarter." << endl;
	}
	else{
		cout << "You have " << quarters << " quarters." << endl;
	}

	if (half_dollars == 1){ //gives the number of half dollars
		cout << "You have 1 half dollar." << endl;
	}
	else{
		cout << "You have " << half_dollars << " half dollars." << endl;
	}
	cout << endl;
	

	int q;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}