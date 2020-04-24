/*Agent.h
Nathan Damon
CS 201
4/21/2020
This header will declare the class Agent's declarations.
*/

#ifndef Agent_H
#define Agent_ccp

#include "thermostat.h"

class Agent
{
public:
	Agent() : _act{ false }, _current_temp{ 0 }, _lower{ 0 }, _upper{ 5 }  {};
	void perceive(Environment& location); // Gets the temperature from environment a
	void think();
	void get_range(int lower, int upper);
	
	void act(Environment& location);



private:
	int _current_temp;
	int _lower;
	int _upper;
	bool _act; // Tells the Environment to turn the heater on or off
};

#define Agent_H
#endif
