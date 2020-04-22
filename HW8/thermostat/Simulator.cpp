/*Simulator.cpp
Nathan Damon
CS 201
4/21/2020
This header will define the class Simulator's functions.
*/

#include "thermostat.h"

void Simulator::askOwner()
{
	cout << "Specify a lower temperature bound: ";
	string select_str;
	while (true) // Gets the user's lower bound selection
	{
		std::getline(cin, select_str);
		istringstream instream(select_str);
		instream >> _lower;
		if (instream)
			break;
		cout << "You need to enter an integer: ";
	}

	cout << "Specify an upper temperature bound: ";

	int upper;
	while (true) // Gets the user's upper bound selection
	{
		std::getline(cin, select_str);
		istringstream instream(select_str);
		instream >> upper;
		if (instream)
			if (upper > _lower)
				break;
		cout << "You need to enter an integer greater than your lower bound: ";
	}
	_upper = upper;
}