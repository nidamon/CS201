/*floating point.h
Nathan Damon
CS 201
3/23/2020
This header will declare floating point.cpp as a function.
*/

#ifndef floating_point_H
#define floating_point_H

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>
using std::size_t;
using std::cout;
using std::endl;
const double PI = std::acos(-1);

std::vector<double> degreesToRadians(int degree);

#endif