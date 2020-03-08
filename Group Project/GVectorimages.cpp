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

// Asks the user where the want to move to and then displays a short movement animation
void Movement(
	const vector<vector<string>>& barrier_models, 
	const vector <string>& player_cell,
	const vector <string>& empty_cell,
	vector <int>& Vlast_generated_barrier_set,
	vector <int>& random_barrier_model,
	vector <int>& Player_posistion);

// Old_Layer outputs the previous new layer.
void Old_Layer(
	const vector<vector<string>>& barrier_models,
	const vector <int>& Vlast_generated_barrier_set);

// New_Layer outputs a new randomized layer.
void New_Layer(
	const vector <vector <string>> & barrier_models,
	const vector <int>& Vrandom_barrier_set,
	const int& repititions,
	const int& types_of_barriers,
	vector <int>& random_barrier_model);

// Layers contains the functions and code to output all the visuals.
void Layers(
	const vector<vector<string>>& barrier_models,
	const vector <string>& empty_cell,
	const vector <string>& player_cell,
	const vector <int>& Player_posistion,
	const int& repetitions,
	const int& types_of_barriers,
	vector <int>& Vlast_generated_barrier_set,
	vector <int>& Vrandom_barrier_set,
	vector <int>& random_barrier_model);


vector <vector <string>> barrier_models; // Need to change
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

vector <int> Vrandom_barrier_set(3, 0); // Used to hold one of six different sets of barriers
vector <int> Vlast_generated_barrier_set(3, 0); // Copies down the barrier model for printing the previous set of barriers.
vector <int> random_barrier_model(3, 0); // Used for barrier randomization.
vector <int> Player_posistion = { 0, 1, 0 };

int stop; // Is used at the end of the program to prevent the console from closing.
int main()
{
	for (int i = 0; i < 12; i++) { // Creates the empty cell
		empty_cell.push_back(empty);
	}

	player_cell = player_model_1; 

	barrier_models.push_back(empty_cell); // Needs refinement.
	barrier_models.push_back(barrier_model_1);
	barrier_models.push_back(barrier_model_2);
	barrier_models.push_back(barrier_model_3);


	// Main while loop for displaying the models

	int lives = 1;
	int repetitions = 0;
	int types_of_barriers = 3; // There are three boxes at the moment.
	
	while (lives == 1){
		Layers(
			barrier_models,
			empty_cell,
			player_cell,
			Player_posistion,
			repetitions,
			types_of_barriers,
			Vlast_generated_barrier_set,
			Vrandom_barrier_set,
			random_barrier_model);
	
		
		Movement(
			barrier_models,
			player_cell,
			empty_cell,
			Vlast_generated_barrier_set,
			random_barrier_model,
			Player_posistion);


		repetitions++;

	//// Prompts for a continuation of repetitions
	//	lives = 0;
	//	cout << endl;
	//	cout << "If want more samples, type 1: ";
	//	cin >> lives;

		system("cls"); // Refreshes the console screen.
	}
	

	cout << endl;
	cout << "To stop, type something: ";
	cin >> stop;

	return 0;
}






// Asks the user where the want to move to and then displays a short movement animation
void Movement(
	const vector<vector<string>>& barrier_models,
	const vector <string>& player_cell,
	const vector <string>& empty_cell,
	vector <int>& Vlast_generated_barrier_set,
	vector <int>& random_barrier_model,
	vector <int>& Player_posistion)
{
	// The vector Player_cell_and_empty_cell makes picking between the cells easier within this function.
	vector<vector<string>> Player_cell_and_empty_cell = { empty_cell , player_cell };

	int Move_from;
	int Move_to;
	int Position_hold; // Temporarily holds a value from Player_posistion during movement

	for (int i = 0; i < Player_posistion.size(); i++)
	{
		if (Player_posistion[i] != 0)
		{
			Move_from = i;
			break;
		}
	}

	cout << "Choose column 1, 2, or 3 to move to it: ";
	cin >> Move_to;

	int distance_of_move = (Move_to - 1) - Move_from;

	if (distance_of_move == 0) // If not moving
		return;
	else if (distance_of_move > 0) // If moving right
	{
		for (int q = 0; q < distance_of_move; q++)
		{

			for (int j = 0; j < empty_cell[0].size(); j = j + 6)
			{
				system("cls"); // refreshes the console screen.

				for (int i = 0; i < 8; i++)
					cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;

				Old_Layer(barrier_models, Vlast_generated_barrier_set);

				for (int i = 0; i < 12; i++) {
					cout << empty_cell[i].substr(0, j + 1);
					cout << Player_cell_and_empty_cell[Player_posistion[0]][i];
					cout << Player_cell_and_empty_cell[Player_posistion[1]][i];
					cout << Player_cell_and_empty_cell[Player_posistion[2]][i].substr(0, Player_cell_and_empty_cell[Player_posistion[0]][i].size() - j - 1);
					cout << endl;
				}

				// Generates the bottom layer.
				for (int k = 0; k < 12; k++) {
					cout << barrier_models[random_barrier_model[0]][k];
					cout << barrier_models[random_barrier_model[1]][k];
					cout << barrier_models[random_barrier_model[2]][k] << endl;
				}

				for (int i = 0; i < 4; i++)
					cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;

				Sleep(0100);
			}
			Position_hold = Player_posistion[2];
			Player_posistion[2] = Player_posistion[1];
			Player_posistion[1] = Player_posistion[0];
			Player_posistion[0] = Position_hold;
		}
	}
	else if (distance_of_move < 0) // If moving left
	{
		for (int q = 0; q > distance_of_move; q--)
		{

			for (int j = 0; j < empty_cell[0].size(); j = j + 6)
			{
				system("cls"); // refreshes the console screen.

				for (int i = 0; i < 8; i++)
					cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;

				Old_Layer(barrier_models, Vlast_generated_barrier_set);

				for (int i = 0; i < 12; i++) {

					cout << Player_cell_and_empty_cell[Player_posistion[0]][i].substr(j, Player_cell_and_empty_cell[Player_posistion[0]][i].size());
					cout << Player_cell_and_empty_cell[Player_posistion[1]][i];
					cout << Player_cell_and_empty_cell[Player_posistion[2]][i];
					cout << empty_cell[i].substr(0, j + 1);
					cout << endl;
				}

				// Generates the bottom layer.
				for (int k = 0; k < 12; k++) {
					cout << barrier_models[random_barrier_model[0]][k];
					cout << barrier_models[random_barrier_model[1]][k];
					cout << barrier_models[random_barrier_model[2]][k] << endl;
				}

				for (int i = 0; i < 4; i++)
					cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;

				Sleep(0100);
			}
			Position_hold = Player_posistion[0];
			Player_posistion[0] = Player_posistion[1];
			Player_posistion[1] = Player_posistion[2];
			Player_posistion[2] = Position_hold;
		}
	}
// Sets Vlast_generated to the current Vrandom's values.
	for (int i = 0; i < 3; i++)
		Vlast_generated_barrier_set[i] = random_barrier_model[i];
}





