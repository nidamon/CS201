/*Environment.cpp
Nathan Damon
CS 201
4/21/2020
This header will define the class Environment's functions.
*/

#include "thermostat.h"

// Changes temperature depending on heater's state
void Environment::itteration()
{
	if (_heater)
		_temperature += 1;
	else
		_temperature -= 1;
	cout << _temperature << endl;
}

// Returns the temperature
int Environment::get_temp()
{
	return _temperature;
}