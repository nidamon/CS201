/*vacuum-cleaner-world.cpp
Nathan Damon
CS 201
4/23/2020
This program will use classes to imitate a mobile vacuum cleaner.
*/

#include "vacuum-cleaner-world.h"
// When I put the classes in seperate files, they did not want to use vector at all. 
// I could not figure out why, so I opted to go back to having fewer files.

int main()
{
	simulator Neo;
	int repeat = 80;
	Neo.simulate(repeat);
	
	cout << endl;
	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}

// Class member functions below in order of creation

// Randomly puts down dirt
void environment::dirt(int& moves, random_device& r)
{
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, _world.size() - 1);
	if (moves % 7 == 0)
		_world[uniform_dist(e1)] = 1;
}

// Gets the location of the nearest dirt
void agent::get_dirt_loc(environment& house)
{
	int close_dirt = 0;
	int close_dirt_dist = 9;
	int distance = 9;
	for (size_t i = 0; i < house._world.size(); i++) // Finds location of dirt
	{
		distance = 9;
		if (house._world[i] == 1)
		{
			if (_pos > i)
				distance = (_pos - i);
			if (i > _pos)
				distance = (i - _pos);
			if (_pos == i)
				distance = 0;
			if (distance < close_dirt_dist)
			{
				close_dirt_dist = distance;
				close_dirt = i;
			}
		}
	};
	cout << "Robot obective: ";
	if (close_dirt > _pos)
	{
		cout << "right" << endl;
		_right = true;
		_left = false;
		_vacuum = false;
	}
	if (close_dirt < _pos)
	{
		cout << "left" << endl;
		_left = true;
		_right = false;
		_vacuum = false;
	}
	if (close_dirt == _pos)
	{
		cout << "Vacuum" << endl;
		_vacuum = true;
		_right = false;
		_left = false;
	}
}

// Moves the vacuum cleaner left or right
void simulator::move(agent& vac)
{
	if (vac._right)
		vac._pos += 1;
	if (vac._left)
		vac._pos -= 1;
}

// Agent tells environment that that location no longer has dirt
void agent::vac_it(environment& house)
{
	if (_vacuum)
		house._world[_pos] = 0;
}

// Simulates the world
void simulator::simulate(int& repeat)
{
	environment house;
	agent vac;
	random_device r;

	for (int j = 0; j < repeat; j++)
	{
		system("cls"); // refreshes the console screen.

		house.dirt(j, r);
		vac.get_dirt_loc(house);
		for (size_t i = 0; i < house._world.size(); i++)
		{
			if (vac._pos == i)
				cout << "[=]"; // Icon for vacuum
			else
				cout << "   ";
		}

		cout << endl;
		for (size_t i = 0; i < house._world.size(); i++)
			cout << " " << house._world[i] << " ";
		cout << endl;

		if (!vac._vacuum)
			move(vac);
		else
		{
			Sleep(0200); // Gives some delay to see the vacuum cleaning
			vac.vac_it(house);
		}
		vac._moves++;
		Sleep(0400);
	}
}