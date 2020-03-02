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
vector <int> Vlast_generated(3, 0);

int main()
{
	int stop;
	int max_barrier_count = 2;
	int min_barrier_count = 1;
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

	for (int i = 0; i < 6; i++) {  // For testing the output of the cells.
		cout << empty_cell[i] << endl;
	}

	barrier_section.push_back(empty_cell);
	barrier_section.push_back(barrier_cell);

	int yes = 1;
	int repititions = 0;
	while (yes == 1){
		srand(time(0));
		randvalue = (((rand()) + repititions) % 5);
		switch (randvalue)
		{
		case 0:
			Vrandom = { 1 , 0 , 0 };
			break;
		case 1:
			Vrandom = { 1 , 1 , 0 };
			break;
		case 2:
			Vrandom = { 1 , 0 , 1 };
			break;
		case 3:
			Vrandom = { 0 , 1 , 0 };
			break;
		case 4:
			Vrandom = { 0 , 1 , 1 };
			break;
		case 5:
			Vrandom = { 0 , 0 , 1 };
			break;
		}
	// repeats the previous bottom layer.
		for (int i = 0; i < 6; i++) {
			cout << barrier_section[Vlast_generated[0]][i] << barrier_section[Vlast_generated[1]][i] << barrier_section[Vlast_generated[2]][i] << endl;
		}
	// Generates the middle layer with the player model.
		for (int i = 0; i < 6; i++) {
			cout << empty_cell[i] << player_cell[i] << empty_cell[i] << endl;
		}
	// Generates the bottom layer.
		for (int i = 0; i < 6; i++) {
			cout << barrier_section[Vrandom[0]][i] << barrier_section[Vrandom[1]][i] << barrier_section[Vrandom[2]][i] << endl;
		}
	// Sets Vlast_generated to the current Vrandom's values.
		for (int i = 0; i < 3; i++)
			Vlast_generated[i] = Vrandom[i];
		
		repititions++;

		yes = 0;
		cout << endl;
		cout << "If want more samples, type 1: ";
		cin >> yes;

		system("cls");
	}
	

	cout << endl;
	cout << "To stop, type something: ";
	cin >> stop;

	return 0;
}
