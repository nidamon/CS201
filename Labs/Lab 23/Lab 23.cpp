/*Lab 23.cpp
Nathan Damon
CS 201
3/31/2020
This file will use map.
*/

#include <map>
using std::map;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <Windows.h>
#include <iomanip>
using std::setw;
#include <ios>
using std::left;

map<string, string> dialogue = {
	{ "Hello", "Hi!"},
	{ "Morning!", "Mornin'! How's your day been?"},
	{ "Good", "Thats great!"},
	{ "What?!", "I know right..."},
	{ "Due_when?", "...  5 minutes ago..."}
};

int main()
{


	srand(time(0));
	int randvalue = ((rand()) % 5);
	switch (randvalue)
	{
	case 0:
		dialogue.erase("Hello");
		break;
	case 1:
		dialogue.erase("Morning!");
		break;
	case 2:
		dialogue.erase("Good");
		break;
	case 3:
		dialogue.erase("What?!");
		break;
	case 4:
		dialogue.erase("Due_when?");
		break;
	}


	for (const auto& p : dialogue)
	{
		auto k = p.first;
		auto v = p.second;
		cout << "Person A: " << setw(12) << left << k <<  "Person B: " << v;
		cout << endl;
		Sleep(0700);
	}




	//while (true)
	//{
	//	string str; 
	//	cout << "Say something: ";
	//	cin >> str;
	//	if (str == "stop")
	//		break;
	//	else
	//	{
	//		int item_count = dialogue.count(str);
	//		if (item_count != 0)
	//			cout << "Person B:      " << dialogue[str] << endl;
	//		else
	//		{
	//			cout << endl;
	//			cout << "No one responds..." << endl;
	//			cout << endl;
	//		}	
	//	}
	//}




	int q;
	cin >> q;
}