/*vacuum-cleaner-world.cpp
Nathan Damon
CS 201
4/23/2020
This program will use classes to imitate a mobile vacuum cleaner.
*/

#include "vacuum-cleaner-world.h"

// When I put the classes in seperate files, they did not want to use vector at all. 
// I could not figure out why, so I opted to go back to having fewer files.



class environment
{
public:
	environment() : _world{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } {};
	void dirt(int& moves, random_device& r); // Randomly puts down dirt

	vector<int> _world; // Vector representing the world

private:
	
};

class agent
{
public:
	agent() : _moves{ 0 }, _vac_position{ 0, 0, 0, 1, 0, 0, 0, 0, 0 }, _left{ false }, _right{ false }{};
	void get_dirt_loc(environment& house); // Gets the location of the nearest dirt
	int _moves; // Number of moves made by the vacuum

	vector<int> _vac_position; // Vector representing location of vacuum
private:
	bool _left;
	bool _right;
};

class simulator
{
public:
	//simulator() : {}

private:

};



int main()
{
	environment house;
	agent vac;
	random_device r;

	for (int j = 0; j < 50; j++)
	{
		system("cls"); // refreshes the console screen.
		for (size_t i = 0; i < house._world.size(); i++)
			cout << " " << house._world[i];
		cout << endl;
		house.dirt(j, r);
		vac.get_dirt_loc(house);
		for (size_t i = 0; i < vac._vac_position.size(); i++)
			cout << " " << vac._vac_position[i];
		cout << endl;
		vac._moves++;
		Sleep(0100);
	}
	cout << endl;
	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}

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
	int pos = 0;

	for (size_t i = 0; i < _vac_position.size(); i++) // Finds location of vacuum
	{
		if (_vac_position[i] == 1)
		{
			pos = i;
			break;
		}
	}
	int close_dirt = 0;
	int close_dirt_dist = 9;
	int distance = 9;
	for (size_t i = 0; i < house._world.size(); i++) // Finds location of dirt
	{
		distance = 9;
		if (house._world[i] == 1)
		{
			if (pos > i)
				distance = (pos - i);
			if (i > pos)
				distance = (i - pos);
			if (pos == i)
				distance = 0;
			if (distance < close_dirt_dist)
			{
				close_dirt_dist = distance;
				close_dirt = i;
			}
		}
	};
	if (close_dirt > pos)
	{
		cout << "right" << endl;
		_right = true;
	}
	if (close_dirt < pos)
	{
		cout << "left" << endl;
		_left = true;
	}
	if (close_dirt == pos)
	{
		cout << "stay" << endl;
	}
}