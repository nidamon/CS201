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

vector <vector <string>> barrier_section; // Need to change
vector <string> empty_cell;
vector <string> player_cell; // Will hold a specified player model.

string empty =            "|                            |";
string outside_barrier =  "|----------------------------|"; // Not using at the moment.
string inside_barrier =   "|############################|"; // Similarly not being used.


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

vector <string> barrier_model_2 = { // Rabbit box 2
 "|                            |",
 "|   H>==================<H   |",
 "|   Y \\                / Y   |",
 "|   |  \\ ____________ /  |   |",
 "|   |   |            |   |   |",
 "|   |   |            |   |   |",
 "|   |   |     2      |   |   |",
 "|   |   |(\\___/)     |   |   |",
 "|   |   |(=\'.\'=)_____|   |   |",
 "|   | _- (\")_(\")      -_ |   |",
 "|   I>==================<I   |",
 "|                            |",
};

vector <string> barrier_model_3 = { // Rabbit box 3
 "|                            |",
 "|   H>==================<H   |",
 "|   Y \\                / Y   |",
 "|   |  \\ ____________ /  |   |",
 "|   |   |            |   |   |",
 "|   |   |            |   |   |",
 "|   |   |       3    |   |   |",
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

vector <int> Vrandom(3, 0); // Used for barrier randomization.
vector <int> Vlast_generated(3, 0); // Copies down the barrier model for printing the previous set of barriers.

int main()
{
	int stop; // Is used at the end of the program to prevent the console from closing.
	int max_barrier_count = 2;
	int min_barrier_count = 1;
	int barrier_count = 0;
	int randvalue = 0;

	for (int i = 0; i < 12; i++) { // Creates the empty cell
		empty_cell.push_back(empty);
	}

	player_cell = player_model_1; 

	for (int i = 0; i < 12; i++) {  // For testing the output of the cells.
		cout << empty_cell[i] << endl;
	}

	barrier_section.push_back(empty_cell); // Needs refinement.
	barrier_section.push_back(barrier_model_1);
	barrier_section.push_back(barrier_model_2);
	barrier_section.push_back(barrier_model_3);

	// Main while loop for displaying the models

	int yes = 1;
	int repititions = 0;
	while (yes == 1){
		srand(time(0));
		randvalue = (((rand()) + repititions) % 5); // Gets a random value between 0 and 5.
		switch (randvalue) // Picks between 6 different variations of barrier setups.
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

		int random_barrier_1 = 0;
		int random_barrier_2 = 0;
		int random_barrier_3 = 0;
		int types_of_barriers = 3; // There are three rabbit boxes at the moment.
		int image_movement = 0;
		while (image_movement != 6)
		{
			system("cls"); // refreshes the console screen.

		// Generates the top layer the rapidly shrinks.
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
			

			if (Vrandom[0] == 1) // Picks a random barrier model.
				random_barrier_1 = ((((rand()) + repititions) % 5) % 4); // Will need changing when more than 3 barrier models are made.
			else
				random_barrier_1 = 0;


			if (Vrandom[1] == 1) // Picks a random barrier model.
				random_barrier_2 = ((((rand()) + repititions) % 7) % 4); // Will need changing when more than 3 barrier models are made.
			else
				random_barrier_2 = 0;


			if (Vrandom[2] == 1) // Picks a random barrier model.
				random_barrier_3 = ((((rand()) + repititions) % 9) % 4); // Will need changing when more than 3 barrier models are made.
			else
				random_barrier_3 = 0;


		// Generates the bottom layer.
			for (int i = 0; i < 12; i++) {
				cout << barrier_section[random_barrier_1][i];
				cout << barrier_section[random_barrier_2][i];
				cout << barrier_section[random_barrier_3][i] << endl;

			}

		// Generates a new layer with empty cells that increases in size.
			for (int i = 0; i < image_movement; i++) {
				cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;
			}

			image_movement = image_movement + 2; // Determines how many times the overall image makes small shifts.
		}

	// Sets Vlast_generated to the current Vrandom's values.
			Vlast_generated[0] = random_barrier_1;
			Vlast_generated[1] = random_barrier_2;
			Vlast_generated[2] = random_barrier_3;
		
		repititions++;
	// Prompts for a continuation of repetitions
		yes = 0;
		cout << endl;
		cout << "If want more samples, type 1: ";
		cin >> yes;

		system("cls"); // refreshes the console screen.
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
