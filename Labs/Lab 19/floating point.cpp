/*floating point.cpp
Nathan Damon
CS 201
3/23/2020
This program will calculate a radian for every degree given and put it into a vector called radians.
*/

#include "floating point.h"

#define _USE_MATH_DEFINES

std::vector<double> degreesToRadians(int degrees) {

	std::vector<double> radians(degrees + 1);
	double new_radian;

	// for each degree, fill the vector with its radian
	for (int degree = 0; degree <= degrees; degree++) {
		// TODO: calculate a radian and add it to the vector****************
		new_radian = (degree * (PI / 180.0));
		radians[degree] = new_radian;

		// *****************************************************************
	}
	return radians;
}