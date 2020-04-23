/*agent.cpp
Nathan Damon
CS 201
4/23/2020
This header will define the class agent's functions.
*/

//#include "vacuum-cleaner-world.h"
//
//// Gets the location of the nearest dirt
//void agent::get_dirt_loc(environment& house)
//{
//	int pos = 0;
//
//	for (size_t i = 0; i < _vac_position.size(); i++) // Finds location of vacuum
//	{
//		if (_vac_position[i] == 1)
//			pos = i;
//		break;
//	}
//
//	int close_dirt = 0;
//	int close_dirt_dist = 9;
//	int distance = 0;
//	for (size_t i = 0; i < house._world.size(); i++) // Finds location of dirt
//	{
//		if (house._world[i] == 1)
//		{
//			if (pos - i < 0)
//				distance = i - pos;
//			if (pos - i > 0)
//				distance = pos - i;
//			if (distance < close_dirt_dist)
//				close_dirt = i;
//		}
//	}
//
//	if (close_dirt > pos)
//	{
//		cout << "right" << endl;
//		_right = true;
//	}
//	if (close_dirt < pos)
//	{
//		cout << "left" << endl;
//		_left = true;
//	}
//}