/*Simulator.h
Nathan Damon
CS 201
4/21/2020
This header will declare the class Simulator's declarations.
*/

#ifndef Simulator_H
#define Simulator_ccp

#include "thermostat.h"

class Simulator
{
public:
	Simulator() : _lower { 0 }, _upper{ 5 } {};
	//void run(); // Calls: 
	// Environment.itteration(),
	// Agent.perceive(Environment a), 
	// Agent.think(),
	// Agent.act(Environment), 
	// Simulator.askOwner()
	void askOwner(); // Gets the temperature range from the user

	int _lower;
	int _upper;

private:

};

#define Simulator_H
#endif