// New_Layer outputs a new randomized layer.
void New_Layer(
	const vector<vector<string>>& barrier_models,
	const vector <int>& Vrandom_barrier_set,
	const int& repetitions,
	const int& types_of_barriers,
	vector <int>& random_barrier_model)
{
	for (int i = 0; i < 3; i++)
	{
		if (Vrandom_barrier_set[i] == 1) // Picks a random barrier model.
			random_barrier_model[i] = (((((rand()) + repetitions) % (11 + 2 * i)) % types_of_barriers) + 1); // Will need to change the 3 when more than 3 barrier models are made.
		else
			random_barrier_model[i] = 0;
	}
	
// Generates the bottom layer.
	for (int i = 0; i < 12; i++) {
		cout << barrier_models[random_barrier_model[0]][i];
		cout << barrier_models[random_barrier_model[1]][i];
		cout << barrier_models[random_barrier_model[2]][i] << endl;
	}
}






// Old_Layer outputs the previous new layer.
void Old_Layer(
	const vector<vector<string>>& barrier_models,
	const vector <int>& Vlast_generated_barrier_set)
{
// repeats the previous bottom layer.
	for (int i = 0; i < 12; i++) {
		cout << barrier_models[Vlast_generated_barrier_set[0]][i];
		cout << barrier_models[Vlast_generated_barrier_set[1]][i];
		cout << barrier_models[Vlast_generated_barrier_set[2]][i] << endl;
	}
}






// Layers contains the functions and code to output all the visuals
void Layers(
	const vector<vector<string>>& barrier_models,
	const vector <string>& empty_cell,
	const vector <string>& player_cell,
	const vector <int>& Player_posistion,
	const int& repetitions,
	const int& types_of_barriers,
	vector <int>& Vlast_generated_barrier_set,
	vector <int>& Vrandom_barrier_set,
	vector <int>& random_barrier_model)
{	
	int randvalue = 0; 
	int image_movement = 0;

	srand(time(0));
	randvalue = (((rand()) + repetitions) % 6); // Gets a random value between 0 and 5.
	switch (randvalue) // Picks between 6 different variations of barrier setups.
	{
	case 0:
		Vrandom_barrier_set = { 1 , 0 , 0 };
		break;
	case 1:
		Vrandom_barrier_set = { 1 , 1 , 0 };
		break;
	case 2:
		Vrandom_barrier_set = { 1 , 0 , 1 };
		break;
	case 3:
		Vrandom_barrier_set = { 0 , 1 , 0 };
		break;
	case 4:
		Vrandom_barrier_set = { 0 , 1 , 1 };
		break;
	case 5:
		Vrandom_barrier_set = { 0 , 0 , 1 };
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

		Old_Layer(barrier_models, Vlast_generated_barrier_set);

	// Generates the middle layer with the player model.
		for (int i = 0; i < 12; i++) 
		{
			for (int k = 0; k < Player_posistion.size(); k++)
			{
				if (Player_posistion[k] != 1)
					cout << empty_cell[i];
				else
					cout << player_cell[i];
			}
			cout << endl;
		}

		New_Layer(barrier_models, Vrandom_barrier_set, repetitions, types_of_barriers, random_barrier_model);

	// Generates a new layer with empty cells that increases in size.
		for (int i = 0; i < image_movement; i++) {
			cout << empty_cell[i] << empty_cell[i] << empty_cell[i] << endl;
		}

		if (image_movement == 0)
			Sleep(0100);

		Sleep(0050);

		image_movement = image_movement + 2; // Determines how many times the overall image makes small shifts.
	}	
}