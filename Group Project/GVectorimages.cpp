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

string player_model_1_0 = "|   !     !   |";
string player_model_1_1 = "| ! ! .-. ! ! |";  // Temporary gingerbread man
string player_model_1_2 = "| ! _( \" )_ ! |";
string player_model_1_3 = "|  (_  :  _)  |";
string player_model_1_4 = "|    / ' \\    |";
string player_model_1_5 = "|   (_/^\\_)   |";
string player_model_1_6 = "|             |";

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

    player_cell.push_back(player_model_1_0);
	player_cell.push_back(player_model_1_1);
	player_cell.push_back(player_model_1_2);
	player_cell.push_back(player_model_1_3);
	player_cell.push_back(player_model_1_4);
	player_cell.push_back(player_model_1_5);
	

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

	int yes = 1;

	while (yes == 1){
		srand(time(0));
		Vrandom[0] = ((rand() % 3) % 2);
		Vrandom[1] = ((rand() % 5) % 2);
		Vrandom[2] = ((rand() % 7) % 2);

		for (int i = 0; i < 6; i++) {
			cout << barrier_section[Vrandom[0]][i] << barrier_section[Vrandom[1]][i] << barrier_section[Vrandom[2]][i] << endl;
		}

		for (int i = 0; i < 6; i++) {
			cout << empty_cell[i] << player_cell[i] << empty_cell[i] << endl;
		}

		srand(time(0));
		Vrandom[0] = ((rand() % 13) % 2);
		Vrandom[1] = ((rand() % 11) % 2);
		Vrandom[2] = ((rand() % 9) % 2);

		for (int i = 0; i < 6; i++) {
			cout << barrier_section[Vrandom[0]][i] << barrier_section[Vrandom[1]][i] << barrier_section[Vrandom[2]][i] << endl;
		}

		yes = 0;
		cout << endl;
		cout << "If want more samples, type 1: ";
		cin >> yes;
	}
	
	cout << endl;
	cout << "To stop, type something: ";
	cin >> stop;

	return 0;
}
