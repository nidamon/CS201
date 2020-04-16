/*GVectorimages.cpp   ***DOES NOT CONTAIN THE VECTOR IMAGES ANY MORE***
Nathan Damon
CS 201
2/19/2020
This program will contain the functions for the game and will no longer hold the vector images as its name suggests.
The images have been moved to Gproject.h and made into const vectors
*/

#include "Gproject.h"

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

	int Move_from = 0;
	int Move_to;
	int Position_hold; // Temporarily holds a value from Player_posistion during movement

	for (size_t i = 0; i < Player_posistion.size(); i++)
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
	if (distance_of_move > 0) // If moving right
	{
		for (int q = 0; q < distance_of_move; q++)
		{

			for (size_t j = 0; j < empty_cell[0].size(); j = j + 6)
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

			for (size_t j = 0; j < empty_cell[0].size(); j = j + 6)
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
	vector <int>& random_barrier_model)
{
	for (int i = 0; i < 3; i++)
	{
		if (Vrandom_barrier_set[i] == 1) // Picks a random barrier model.
			random_barrier_model[i] = (((((rand()) + repetitions) % (11 + 2 * i)) % (barrier_models.size() - 1)) + 1); // Will need to change the 3 when more than 3 barrier models are made.
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
			for (size_t k = 0; k < Player_posistion.size(); k++)
			{
				if (Player_posistion[k] != 1)
					cout << empty_cell[i];
				else
					cout << player_cell[i];
			}
			cout << endl;
		}

		New_Layer(barrier_models, Vrandom_barrier_set, repetitions, random_barrier_model);

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






// Crash determines whether or not the player has hit an obsticle
void Crash(
	const vector <int>& Player_posistion,
	const vector <int>& Vrandom_barrier_set,
	const int& repetitions,
	int& barriers_dodged_in_a_row,
	int& lives,
	int& score)
{
	int lives_hold = lives;

	for (size_t i = 0; i < Player_posistion.size(); i++)
	{
		if (Player_posistion[i] == 1)
		{
			if (Vrandom_barrier_set[i] == 1)
			{
				lives--;
				barriers_dodged_in_a_row = 0;
			}
		}
	}

	if (lives_hold == lives)
	{
		score = score + 10 * ((barriers_dodged_in_a_row * 2) + (repetitions / 4) + 1);
		barriers_dodged_in_a_row++;
	}
}






// Menu for picking skins(unavailable atm), playing, saving (unavailable atm), or quiting
int Menu(
	const vector < vector <string>>& Titles)
{
	random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, 2);

	system("cls"); // refreshes the console screen.
	int chosen_title = uniform_dist(e1);
	// Title display here
	for (size_t i = 0; i < Title1.size(); i++)
		cout << Titles[chosen_title][i] << endl;
	cout << endl;
	cout << "By Nathan Damon" << endl;
	cout << endl;
	cout << endl;
	cout << setw(9) << right << "1) " << "Play" << endl;
	cout << setw(9) << right << "2) " << "Skins" << endl;
	cout << setw(9) << right << "3) " << "Save your high score" << endl;
	cout << setw(9) << right << "4) " << "Instructions/about" << endl;
	cout << setw(9) << right << "5) " << "Quit" << endl;
	cout << setw(7) << right << "E" << "nter a number to select an option: ";
	
	string select_str; 
	int select;
	while (true) // Gets the users selection
	{
		std::getline(cin, select_str);
		istringstream instream(select_str);
		instream >> select;
		if (instream) // Confirms if there is an int value in cypher_shift_str
			if (select > 0)
				if (select < 6)
					break;
		cout << "You need to enter an integer: ";
	}
	return select;
}






// Displays Game over and updates the high score if needed.
void Game_over_display(
	const vector <string>& Game_over,
	const int& score,
	int& High_score)
{
	system("cls"); // refreshes the console screen.
	// Game over display here
	for (size_t i = 0; i < Game_over.size(); i++)
		cout << Game_over[i] << endl;

	cout << endl;
	cout << endl;
	cout << endl;

	if (score > High_score)
	{
		cout << setw(9) << right << "" << "NEW High Score!!!" << endl;
		cout << setw(9) << right << "" << "Prvious High Score: " << High_score << endl;
		cout << setw(9) << right << "" << "Your Score: " << score << endl;
		High_score = score;
	}
	else
	{
		cout << "Your Score was: " << score << endl;
		cout << "The curent High Score: " << High_score << endl;
	}
	Sleep(5000);
}






// Alows for the saving and loading of the games.
int Save_Load_game(
	vector<pair <string, int>>& saves_premap,
	map<int, pair <string, int>>& player_saves,
	int& High_score)
{
	if (false) // File write
	{
		ofstream fout("Freefall.txt", ios::app);
		if (!fout)
		{
			cout << "Error opening file" << endl;
			return 0;
		}
		else
		{
			//for (int i = 0; i < 10; i++)
			fout << "Testdummy 850" << endl;
			fout << "test 25" << endl;
			fout << "HelloWorld 1001" << endl;
			fout << "Fallendown 12" << endl;
			fout << "Down 357" << endl;

			fout << endl;
			if (!fout)
			{
				cout << "Error writing to file" << endl;
				return 0;
			}
			cout << "Text inputted" << endl;
		}
	}





	pair <string, int> short_use;

	if (true) // File read
	{
		ifstream fin("Freefall.txt");
		if (!fin)
		{
			cout << "Error opening file" << endl;
			return 0;
		}
		else
		{
			while (true)
			{
				string line;
				getline(fin, line);
				if (!fin)
				{
					if (fin.eof())
					{
						cout << "Finished reading file" << endl;
						break;
					}
					else
					{
						cout << "Error during transmit." << endl;
						break;
					}
				}

				istringstream instream(line);
				string name;
				int saved_score;
				instream >> name >> saved_score;
				if (!instream)
					break;

				//cout << line << endl; // If need to check file reading

				short_use.first = name;
				short_use.second = saved_score;
				saves_premap.push_back(short_use);
			}
		}
	}

	auto iter1 = saves_premap.begin();
	auto iter2 = saves_premap.end();
	sort(iter1, iter2);

	short_use.first = "zzzz";
	short_use.second = 0;
	saves_premap.push_back(short_use);

	size_t i = 0;
	int j = 1;
	while (i < saves_premap.size()-1)
	{
		if (saves_premap[i].first != saves_premap[i + 1].first)
		{
			player_saves[j].first = saves_premap[i].first;
			player_saves[j].second = saves_premap[i].second;
			j++;
		}
		i++;
	}





	system("cls"); // refreshes the console screen.

	cout << "  Saves:" << endl;

	cout << "    Id: " << setw(15) << left << "Name: " << "Score:" << endl;
	for (const auto& p : player_saves)
	{
		auto k = p.first;
		auto v = p.second;
		cout << "     " << setw(3) << left << k
			<< setw(15) << left << v.first << " "
			<< setw(4) << left << v.second << endl;
	}



	if (false) // File write
	{
		ofstream fout("Freefall.txt", ios::app);
		if (!fout)
		{
			cout << "Error opening file" << endl;
			return 0;
		}
		else
		{
			//for (int i = 0; i < 10; i++)
			fout << "Testdummy 850" << endl;
			fout << "test 25" << endl;
			fout << "HelloWorld 1001" << endl;
			fout << "Fallendown 12" << endl;
			fout << "Down 357" << endl;

			fout << endl;
			if (!fout)
			{
				cout << "Error writing to file" << endl;
				return 0;
			}
			cout << "Text inputted" << endl;
		}
	}

	string select_str;
	int select;
	while (true) // Gets the users selection
	{
		std::getline(cin, select_str);
		istringstream instream(select_str);
		instream >> select;
		if (instream) // Confirms if there is an int value in cypher_shift_str
			if (select > 0)
				if (select < 6)
					break;
		cout << "You need to enter an integer: ";
	}
	return 0;
}