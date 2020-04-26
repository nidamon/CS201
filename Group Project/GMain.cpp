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
map<string, int> player_dodge_saves;

// Vector for file I/O
vector<pair <string, int>> saves_premap;
vector<pair <string, int>> player_dodge_saves_premap;

// Makes it possible to color text
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

int main()
{
    player_cell = player_model_1; // Default model is the Gingerbread man

    int High_score = 0;
    int Highest_score = 0;
    int score = 0;
    int lives = 0;
    int repetitions = 0;
    int barriers_dodged_in_a_row = 0;
    int most_barriers_dodged_in_a_row = 0;
    int players_most_barriers_dodged_in_a_row = 0;

    auto color_text = [](int color, HANDLE& hConsole) // Color based on input
    {
        SetConsoleTextAttribute(hConsole, color);
    };

    Pre_load_saves(saves_premap, player_dodge_saves_premap, player_saves, player_dodge_saves, Highest_score);
    system("cls"); // refreshes the console screen.


    // Menu loops over everything --> backout brings to menu
    while (true)
    {
        int select = Menu(Titles, hConsole); // Outputs the title

        if (select == 1) // Play if 1
        {
            lives += 3;
            score = 0;
            Player_posistion = { 0, 1, 0 };
            Vlast_generated_barrier_set = { 0, 0, 0 };
            most_barriers_dodged_in_a_row = 0;
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
                color_text(10, hConsole); // Green
                cout << setw(2) << right << "L" << "ives left: " << lives;
                color_text(14, hConsole); // Yellow
                cout << setw(23) << right << "S" << "core: " << score;
                color_text(11, hConsole); // Light blue
                cout << setw(24) << right << "D" << "odge streak: " << barriers_dodged_in_a_row << endl;
                color_text(7, hConsole); // Default white
                Big_output(
                    lives,
                    score,
                    barriers_dodged_in_a_row,
                    big_numbers,
                    hConsole);
                cout << endl;

                Movement(
                    barrier_models,
                    player_cell,
                    empty_cell,
                    Vlast_generated_barrier_set,
                    random_barrier_model,
                    Player_posistion,
                    hConsole);

                Crash(
                    Player_posistion,
                    Vrandom_barrier_set,
                    repetitions,
                    most_barriers_dodged_in_a_row,
                    barriers_dodged_in_a_row,
                    lives,
                    score);

                repetitions++;
            };
            Game_over_display(
                Game_over, 
                score, most_barriers_dodged_in_a_row, 
                players_most_barriers_dodged_in_a_row, 
                High_score, 
                Highest_score,
                hConsole);
        }
        else if (select == 2) // Skin menu if 2
        {
            Skins_Menu(
                player_cell,
                player_models,
                High_score,
                hConsole);
        }
        else if (select == 3) // Saves menu if 3
        {
            while (true)
            {
                int sub_select = Save_load_Menu(hConsole);
                if (sub_select == 1) // Load menu if 1
                {
                    Pre_load_saves(saves_premap, player_dodge_saves_premap, player_saves, player_dodge_saves, Highest_score);
                    Load_game(player_saves, player_dodge_saves, High_score, Highest_score, players_most_barriers_dodged_in_a_row);
                }
                if (sub_select == 2) // Save menu if 2
                    Save_game(player_saves, player_dodge_saves, High_score, players_most_barriers_dodged_in_a_row);
                if (sub_select == 3) // Quit if 3
                    break;
            }
            cout << "Closing soon!";
        }
        else if (select == 4) // About page if 4
            About();
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


