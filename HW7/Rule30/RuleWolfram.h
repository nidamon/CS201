/*RuleWolfram.h
Nathan Damon
CS 201
4/19/2020
This header file will contain the declarations for the RuleWolfram class.
*/

#ifndef RuleWolfram_H
#define rule30_Cpp

#include<windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
#include <vector>
using std::vector;
#include <sstream>
using std::istringstream;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;

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

class Image3
{
public:
    bool savePPM(const std::string& path, const RuleWolfram& rule) const;
};


#endif
