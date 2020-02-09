/*names
Nathan Damon
CS 201
2/5/2020
This program will take 10 names as input from the user and do something interesting.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;

void InputNames(std::vector<std::string> & names);

int main(int argc, char** argv)
{
	std::vector<std::string> names;
	InputNames(names);

	int q;
	cin >> q;
	return 0;
}

void InputNames(std::vector<std::string> & names)
{
	for (int i = 0; i < 10; i++) {
		std::string name;
		std::cout << "Please enter a name: ";
		std::getline(cin, name);
		names.push_back(name);
	}
}