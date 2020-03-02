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

#include <Windows.h>

using std::vector;
using std::string;

vector <vector <string>> barrier_section;
vector <string> empty_cell;
vector <string> barrier_cell;
vector <string> player_cell;

string empty =            "|                            |";
string outside_barrier =  "|----------------------------|";
string inside_barrier =   "|############################|";


vector <string> barrier_model_1 = { // Rabbit box
 "|                            |",
 "|   H>==================<H   |",
 "|   Y \\                / Y   |",
 "|   |  \\ ____________ /  |   |",
 "|   |   |            |   |   |",
 "|   |   |            |   |   |",
 "|   |   |            |   |   |",
 "|   |   |(\\___/)     |   |   |",
 "|   |   |(=\'.\'=)_____|   |   |",
 "|   | _- (\")_(\")      -_ |   |",
 "|   I>==================<I   |",
 "|                            |",
};

// Player Models below.

vector <string> player_model_1 = { // Temporary gingerbread man
 "|                            |",
 "|                            |",  
 "|                            |",
 "|       AAAAHHHHH!!!!!       |",
 "|                            |",
 "|           !     !          |",
 "|         ! ! .-. ! !        |",
 "|         ! _( \" )_ !        |",
 "|          (_  :  _)         |",
 "|            / ' \\           |",
 "|           (_/^\\_)          |",
 "|                            |",
};

vector <string> player_model_2 = { // The Bat
 "|                            |",
 "|                            |",  
 "|                            |",
 "|                            |",
 "|     (,_    ,_,    _,)      |",
 "|     /|\\`-._( )_.-'/|\\      |",
 "|    / | \\`'-/ \\-'`/ | \\     |",
 "|   /  |_.'-.\\ /.-'._|  \\    |",
 "|  /_.-'      \"      `-._\\   |",
 "|                            |",
 "|                            |",
 "|                            |",
};

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

	for (int i = 0; i < 12; i++) {
		empty_cell.push_back(empty);
	}

	player_cell = player_model_2;

	barrier_cell = barrier_model_1;


	for (int i = 0; i < 12; i++) {  // For testing the output of the cells.
		cout << empty_cell[i] << endl;
	}

	barrier_section.push_back(empty_cell); // Needs refinement.
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

		int image_movement = 0;
		while (image_movement != 6)
		{
			system("cls");

			// Generates the middle layer with the player model.
			for (int i = image_movement; i < 12; i++) {
				cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;
			}
			// repeats the previous bottom layer.
			for (int i = 0; i < 12; i++) {
				cout << barrier_section[Vlast_generated[0]][i] << barrier_section[Vlast_generated[1]][i] << barrier_section[Vlast_generated[2]][i] << endl;
			}
			// Generates the middle layer with the player model.
			for (int i = 0; i < 12; i++) {
				cout << empty_cell[i] << player_cell[i] << empty_cell[i] << endl;
			}
			// Generates the bottom layer.
			for (int i = 0; i < 12; i++) {
				cout << barrier_section[Vrandom[0]][i] << barrier_section[Vrandom[1]][i] << barrier_section[Vrandom[2]][i] << endl;
			}

			// Generates the middle layer with the player model.
			for (int i = 0; i < image_movement; i++) {
				cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;
			}

			image_movement = image_movement + 2;
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
	


	// Small test movement test below

	vector<string> S_a = { "_" , "|" , "_" , "_" , "|" , "_" , "|" , "_" };
	vector<string> S_b = { "_" , "_" , "_" , "_" , "|" , "_" , "_" , "_" };
	vector<string> S_c = { "_" , "_" , "|" , "_" , "_" , "|" , "_" , "|" };

	yes = 1;
	repititions = 0;
	while (yes == 1) {

		// repeats the previous bottom layer.
		for (int i = (repititions); i < (repititions + 4); i++) {
			cout << S_a[i % 7] << " ";
		}
		cout << endl;
		for (int i = (repititions); i < (repititions + 4); i++) {
			cout << S_b[i % 7] << " ";
		}
		cout << endl;
		for (int i = (repititions); i < (repititions + 4); i++) {
			cout << S_c[i % 7] << " ";
		}

		cout << endl;

		Sleep(0700);

		repititions++;

		/*yes = 0;
		cout << endl;
		cout << "If want more samples, type 1: ";
		cin >> yes;*/

		system("cls");
	}




	cout << endl;
	cout << "To stop, type something: ";
	cin >> stop;

	return 0;
}
