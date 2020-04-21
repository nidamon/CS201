/*Gproject.h
Nathan Damon
CS 201
3/25/2020
This header will declare all of the functions used in Gmain and will contain a set of vectors that hold strings for the game.
*/

#ifndef Gproject_H
#define Gproject_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <random>
using std::random_device;
#include <string>
using std::string;
#include <iomanip>
using std::setw;
using std::right;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <map>
using std::map;
#include <utility>
using std::pair;
#include <ios>
using std::left;

using std::size_t;





const vector <string> Title1 = {
 " //////   /////    //////   //////      //////      ////   //       //",
 " //       //  //   //       //          //        //  //   //       //",
 " /////    /////    //////   //////      /////    //////    //       //",
 " //       //  //   //       //          //      //  //     //       //",
 " //       //  //   //////   //////      //     //  //      //////   //////"
};

const vector <string> Title2 = {
 "     //////   /////    //////   //////      //////    ////       //       //",
 "    //       //  //   //       //          //       //  //      //       //",
 "   /////    /////    //////   //////      /////    //////      //       //",
 "  //       //  //   //       //          //       //  //      //       //",
 " //       //  //   //////   //////      //       //  //      //////   //////"
};

const vector <string> Title3 = {
 " //////   /////    //////   //////      //////   ////    //       //",
 " //       //  //   //       //          //      //  //   //       //",
 " /////    /////    //////   //////      /////   //////   //       //",
 " //       //  //   //       //          //      //  //   //       //",
 " //       //  //   //////   //////      //      //  //   //////   //////"
};


const vector < vector <string>> Titles = {
    Title1,
    Title2,
    Title3
};

// Displayed for game over
const vector <string> Game_over = {
 "    //////     ////    //      //   //////       //////    //    //   //////   /////",
 "  //          //  //   ///    ///   //          //    //   //    //   //       //  //",
 "  //   ////   //////   ////  ////   //////      //    //   //    //   //////   /////",
 "  //     //   //  //   // //// //   //          //    //    //  //    //       //  //",
 "   //////     //  //   //  //  //   //////       //////       //      //////   //  //"
};


// Below are the integers 0 - 9
const vector <string> zero = {
"/////", //     "/////"
"/   /", //    "/   /"
"/   /", //   "/   /"
"/   /", //  "/   /"
"/////"  // "/////" 
};

const vector <string> one = {
"  /  ", //     "  /  "
" //  ", //    " //  "
"  /  ", //   "  /  "
"  /  ", //  "  /  "
" /// "  // " /// "
};

const vector <string> two = {
"/////", //     "/////"
"    /", //    "    /"
"/////", //   "/////"
"/    ", //  "/    "
"/////"  // "/////"
};

const vector <string> three = {
"/////", //     "/////"
"    /", //    "    /"
"/////", //   "/////"
"    /", //  "    /"
"/////"  // "/////"
};

const vector <string> four = {
"/  / ", //     "/  / "
"/  / ", //    "/  / "
"/////", //   "/////"
"   / ", //  "   / "
"   / "  // "   / "
};

const vector <string> five = {
"/////", //     "/////"
"/    ", //    "/    "
"/////", //   "/////"
"    /", //  "    /"
"/////"  // "/////"
};

const vector <string> six = {
"/////", //     "/////"
"/    ", //    "/    "
"/////", //   "/////"
"/   /", //  "/   /"
"/////"  // "/////"
};

const vector <string> seven = {
"/////", //     "/////"
"    /", //    "    /"
"    /", //   "    /"
"    /", //  "    /"
"    /"  // "    /"
};

const vector <string> eight = {
"/////", //     "/////"
"/   /", //    "/   /"
"/////", //   "/////"
"/   /", //  "/   /"
"/////"  // "/////" 
};

const vector <string> nine = {
"/////", //     "/////"
"/   /", //    "/   /"
"/////", //   "/////"
"/   /", //  "    /"
"/////"  // "/////" 
};

const vector <vector <string>> big_numbers = {
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine
};


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

const vector <string> barrier_model_2 = { // Empty box
 "|                            |",
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
 "|                            |",
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

// Vector of barrier models
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
 "Gingerbread Man"
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
 "The Bat"
};

