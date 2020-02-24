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
#include <sstream>

using std::istringstream;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	vector <int> Vrandom(4, -1); // Contains the number to guess.
	vector<int> one_through_nine { 0,1,2,3,4,5,6,7,8,9 }; // Creates a vector with 0-9
	int guess; // Holds the user's 4-digit guess.
	std::string str; // The string guess of the user.
	int done = 1; // For the while loop that continues to prompt for an integer input.
	vector <int> Vguess;
	int bulls = 0;
	int cows = 0;

	cout << "We are trying to pick a four digit number. This could take a moment." << endl;

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

	
	cout << "Enter your guess for what the four-digit number is: ";
	
	while (done != 0)
	{
		std::getline(cin, str);
		istringstream instream(str);
		instream >> guess;
		if (!instream)
			cout << "You need to enter an integer." << endl;
		else
			done = 0;
	}

	int digit1;
	int digit2; 
	int digit3;
	int digit4;

	digit1 = (guess / 1000); // These expressions below are used to grab the digits of the user's geuss.
	Vguess.push_back(digit1);
	digit2 = ((guess - digit1 * 1000) / 100);
	Vguess.push_back(digit2);
	digit3 = ((guess - digit1 * 1000 - digit2 * 100) / 10);
	Vguess.push_back(digit3);
	digit4 = (guess - digit1 * 1000 - digit2 * 100 - digit3 * 10);
	Vguess.push_back(digit4);

	for (int i = 0; i < Vguess.size(); i++) // Outputs the answer for testing.
		cout << Vguess[i] << endl;

	for (int i = 0; i < Vrandom.size(); i++)
	{
		if (Vguess[i] == Vrandom[i])
			bulls++;
		else
			for (int j = 0; j < Vrandom.size(); j++)
				if (Vguess[j] == Vrandom[i])
					cows++;
	}
	cout << endl;

	cout << bulls << " bull and " << cows << " cow." << endl;

	cout << endl;

	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}