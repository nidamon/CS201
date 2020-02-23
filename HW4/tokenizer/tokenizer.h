/*tokenizer.h
Nathan Damon
CS 201
2/22/2020
This header will declare tokenizer.cpp as a function.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::istringstream;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

#ifndef tokenizer_H
#define tokenizer_H

bool ReadLine(string& str);
unsigned StringToTokenWS(const string& input, vector<string>& tokens);


#endif