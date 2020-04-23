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
	agent() : _moves{ 0 }, _pos{0}, _left{ false }, _right{ false }, _vacuum{ false }{};
	void get_dirt_loc(environment& house); // Gets the location of the nearest dirt
	
	int _moves; // Number of moves made by the vacuum

	bool _left;
	bool _right;
	bool _vacuum;
	int _pos;
private:

};

class simulator
{
public:
	//simulator() : {}
	void move(agent& vac); // Moves the vacuum cleaner left or right

private:

};



int main()
{
	simulator Neo;
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
		for (size_t i = 0; i < house._world.size(); i++)
		{
			if (vac._pos == i)
				cout << " " << 1;
			else
				cout << "  ";
		}
		Neo.move(vac);
		cout << endl;
		vac._moves++;
		Sleep(0400);
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
		cout << "stay" << endl;
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