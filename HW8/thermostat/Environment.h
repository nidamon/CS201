/*Environment.h
Nathan Damon
CS 201
4/21/2020
This header will declare the class Environment's declarations.
*/

#ifndef Environment_H
#define Environment_ccp

#include "thermostat.h"

class Environment
{
public:
	Environment() : _heater{ false }, _temperature{ 50 } {}
	void itteration();
	int get_temp();

private:
	int _temperature;
	bool _heater;
};

#define Environment_H
#endif
