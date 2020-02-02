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

	//Here the cells are defined as strings
	string a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2;
	string a3, b3, c3, d3, e3, f3, g3, h3, a4, b4, c4, d4, e4, f4, g4, h4;
	string a5, b5, c5, d5, e5, f5, g5, h5, a6, b6, c6, d6, e6, f6, g6, h6;
	string a7, b7, c7, d7, e7, f7, g7, h7, a8, b8, c8, d8, e8, f8, g8, h8;

	//All of the cells are set to equal "."
	a1 = b1 = c1 = d1 = e1 = f1 = g1 = h1 = a2 = b2 = c2 = d2 = e2 = f2 = g2 = h2 = ".";
	a3 = b3 = c3 = d3 = e3 = f3 = g3 = h3 = a4 = b4 = c4 = d4 = e4 = f4 = g4 = h4 = ".";
	a5 = b5 = c5 = d5 = e5 = f5 = g5 = h5 = a6 = b6 = c6 = d6 = e6 = f6 = g6 = h6 = ".";
	a7 = b7 = c7 = d7 = e7 = f7 = g7 = h7 = a8 = b8 = c8 = d8 = e8 = f8 = g8 = h8 = ".";

	while (n >= 0) { //Outputs the grid and asks for a new placement
		cout << "    1   2   3   4   5   6   7   8" << endl;
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
		switch (row) { //selects the row
		case 1:
			switch (column) { //selects the cell in the #1 row
			case 1:
				a1 = "X";
				break;
			case 2:
				b1 = "X";
				break;
			case 3:
				c1 = "X";
				break;
			case 4:
				d1 = "X";
				break;
			case 5:
				e1 = "X";
				break;
			case 6:
				f1 = "X";
				break;
			case 7:
				g1 = "X";
				break;
			case 8:
				h1 = "X";
				break;
			default:
				n = -1;
				break;
			}
			break;
		case 2:
			switch (column) { //selects the cell in the #2 row
			case 1:
				a2 = "X";
				break;
			case 2:
				b2 = "X";
				break;
			case 3:
				c2 = "X";
				break;
			case 4:
				d2 = "X";
				break;
			case 5:
				e2 = "X";
				break;
			case 6:
				f2 = "X";
				break;
			case 7:
				g2 = "X";
				break;
			case 8:
				h2 = "X";
				break;
			default:
				n = -1;
				break;
			}
			break;
		case 3:
			switch (column) { //selects the cell in the #3 row
			case 1:
				a3 = "X";
				break;
			case 2:
				b3 = "X";
				break;
			case 3:
				c3 = "X";
				break;
			case 4:
				d3 = "X";
				break;
			case 5:
				e3 = "X";
				break;
			case 6:
				f3 = "X";
				break;
			case 7:
				g3 = "X";
				break;
			case 8:
				h3 = "X";
				break;
			default:
				n = -1;
				break;
			}
			break;
		case 4:
			switch (column) { //selects the cell in the #4 row
			case 1:
				a4 = "X";
				break;
			case 2:
				b4 = "X";
				break;
			case 3:
				c4 = "X";
				break;
			case 4:
				d4 = "X";
				break;
			case 5:
				e4 = "X";
				break;
			case 6:
				f4 = "X";
				break;
			case 7:
				g4 = "X";
				break;
			case 8:
				h4 = "X";
				break;
			default:
				n = -1;
				break;
			}
			break;
		case 5:
			switch (column) { //selects the cell in the #5 row
			case 1:
				a5 = "X";
				break;
			case 2:
				b5 = "X";
				break;
			case 3:
				c5 = "X";
				break;
			case 4:
				d5 = "X";
				break;
			case 5:
				e5 = "X";
				break;
			case 6:
				f5 = "X";
				break;
			case 7:
				g5 = "X";
				break;
			case 8:
				h5 = "X";
				break;
			default:
				n = -1;
				break;
			}
			break;
		case 6:
			switch (column) { //selects the cell in the #6 row
			case 1:
				a6 = "X";
				break;
			case 2:
				b6 = "X";
				break;
			case 3:
				c6 = "X";
				break;
			case 4:
				d6 = "X";
				break;
			case 5:
				e6 = "X";
				break;
			case 6:
				f6 = "X";
				break;
			case 7:
				g6 = "X";
				break;
			case 8:
				h6 = "X";
				break;
			default:
				n = -1;
				break;
			}
			break;
		case 7:
			switch (column) { //selects the cell in the #7 row
			case 1:
				a7 = "X";
				break;
			case 2:
				b7 = "X";
				break;
			case 3:
				c7 = "X";
				break;
			case 4:
				d7 = "X";
				break;
			case 5:
				e7 = "X";
				break;
			case 6:
				f7 = "X";
				break;
			case 7:
				g7 = "X";
				break;
			case 8:
				h7 = "X";
				break;
			default:
				n= -1;
				break;
			}
			break;
		case 8:
			switch (column) { //selects the cell in the #8 row
			case 1:
				a8 = "X";
				break;
			case 2:
				b8 = "X";
				break;
			case 3:
				c8 = "X";
				break;
			case 4:
				d8 = "X";
				break;
			case 5:
				e8 = "X";
				break;
			case 6:
				f8 = "X";
				break;
			case 7:
				g8 = "X";
				break;
			case 8:
				h8 = "X";
				break;
			default:
				n= -1;
				break;
			}
			break;
		default:
			n = -1;
			break;
		}

	}
	return 0;
}