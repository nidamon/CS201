/*Agent.cpp
Nathan Damon
CS 201
4/21/2020
This header will define the class Agent's functions.
*/

#include "thermostat.h"

// Gets the temperature from environment a
void Agent::perceive (Environment location)
{
	_current_temp = location.get_temp();
}

//void Agent::think()
//{
//
//}

//void Agent::get_range(int& a, int& b)
//{
//
//}
