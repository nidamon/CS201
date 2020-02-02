/*Nathan Damon
CS 201
2/2/2020
This program will print positive integers inputted by the user and outputs the highest positive integer given when zero or a negative number is inputted.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n = 1;
	int greatest = 0;

	cout << "Enter a sequence of positive integers, ending with zero." << endl;
	cout << "I will print the greatest positive number entered." << endl;

	while (n > 0) { //This while loop asks for the positive integer

		cout << "Enter a positive integer (0 to end): ";
		cin >> n;
		if (n > greatest) {
			greatest = n;
		}
	}
	if (greatest == 0) {

		cout << "No positive integers were entered." << endl;
	}
	else {

		cout << "The greatest number entered: " << greatest << endl;
	}
	return 0;
}