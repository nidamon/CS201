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
	int n=0;

	while (n < 1) {

		cout << "Please enter a positive integer ";
		cin >> n;
		if (n >= 1) {
			break;
		}
		else {
			cout << n << " needs to be a positive integer" << endl;
		}
	}
	cout << "You entered: " << n << endl;
	for (int i = 0; i <= n; i=i++) {
		for (int i = n; i >= 0; i=i-1) {
			cout << " ";
		}
			cout << "#";
	}
	return 0;
}