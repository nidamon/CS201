/*Simulator.cpp
Nathan Damon
CS 201
4/21/2020
This header will define the class Simulator's functions.
*/

#include "thermostat.h"

bool Simulator:: askOwner()
{
	cout << setw(9) << right << "1) " << "Continue" << endl;
	cout << setw(9) << right << "2) " << "Quit" << endl;
	cout << setw(7) << right << "E" << "nter a number to select an option: ";

	string select_str;
	int select;
	while (true) // Gets the users selection
	{
		std::getline(cin, select_str);
		istringstream instream(select_str);
		instream >> select;
		if (instream)
			if (select > 0)
				if (select < 3)
					break;
		cout << "You need to enter 1 or 2: ";
	}
	if (select == 2)
		return false;

	cout << "Specify a lower temperature bound: ";
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
	return true;
}

// Calls: 
	// Environment.itteration(),
	// Agent.perceive(Environment a), 
	// Agent.think(),
	// Agent.act(Environment), 
	// Simulator.askOwner()
//void Simulator::run(Environment location, Agent thermo)
//{
//	bool proceed;
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 9)
//			proceed = askOwner();
//		if (proceed)
//			i = 0;
//		location.itteration();
//		thermo.perceive(location);
//		thermo.think();
//		thermo.act(location);
//	}
//}