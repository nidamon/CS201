/*collatz.cpp
Nathan Damon
CS 201
2/16/2020
This program will take a string and integer input and output a box.
*/


int n;

int main()
{
	cout << "Please give a positive number that you want the Collatz sequence to start at: ";
	cin >> n;
	while (n < 1) { // If n is not 1 or more, user is prompted again.
		cout << "The number cannot be less then 1. Enter a number greater than 0: ";
		cin >> n;
	}

	return 0;
}