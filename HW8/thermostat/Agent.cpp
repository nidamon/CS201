/*Agent.cpp
Nathan Damon
CS 201
4/21/2020
This header will define the class Agent's functions.
*/

#include "thermostat.h"

// Gets the temperature from environment a
void Agent::perceive (Environment& location)
{
	_current_temp = location.get_temp();
}

// If the temperature is less than the upper bound, then 
// heater is on until below lower range
void Agent::think()
{
	if (_current_temp < _lower)
		_act = true;
	if (_current_temp > _upper)
		_act = false;
}

// Gets the upper and lower bounds from Simulator
void Agent::get_range(int lower, int upper)
{
	_lower = lower;
	_upper = upper;
}

void Agent::act(Environment& location)
{
	location._heater = _act;
}