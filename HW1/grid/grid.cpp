/*Nathan Damon
CS 201
2/2/2020
This program will depict a square grid with column and row labels and allow the user to put an x in a specified cell.
Really wasn't sure how this was supposed to be done.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main() {
	int n = 0;
	int row = 0;
	int column = 0;
	string a1, b1, c1, d1, e1, f1, g1, h1, a2 = ".";
	//string column_row = a1;

	while (n >= 0) {
		cout << "  1   2   3   4   5   6   7   8" << endl;
		cout << "---------------------------------" << endl;
		cout << "1 | " << a1 << " | " << b1 << " | " << c1 << " | " << d1 << " | " << e1 << " | " << f1 << " | " << g1 << " | " << h1 << " |" << endl;
		cout << "| . | . | . | . | . | . | . | . |" << endl;

		cout << "Enter a row number: ";
		cin >> row;
		if (row < 1) {
			break;
		}
		cout << "Enter a column number: ";
		cin >> column;
		if (column < 1) {
			break;
		}
		switch (row) {
		case 1:
			switch (column) {
			case 1:
				a1 = "X";
				break;
			case 2:
				b1 = "X";
				break;
			default:
				n = -1;
				break;
			}
			break;
		case 2:
			a2 = "X";
			break;
		default:
			n = -1;
			break;
		}

	}
	return 0;
}