/*Gproject.h
Nathan Damon
CS 201
3/25/2020
This header will declare all of the functions from the used in Gmain.
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
