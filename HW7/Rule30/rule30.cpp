/*rule30.cpp
Nathan Damon
CS 201
4/19/2020
This program will output a cellular automata.
Lots of help from The Coding Train and his video:
        "7.2: Wolfram Elementary Cellular Automata - The Nature of Code"
*/

#include<windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
#include <vector>
using std::vector;

class RuleWolfram
{
public:
    int rules(int a, int b, int c); // Rules for RuleWolfram

    void set_gen_size(int columns); // Sets the size of each row
    void generate(); // Creates the new generation based on the previous one
    void output(); // Displays the row of the current generation

    int a = 0;
    int b = 0;
    int c = 0;
    int gen_count = 0; // Counts the number of generations as generated
    vector<int> ruleset = {}; // Blank ruleset
    vector<int> current_generation = {};
    vector<int> next_generation;

};



int main()
{
    RuleWolfram rule30;
    vector<int> rule_30 = { 0, 0, 0, 1, 1, 1, 1, 0 };
    int rows = 20;
    int columns = 40;
    rule30.set_gen_size(columns);
    rule30.ruleset = rule_30; // Sets the ruleset in the class to rule 30
    for (int i = 0; i < (rows / 15); i++)
        cout << endl;
    for (int i = 0; i < rows; i++)
        rule30.output();

    // Stops the console from closing.
    cout << "Don't Scroll or the pixels will be lost!" << endl;
    int q;
    cin >> q;

    return 0;
}


// Rules for rule30
int RuleWolfram::rules(int a, int b, int c)
{
    if (a == 1 && b == 1 && c == 1) return ruleset[0];
    if (a == 1 && b == 1 && c == 0) return ruleset[1];
    if (a == 1 && b == 0 && c == 1) return ruleset[2];
    if (a == 1 && b == 0 && c == 0) return ruleset[3];
    if (a == 0 && b == 1 && c == 1) return ruleset[4];
    if (a == 0 && b == 1 && c == 0) return ruleset[5];
    if (a == 0 && b == 0 && c == 1) return ruleset[6];
    if (a == 0 && b == 0 && c == 0) return ruleset[7];
}


// Sets the size of each row
void RuleWolfram::set_gen_size(int columns)
{
    current_generation.resize(columns, 0);
    current_generation[(current_generation.size()/2)] = 1;
    next_generation.resize(columns, 0);
}


// Creates the new generation based on the previous one
void RuleWolfram::generate()
{
    for (size_t i = 1; i < current_generation.size()-1; i++)
    {
        int left = current_generation[i - 1];
        int middle = current_generation[i];
        int right = current_generation[i + 1];
        next_generation[i] = rules(left, middle, right);
    }
    current_generation = next_generation; // Sets the current gen to the new gen
    gen_count++;
}


// Displays the row of the current generation
void RuleWolfram::output()
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);

    // Colors
    COLORREF light = RGB(0, 0, 0);
    COLORREF dark = RGB(255, 255, 255);
    COLORREF Color = RGB(255, 255, 255);

    //Draw pixels
    for (int i = 0; i < current_generation.size(); i++)
    {
        if (current_generation[i] == 0)
            Color = dark;
        if (current_generation[i] == 1)
            Color = light;
        SetPixel(mydc, i, gen_count, Color);
    }
    generate();
}