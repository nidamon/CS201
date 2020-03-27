/*Gproject.h
Nathan Damon
CS 201
3/25/2020
This header will declare all of the functions used in Gmain and will contain a set of vectors that hold strings for the game.
*/

#ifndef Gproject_H
#define Gproject_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using std::size_t;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;


// Below is the empty cell and the barrier models.

const vector <string> empty_cell = { // This is the empty cell
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
};

const vector <string> barrier_model_1 = { // Rabbit box
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

const vector <string> barrier_model_2 = { // Empty box
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

const vector <string> barrier_model_3 = { // "Person A" box
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

const vector <vector <string>> barrier_models = {
    empty_cell, // This is the empty cell
    barrier_model_1, // Rabbit box
    barrier_model_2, // Empty box
    barrier_model_3, // "Person A" box
};



// Player Models below.



const vector <string> player_model_1 = { // Gingerbread man
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

const vector <string> player_model_2 = { // The Bat
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
	const vector <vector <string>>& barrier_models,
	const vector <int>& Vrandom_barrier_set,
	const int& repititions,
	vector <int>& random_barrier_model);


// Layers contains the functions and code to output all the visuals.
void Layers(
	const vector<vector<string>>& barrier_models,
	const vector <string>& empty_cell,
	const vector <string>& player_cell,
	const vector <int>& Player_posistion,
	const int& repetitions,
	vector <int>& Vlast_generated_barrier_set,
	vector <int>& Vrandom_barrier_set,
	vector <int>& random_barrier_model);

#endif
