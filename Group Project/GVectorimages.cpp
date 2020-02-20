/*GVectorimages.cpp
Nathan Damon
CS 201
2/19/2020
This program will contain a set of vectors that hold strings for a game.
*/

#include <iostream>
#include <vector>

using std::vector;
using std::string;

vector <vector <string>> vblank;
vector <string> vblank1;

string empty = "|             |";



using std::cout;
using std::cin;
using std::endl;

void main()
{
	for (int i = 0; i < 6; i++) {
		vblank1.push_back(empty);
	}

	cout << "push done" << endl;

	for (int i = 0; i < 6; i++) {
		cout << vblank1[i] << endl;
	}

	cout << empty.size() << endl;

	int nooooo;
	cout << endl;
	cout << "To stop, type something: ";
	cin >> nooooo;
}
