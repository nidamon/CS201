/*Simulator.cpp
Nathan Damon
CS 201
4/21/2020
This header will define the class Simulator's functions.
*/

#include "thermostat.h"

void Simulator::askOwner() // Asks whether to continue or not
{
	string select_str;
	int select;
	if (_iter_count > 0)
	{
		cout << setw(9) << right << "1) " << "Continue" << endl;
		cout << setw(9) << right << "2) " << "Quit" << endl;
		cout << setw(6) << right << "E" << "nter a number to select an option: ";


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
		cout << endl;
		if (select == 2)
		{
			_proceed = false;
			return;
		}
		else
			_proceed = true;
	}
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
	_iter_count++;
}

void Simulator::run() // Runs the simulation 
{
	Environment Room;
	Agent Thermo;
	int i = 10;
	while (i < 11)
	{
		if (i == 10)
		{
			askOwner();
			i = 0;
		}
		if (_proceed)
			for (int k = 0; k < 10; k++)
			{
				Room.itteration();
				Thermo.perceive(Room);
				Thermo.get_range(_lower, _upper);
				Thermo.think();
				Thermo.act(Room);
				i++;
				if (i > 10)
					break;
			}
		else
			break;
	}
}