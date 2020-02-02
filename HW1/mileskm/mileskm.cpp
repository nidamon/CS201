/*Nathan Damon
CS 201
2/2/2020
This program will convert miles to kilometers.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n = 0;

	cout << "Enter a number of miles for kilometer conversion: ";
	cin >> n;
	cout << "Number of kilometers: " << n * 1.609 << endl;
	system("pause"); //Had to use this again...

	return 0;
}