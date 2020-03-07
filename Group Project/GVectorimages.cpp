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

//void Movement(/*const& Vrandom, const& Vlast_generated,*/ &Move); // CHANGE

void Old_Layer(
	const vector<vector<string>>& barrier_section,
	const vector <int>& Vlast_generated);

void New_Layer(
	const vector <vector <string>> & barrier_section,
	const vector <int>& Vrandom,
	const int& repititions,
	const int& types_of_barriers,
	int& random_barrier_1,
	int& random_barrier_2,
	int& random_barrier_3);

void Layers(
	const vector<vector<string>>& barrier_section,
	const vector <string>& empty_cell,
	const vector <string>& player_cell,
	const int& repetitions,
	const int& types_of_barriers,
	vector <int>& Vlast_generated,
	vector <int>& Vrandom);


vector <vector <string>> barrier_section; // Need to change
vector <string> empty_cell;
vector <string> player_cell; // Will hold a specified player model.

string empty =            "|                            |";
string outside_barrier =  "|----------------------------|"; // Not using at the moment.
string inside_barrier =   "|############################|"; // Similarly not being used.


vector <string> barrier_model_1 = { // Rabbit box
 "|                        1   |",
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

vector <string> barrier_model_2 = { // Empty box 2
 "|                        2   |",
 "|   H>==================<H   |",
 "|   Y \\                / Y   |",
 "|   |  \\ ____________ /  |   |",
 "|   |   |            |   |   |",
 "|   |   |            |   |   |",
 "|   |   |            |   |   |",
 "|   |   |            |   |   |",
 "|   |   |____________|   |   |",
 "|   | _-              -_ |   |",
 "|   I>==================<I   |",
 "|                            |",
};

vector <string> barrier_model_3 = { // "Person A" box 3
 "|                        3   |",
 "|   H>==================<H   |",
 "|   Y \\                / Y   |",
 "|   |  \\ ____________ /  |   |",
 "|   |   |    ,,,     |   |   |",
 "|   |   |   (o.o)    |   |   |",
 "|   |   |  /^\\#/^\\   |   |   |",
 "|   |   |  ^  #  ^   |   |   |",
 "|   |   |____/_\\_____|   |   |",
 "|   | _-              -_ |   |",
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

int Move;

int main()
{
	int stop; // Is used at the end of the program to prevent the console from closing.

	for (int i = 0; i < 12; i++) { // Creates the empty cell
		empty_cell.push_back(empty);
	}

	player_cell = player_model_1; 

	barrier_section.push_back(empty_cell); // Needs refinement.
	barrier_section.push_back(barrier_model_1);
	barrier_section.push_back(barrier_model_2);
	barrier_section.push_back(barrier_model_3);

	// Main while loop for displaying the models

	int lives = 1;
	int repetitions = 0;
	int types_of_barriers = 3; // There are three boxes at the moment.
	
	while (lives == 1){
		Layers(
			barrier_section,
			empty_cell,
			player_cell,
			repetitions,
			types_of_barriers,
			Vlast_generated,
			Vrandom);
	
		// Where movement needs to go.


		repetitions++;

	// Prompts for a continuation of repetitions
		lives = 0;
		cout << endl;
		cout << "If want more samples, type 1: ";
		cin >> lives;

		system("cls"); // Refreshes the console screen.
	}
	

	cout << endl;
	cout << "To stop, type something: ";
	cin >> stop;

	return 0;
}

/*
void Movement(const& Vrandom, const& Vlast_generated, &Move, const& player_cell, const& empty_cell)
{
	cout << "Choose column 1, 2, or 3 to move to it: ";
	cin >> Move;

	for (int i = 0; i < 5; i++)
	{

	}

}*/


void New_Layer(
	const vector<vector<string>>& barrier_section,
	const vector <int>& Vrandom,
	const int& repetitions,
	const int& types_of_barriers,
	int& random_barrier_1,
	int& random_barrier_2,
	int& random_barrier_3)
{
	if (Vrandom[0] == 1) // Picks a random barrier model.
		random_barrier_1 = (((((rand()) + repetitions) % 5) % types_of_barriers) + 1); // Will need to change the 3 when more than 3 barrier models are made.
	else
		random_barrier_1 = 0;

	if (Vrandom[1] == 1) // Picks a random barrier model.
		random_barrier_2 = (((((rand()) + repetitions) % 7) % types_of_barriers) + 1); // Will need to change the 3 when more than 3 barrier models are made.
	else
		random_barrier_2 = 0;

	if (Vrandom[2] == 1) // Picks a random barrier model.
		random_barrier_3 = (((((rand()) + repetitions) % 11) % types_of_barriers) + 1); // Will need to change the 3 when more than 3 barrier models are made.
	else
		random_barrier_3 = 0;

// Generates the bottom layer.
	for (int i = 0; i < 12; i++) {
		cout << barrier_section[random_barrier_1][i];
		cout << barrier_section[random_barrier_2][i];
		cout << barrier_section[random_barrier_3][i] << endl;
	}
}

void Old_Layer(
	const vector<vector<string>>& barrier_section,
	const vector <int>& Vlast_generated)
{
// repeats the previous bottom layer.
	for (int i = 0; i < 12; i++) {
		cout << barrier_section[Vlast_generated[0]][i] << barrier_section[Vlast_generated[1]][i] << barrier_section[Vlast_generated[2]][i] << endl;
	}
}

void Layers(
	const vector<vector<string>>& barrier_section,
	const vector <string>& empty_cell,
	const vector <string>& player_cell,
	const int& repetitions,
	const int& types_of_barriers,
	vector <int>& Vlast_generated,
	vector <int>& Vrandom)
{	
	int randvalue = 0; 
	int random_barrier_1 = 0;
	int random_barrier_2 = 0;
	int random_barrier_3 = 0;
	int image_movement = 0;

	srand(time(0));
	randvalue = (((rand()) + repetitions) % 5); // Gets a random value between 0 and 5.
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

	//vector <int> random_barrier_model(3, 0);

	while (image_movement != 6)
	{
		system("cls"); // refreshes the console screen.

	// Generates the top layer the rapidly shrinks.
		for (int i = image_movement; i < 12; i++) {
			cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;
		}

		Old_Layer(
			barrier_section,
			Vlast_generated);

	// Generates the middle layer with the player model.
		for (int i = 0; i < 12; i++) {
			cout << empty_cell[i] << player_cell[i] << empty_cell[i] << endl;
		}

		New_Layer(
			barrier_section,
			Vrandom,
			repetitions,
			types_of_barriers,
			random_barrier_1,
			random_barrier_2,
			random_barrier_3);

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
}