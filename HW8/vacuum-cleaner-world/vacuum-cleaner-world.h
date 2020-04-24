/*vacuum-cleaner-world.h
Nathan Damon
CS 201
4/23/2020
This header will declare all of the headers for vacuum-cleaner-world, agent, environment, and simulator.
*/

#ifndef vacuumcleanerworld_H
#define vacuumcleanerworld_H

// When I put the classes in seperate files, they did not want to use vector at all. 
// I could not figure out why, so I opted to go back to having fewer files.

//#include "simulator.h"
//#include "environment.h"
//#include "agent.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <random>
using std::random_device;
#include <Windows.h>

class environment
{
public:
	environment() : _world{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } {};
	void dirt(int& moves, random_device& r); // Randomly puts down dirt

	vector<int> _world; // Vector representing the world
};

class agent
{
public:
	agent() : _moves{ 0 }, _pos{ 0 }, _left{ false }, _right{ false }, _vacuum{ false }{};
	void get_dirt_loc(environment& house); // Gets the location of the nearest dirt
	void vac_it(environment& house); // agent tells environment that that location no longer has dirt

	int _moves; // Number of moves made by the vacuum
	bool _left;
	bool _right;
	bool _vacuum; // Clean here
	int _pos; // Vacuum location
};

class simulator
{
public:
	void move(agent& vac); // Moves the vacuum cleaner left or right
	void simulate(int& repeat); // Simulates the world
};

#define vacuumcleanerworld_H
#endif
