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
	for (int i = 0; i < 5; i++)
		Room.itteration();
	cout << Room.get_temp();
	cout << endl;
	Neo.askOwner();
	cout << "Range: " << Neo._lower << " - " << Neo._upper << endl;

	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}