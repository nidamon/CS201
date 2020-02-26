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
using std::string;

int binary_search(int key, vector <int> keys);

int main()
{
	string answer = "yes";
	while (answer == "yes")
	{
		vector <int> keys;
		int num;
		cout << "Pick a test vector 1, 2, 3, 4, 5): ";
		cin >> num;
		if (num == 1)
			keys = { 1, 2, 5, 7, 8, 10, 14, 15, 16, 18, 19, 20, 24 }; // 13 ints
		else if (num == 2)
			keys = { 4, 5, 9, 15, 18, 19, 25, 35, 42, 43, 48, 71 }; // 12 ints
		else if (num == 3)
			keys = { 1, 2, 3, 4, 8, 14, 18, 24, 25, 26, 27, 29, 31 }; // 13 ints
		else if (num == 4)
			keys = { 1, 2, 8, 9, 10, 11, 13, 14, 18, 24, 25, 26, 27, 29, 32, 37, 52, 61, 65, 67, 73, 74 }; // 22 ints
		else if (num == 5)
			keys = { 1, 2, 3, 4, 8, 14, 18, 24, 25, 26, 27, 29, 48, 71, 72, 81, 92, 93, 94, 96, 99 }; // 21 ints

		for (int i = 0; i < keys.size(); i++)
		{
			cout << keys[i] << " ";
		}

		cout << endl;
		
		int key;
		cout << "Give a value to search for: ";
		cin >> key;

		cout << endl;

		int was_there;
		was_there = binary_search(key, keys);
		if (was_there > -1)
			cout << "It is item number " << was_there << ", with a value of " << keys[was_there] << "." << endl;
		else if (was_there < 0)
			cout << "Item was not found." << endl;

		cout << endl;

		cout << "Would you like to search another test vector? yes/no: ";
		cin >> answer;
		if (answer == "yes")
			cout << "Type away!" << endl;
		else if (answer == "no")
			break;
		else
			cout << "You need to type: yes or no: ";

		cout << endl;
	}

	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}


int binary_search(int key, vector <int> keys) // Searches through a given vector for a value.
{
	int first = 0;
	int last = keys.size();
	int middle, size;

	while (true)
	{
		size = last - first;
		middle = first + size / 2;
		cout << "Key between " << first << " and " << last << ". Checking " << middle << " for comparison." << endl;

		if (size == 0)
			return -2;
		if (size == 1)
		{
			if (keys[middle] == key)
				return middle; // Give the locationin the vector where the item was found.
			return -1;
		}

		if (keys[middle] == key) {
			return middle;
		}
		if (keys[middle] > key)
			last = middle;
		else
			first = middle;
	}
}