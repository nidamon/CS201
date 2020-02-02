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
	string a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2 = ".";
	//string a1 = "."; , b1 = "."; c1 = "."; , d1 = "."; , e1 = "."; , f1 = "."; , g1 = "."; , h1 = "."; , a2 = "."; , b2 = "."; , c2 = "."; , d2 = "."; , e2 = "."; , f2 = "."; , g2 = "."; , h2 = ".";
	//string column_row = a1;
	a1 = b1 = c1 = d1 = e1 = f1 = g1 = h1 = a2 = b2 = c2 = d2 = e2 = f2 = g2 = h2;

	while (n >= 0) {
		cout << "  1   2   3   4   5   6   7   8" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "1 | " << a1 << " | " << b1 << " | " << c1 << " | " << d1 << " | " << e1 << " | " << f1 << " | " << g1 << " | " << h1 << " |" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "2 | " << a2 << " | " << b2 << " | " << c2 << " | " << d2 << " | " << e2 << " | " << f2 << " | " << g2 << " | " << h2 << " |" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "3 | " << a3 << " | " << b3 << " | " << c3 << " | " << d3 << " | " << e3 << " | " << f3 << " | " << g3 << " | " << h3 << " |" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "4 | " << a4 << " | " << b4 << " | " << c4 << " | " << d4 << " | " << e4 << " | " << f4 << " | " << g4 << " | " << h4 << " |" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "5 | " << a5 << " | " << b5 << " | " << c5 << " | " << d5 << " | " << e5 << " | " << f5 << " | " << g5 << " | " << h5 << " |" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "6 | " << a6 << " | " << b6 << " | " << c6 << " | " << d6 << " | " << e6 << " | " << f6 << " | " << g6 << " | " << h6 << " |" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "7 | " << a7 << " | " << b7 << " | " << c7 << " | " << d7 << " | " << e7 << " | " << f7 << " | " << g7 << " | " << h7 << " |" << endl;
		cout << "  ---------------------------------" << endl;
		cout << "8 | " << a8 << " | " << b8 << " | " << c8 << " | " << d8 << " | " << e8 << " | " << f8 << " | " << g8 << " | " << h8 << " |" << endl;
		cout << "  ---------------------------------" << endl;

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