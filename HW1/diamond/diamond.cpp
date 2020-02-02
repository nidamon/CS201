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
	int n = 0;
	int k = 0;

	while (n < 1) {

		cout << "Please enter a positive integer ";
		cin >> n;
		if (n <= 0) {
			cout << n << " needs to be a positive integer" << endl;
		}
	}
	cout << "You entered: " << n << endl;
	for (int i = 1; i <= n; i++ , k++) {

		for (int j = n - 1; j >= k; j = j - 1) { //This will put the spaces in

			cout << " ";
		}
		for (int l = 0; l <= k * 2; l = l++) { //This will place the "#" after the spaces

			cout << "#";
		}
		cout << endl;
	}
	for (int g = n - 1; g >= 1; g--) {

		for (int h = n; h >= g; h--) { //This will put the spaces in

			cout << " ";
		}
		for (int m = 1; m <= (2 * g - 1); m++) { //This will place the "#" after the spaces

			cout << "#";
		}
		cout << endl;
	}
	//system("pause"); //Was having issues with the console instantly closing on me. So I found this tempory solution.
	return 0;
}
