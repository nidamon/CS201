/*rice
Nathan Damon
CS 201
2/9/2020
This program will add up the grains of rice that double with each square of the chess board till they reach or pass the number inputted.
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int rice_on_square = 1;
int total_rice = 0;
int num_rice;

int main()
{
	cout << "Enter a number of rice and see how many squares it takes to get that much: ";
	cin >> num_rice; //Allows the user to determine the number of rice to count up to.

	for (int square = 0; square < 64; square++)
	{
		rice_on_square = pow(2, square); //Doubles the rice for the next square
		total_rice = total_rice + rice_on_square; //Adds up the total rice
		if (total_rice > num_rice)
		{
			cout << "It takes " << square << " squares to reach " << num_rice << " grains of rice." << endl;
			break;
		}
		
	}
	cout << endl;
	cout << "The largest number of squares that can be used to accurrately calculate the number of grains:" << endl;
	cout << "(using an int) is 31 squares." << endl;
	cout << "(using a double) is 64 squares." << endl;
	cout << endl;

	int q;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}
