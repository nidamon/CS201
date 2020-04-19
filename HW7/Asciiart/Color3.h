// Color3.hpp
// Interface for Color3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#ifndef COLOR3_H
#define COLOR3_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iomanip>
using std::setw;
using std::right;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;
#include <Windows.h>

class Color3
{
public:
	Color3();
	Color3(int R, int G, int B);

	// Returns 0.2126R + 0.7152G + 0.0722B
	int weightedSum() const;

	// Returns an ASCII char representing darkness
	// e.g. ' ' = WHITE and 'W' = BLACK
	char asciiValue() const;

	unsigned char r;
	unsigned char g;
	unsigned char b;

	int R;
	int G;
	int B;
};

std::ostream& operator<<(std::ostream& ostr, const Color3& color);
std::istream& operator>>(std::istream& istr, Color3& color);

#endif

