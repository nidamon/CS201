/*Nathan Damon
CS 201
1/29/2020
This program will take a positive integer input and output a diamond with a size based on the integer given.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n;

	while (true) {

		cout << "Please enter a positive integer ";
		cin >> n;
		if (n >= 0) {
			break;
		}
		else {
			cout << n << " needs to be a positive integer" << endl;
		}
	}
	cout << "You entered: " << n << endl;
	for (int i = 1; i <= n; i++) {

	}
	return 0;
}