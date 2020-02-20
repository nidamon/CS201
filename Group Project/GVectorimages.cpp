/*GVectorimages.cpp
Nathan Damon
CS 201
2/19/2020
This program will contain a set of vectors that hold strings for a game.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

vector <int> Vrandom(3, 3);

int main()
{
	int stop;
	int max_barrier_count = 2;
	int barrier_count = 0;
	int randvalue = 0;

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

	cout << endl;
	cout << endl;

	srand(time(0));
	Vrandom[0] = (rand() % 2);
	Vrandom[1] = (rand() % 2);
	Vrandom[2] = (rand() % 2);

	/*for (int i = 0; i < 1; i++) {                   // All commented below is a work in progress
		//while (barrier_count > max_barrier_count) {
		//	barrier_count = 0;
			for (int j = 0; j < 3; j++) {
				srand(time(0));
				randvalue = rand() % 2;
				Vrandom[j] = (randvalue);
		//		if (randvalue == 1)
		//			barrier_count++;
		//	}
		}
		cout << endl;

		for (int j = 0; j < 3; j++) {
			cout << Vrandom[j] << endl;
			//Vrandom.pop_back();
		}
		cout << endl;
	}*/

	cout << endl;
	cout << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 6; i++) {
			cout << barrier_section[Vrandom[0]][i] << barrier_section[Vrandom[1]][i] << barrier_section[Vrandom[2]][i] << endl;
		}
	}
	cout << endl;

	
	cout << endl;
	cout << "To stop, type something: ";
	cin >> stop;

	return 0;
}
