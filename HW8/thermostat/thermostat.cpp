/*thermostat.cpp
Nathan Damon
CS 201
4/21/2020
This program will use classes to imitate a thermostat 
*/

#include "thermostat.h"
#include "Simulator.h"


int main()
{
	Environment Room;
	for (int i = 0; i < 5; i++)
		Room.itteration();
	cout << Room.get_temp();
	cout << endl;


	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}