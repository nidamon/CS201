/*Simulator.h
Nathan Damon
CS 201
4/21/2020
This header will declare the class Simulator's declarations.
*/

#ifndef Simulator_H
#define Simulator_ccp

#include "thermostat.h"
#include "Environment.h"
#include "Agent.h"

class Simulator
{
public:
	void run(); // Calls: 
	// Environment.itteration(),
	// Agent.perceive(Evnironment), 
	// Agent.think(),
	// Agent.act(Environment), 
	// Simulator.askOwner()

private:

};

#define Simulator_H
#endif
