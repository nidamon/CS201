/*bulls-and-cows.cpp
Nathan Damon
CS 201
2/23/2020
This program will create a vector of four integers and ask the user to guess them.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	vector <int> Vrandom(4, -1);
	vector<int> one_through_nine { 0,1,2,3,4,5,6,7,8,9 }; // Creates a vector with 0-9

	cout << "We are trying to pick a four digit number. This could take a moment.";

	for (int i = 0; i < 4; i++)
	{
		int n = -1;
		int random_num;
		while (n == -1) // if a value has been picked, it will be set to zero and will not be picked again.
		{
			srand(time(0));
			random_num = (rand() % 10);
			n = Vrandom[i] = one_through_nine[random_num]; // The ith element of Vrandom is set to equal the random value.
			one_through_nine[random_num] = -1; // The random value is set to -1 so as to not be chosen again.
		}

	}
	cout << endl;
	for (int i = 0; i < Vrandom.size(); i++) // Outputs the answer for testing.
		cout << Vrandom[i];
	cout << endl;

	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}