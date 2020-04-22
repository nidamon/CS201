/*thermostat.cpp
Nathan Damon
CS 201
4/21/2020
This program will use classes to imitate a thermostat 
*/

#include "thermostat.h"

int main()
{
	Environment Room;
	Agent Thermo;
	Simulator Neo;
	
	//Neo.run(Room, Thermo);
	bool proceed = false;
	int i = 10;
	while (i < 11)
	{
		if (i == 10)
			proceed = Neo.askOwner();
		if (proceed)
			i = 0;
		proceed = false;
		Room.itteration();
		Thermo.perceive(Room);
		Thermo.get_range(Neo);
		Thermo.think();
		Thermo.act(Room);
		i++;
	}

	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}