/*binary.cpp
Nathan Damon
CS 201
2/25/2020
This program will search through a vector for a given value.
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;


int main()
{
	int num;
	cout << "Give a size for a vector (less then 100, final element will be (size - 1)): ";
	cin >> num;
	vector <int> keys(num);
	for (int i = 0; i < keys.size(); i++) 
	{
		keys[i] = i;
	}
	int key;
	int first = 0;
	int last = int(keys.size());
	cout << "Give a value to search for: ";
	cin >> key;


	for (int i = 0; i < keys.size(); i++)
	{
		cout << keys[i] << " ";
	}

	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}