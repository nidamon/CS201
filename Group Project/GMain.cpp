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

// Map for file I/O
map<int, pair <string, int>> player_saves;

// Vector for file I/O
vector<pair <string, int>> saves_premap;


int main()
{
    player_cell = player_model_1;

    int High_score = 0;
    int score = 0;
    int lives = 0;
    int repetitions = 0;
    int barriers_dodged_in_a_row = 0;


    // Menu loops over everything --> backout brings to menu
    while (true)
    {
        int select = 0;
        select = Menu(Titles);

 
        if (select == 1) // Play if 1
        {
            lives += 3;
            score = 0;
            repetitions = 0;
            while (lives != 0) {
                Layers(
                    barrier_models,
                    empty_cell,
                    player_cell,
                    Player_posistion,
                    repetitions,
                    Vlast_generated_barrier_set,
                    Vrandom_barrier_set,
                    random_barrier_model);

                cout << endl;
                cout << "Lives left: " << lives << "   Score: " << score << "   Dodge streak: " << barriers_dodged_in_a_row << endl;
                cout << endl;

                Movement(
                    barrier_models,
                    player_cell,
                    empty_cell,
                    Vlast_generated_barrier_set,
                    random_barrier_model,
                    Player_posistion);

                Crash(
                    Player_posistion,
                    Vrandom_barrier_set,
                    repetitions,
                    barriers_dodged_in_a_row,
                    lives,
                    score);

                repetitions++;
            }
            Game_over_display(Game_over, score, High_score);
        }
        else if (select == 3)
        {
            Save_Load_game(saves_premap, player_saves, High_score);
            Sleep(2000);
            cout << "Closing soon!";
            Sleep(2000);
        }

        else if (select == 5) // Quit if 5
        {
            cout << endl;
            cout << "     Come Again!";
            Sleep(2000);
            break;
        }



    }
    return 0;
}


