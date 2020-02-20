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

vector <vector <string>> barrier_section;
vector <string> empty_cell;
vector <string> barrier_cell;
vector <string> player_cell;

string empty =            "|             |";
string outside_barrier =  "|-------------|";
string inside_barrier =   "|#############|";

using std::cout;
using std::cin;
using std::endl;

void main()
{
	int stop;

	for (int i = 0; i < 6; i++) {
		empty_cell.push_back(empty);
	}

	barrier_cell.push_back(outside_barrier);
	barrier_cell.push_back(inside_barrier);
	barrier_cell.push_back(outside_barrier);
	barrier_cell.resize(barrier_cell.size() + 3, empty);

	for (int i = 0; i < 6; i++) {
		cout << empty_cell[i] << endl;
	}

	cout << empty.size() << endl;

	barrier_section.push_back(empty_cell);
	barrier_section.push_back(barrier_cell);
	barrier_section.push_back(empty_cell);

	cout << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 6; i++) {
			cout << barrier_section[0][i] << barrier_section[1][i] << barrier_section[2][i] << endl;
		}
	}
	cout << endl;

	
	cout << endl;
	cout << "To stop, type something: ";
	cin >> stop;
}
