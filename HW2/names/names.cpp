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
using std::cout;
using std::endl;
using std::string;
using std::vector;

void InputNames(vector<string>& names);
bool DoesNameExist(const string& anmeToFind, const vector<string>& names);
void PrintNames(const vector<string>& names);

int main(int argc, char** argv)
{
	vector<string> names;
	InputNames(names);
	PrintNames(names);

	int q; 
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}

void InputNames(vector<string>& names) //Adds the inputted names to the vector "names"
{
	for (int i = 0; i < 10; i++) 
	{
		string name;
		cout << "Please enter a name: ";
		std::getline(cin, name);
		names.push_back(name);
	}
	cout << endl;
}

void PrintNames(const vector<string>& names) //Prints the contents of the vector "names"
{
	cout << "Below is the list of names." << endl;
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << " " << endl;
	}
	cout << endl;
}