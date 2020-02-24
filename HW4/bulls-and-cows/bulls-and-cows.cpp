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
	vector <int> Vguess(4);
	int bulls = 0;
	int cows = 0;
	int trys = 0;

	cout << "We are trying to pick a four digit number. This could take a moment or several." << endl;
	cout << "Loading Game"; // Added this just for fun.
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
		cout << ".";
	}
	cout << endl;
	
	cout << "Enter your guess for what the four-digit number is: ";
	while (bulls < 4) // Runs until the user has gotten all the bulls.
	{
		if (trys > 0) // This message is displayed after the first guess.
			cout << "Enter another guess for what you think the four-digit number is: ";

		done = 1;
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

		if (guess < 0) // Outputs the answer if the user enters a negative number.
			for (int i = 0; i < Vrandom.size(); i++) 
				cout << Vrandom[i];

		int digit1;
		int digit2;
		int digit3;
		int digit4;

		digit1 = (guess / 1000); // These expressions below are used to grab the digits of the user's geuss.
		Vguess[0] = (digit1);
		digit2 = ((guess - digit1 * 1000) / 100);
		Vguess[1] = (digit2);
		digit3 = ((guess - digit1 * 1000 - digit2 * 100) / 10);
		Vguess[2] = (digit3);
		digit4 = (guess - digit1 * 1000 - digit2 * 100 - digit3 * 10);
		Vguess[3] = (digit4);

		bulls = 0; // Resets the number of bulls and cows after each guess.
		cows = 0; 

		for (int i = 0; i < Vrandom.size(); i++)
		{
			if (Vguess[i] == Vrandom[i]) // Determines if bull.
				bulls++;
			else
				for (int j = 0; j < Vrandom.size(); j++)
					if (Vguess[j] == Vrandom[i]) // Determines if cow.
						cows++;
		}
		cout << endl;

		cout << bulls << " bull and " << cows << " cow." << endl;
		trys++;
		cout << endl;
	}

	cout << "Congratulations! You did it!" << endl;

	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}