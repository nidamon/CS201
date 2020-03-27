/*GMain.cpp
Nathan Damon
CS 201
3/25/2020
This file will contain the code for the menu and the code to call all of the functions used for the game.
*/

#include "Gproject.h"

vector <int> Vrandom_barrier_set(3, 0); // Used to hold one of six different sets of barriers
vector <int> Vlast_generated_barrier_set(3, 0); // Copies down the barrier model for printing the previous set of barriers.
vector <int> random_barrier_model(3, 0); // Used for barrier randomization.
vector <int> Player_posistion = { 0, 1, 0 }; // Starts the player in the center and is used in the movement function.
vector <string> player_cell; // Will hold a specified player model.

int main()
{
    player_cell = player_model_1;

    int lives = 1;
    int repetitions = 0;

    while (lives == 1) {
        Layers(
            barrier_models,
            empty_cell,
            player_cell,
            Player_posistion,
            repetitions,
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
    }

    return 0;
}


