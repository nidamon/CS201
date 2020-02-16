/*collatz.cpp
Nathan Damon
CS 201
2/16/2020
This program will take a positive number input and will output a series of numbers ending at one.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int n;

int main()
{
	cout << "Please give a positive number that you want the Collatz sequence to start at: ";
	cin >> n;
	while (n < 1) { // If n is not 1 or more, user is prompted again.
		cout << "The number cannot be less then 1. Enter a number greater than 0: ";
		cin >> n;
	}

	while (n > 1) {
		cout << n << " ";
		switch (n % 2) {
			case 0:
				n = n / 2;
				break;
			case 1:
				n = 3 * n + 1;
				break;
		}
	}
	cout << n << endl;

	int q;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}