const vector <string> player_model_3 = { // That Pizza
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|       //\"\"--.._            |",
 "|      ||  (_)  _\"-._        |",
 "|      ||    _ (_)    '-.    |",
 "|      ||   (_)   __..-'     |",
 "|       \\\\__..--\"\"           |",
 "|                            |",
 "|                            |",
 "|                            |",
 "That Pizza"
};

const vector <string> player_model_4 = { // Fish outa Water
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|            ,--,_           |",
 "|     __    _\\.---'-.        |",
 "|     \\ '.-\"     // o\\       |",
 "|     /_.'-._    \\\\  /       |",
 "|            `\"--(/\"`        |",
 "|                            |",
 "|                            |",
 "|                            |",
 "Fish outa Water"
};

const vector <string> player_model_5 = { // Birds on a branch
 "|                            |",
 "|    __                      |",
 "|   ( ->                     |",
 "|   / )\\               __    |",
 "|  <_/_/    __        <- )   |",
 "| -=\"=\"--,_( ->       /( \\   |",
 "|          / )\\--,__  \\_\\_>  |",
 "|         <_/_/  ___)`\"=\"=-  |",
 "|      ---=\"=\"-````\\\\        |",
 "|                   \\\\       |",
 "|                   //       |",
 "|                   ``       |",
 "Birds on a branch"
};

const vector <string> player_model_6 = { // The Spyder
 "|                            |",
 "|                            |",
 "|                            |",
 "|            __              |",
 "|         | /  \\ |           |",
 "|        \\_\\\\  //_/          |",
 "|          //()\\\\            |",
 "|          \\\\  //            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "|                            |",
 "The Spyder"
};

const vector <string> player_model_7 = { // Playing too much
 "|                            |",
 "|                            |",
 "|     /______\\  /______\\     |",
 "|      (~ o ~)  (~ o ~)      |",
 "|     \\ '-=-'/  \\'-=-' /     |",
 "|      '.__.'    '.__.'      |",
 "|             ^^             |",
 "|          ________          |",
 "|         //======\\\\         |",
 "|         \\\\      //         |",
 "|          \\\\____//          |",
 "|                            |",
 "Playing too much"
};

// Vector of player models
const vector <vector <string>> player_models = {
    player_model_1, // Gingerbread man
    player_model_2, // The Bat
    player_model_3, // That Pizza
    player_model_4, // Fish outa Water
    player_model_5, // Birds on a branch
    player_model_6, // The Spyder
    player_model_7 // Playing too much
};


// Sub menu for Picking a diffent player model.
void Skins_Menu(
    vector <string>& player_cell,
    const vector <vector <string>>& player_models,
    const int& High_score);


// Menu for picking skins(unavailable atm), playing, saving (unavailable atm), or quiting
int Menu(
    const vector < vector <string>>& Titles);


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


// Crash determines whether or not the player has hit an obsticle
void Crash(
    const vector <int>& Player_posistion,
    const vector <int>& Vrandom_barrier_set,
    const int& repetitions,
    int& most_barriers_dodged_in_a_row,
    int& barriers_dodged_in_a_row,
    int& lives,
    int& score);


// Displays Game over and updates the high score if needed.
void Game_over_display(
    const vector <string>& Game_over,
    const int& score,
    const int& most_barriers_dodged_in_a_row,
    int& players_most_barriers_dodged_in_a_row,
    int& High_score,
    int& Highest_score);


// Sub menu for saving or loading.
int Save_load_Menu();


// Loads the saves of the games.
int Pre_load_saves(
    vector<pair <string, int>>& saves_premap,
    vector<pair <string, int>>& player_dodge_saves_premap,
    map<int, pair <string, int>>& player_saves,
    map<string, int>& player_dodge_saves,
    int& Highest_score);


// Alows for the loading of the games.
int Load_game(
    map<int, pair <string, int>>& player_saves,
    map<string, int>& player_dodge_saves,
    int& High_score,
    int& Highest_score,
    int& players_most_barriers_dodged_in_a_row);


// Alows for the saving of the games.
int Save_game(
    map<int, pair <string, int>>& player_saves,
    map<string, int>& player_dodge_saves,
    const int& High_score,
    const int& players_most_barriers_dodged_in_a_row);


// Outputs large digits for integer input
void Big_output(
    const int& lives,
    const int& score,
    const int& barriers_dodged_in_a_row,
    const vector <vector <string>>& big_numbers);


// About page.
void About();
#endif
