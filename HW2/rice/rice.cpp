/*rice
Nathan Damon
CS 201
2/9/2020
This program will add up the grains of rice that double with each square of the chess board.
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

double rice_on_square = 1;
double total_rice = 0;
int num_rice;

int main()
{
	cout << "Enter a number of rice and see how many squares it takes to get that much: ";
	cin >> num_rice;

	for (int square = 0; square < 64; square++)
	{
		rice_on_square = pow(2, square);
		total_rice = total_rice + rice_on_square;
			cout << rice_on_square << "       total " << total_rice << " " << square <<  endl;
		/*if (total_rice > num_rice)
		{
			cout << "It takes " << square << " squares to reach " << num_rice << " grains of rice." << endl;
			break;
		}
		*/
	}
	cout << endl;
	cout << "The largest number of squares that can be used to accurrately calculate the number of grains (using an int) is 31." << endl;
	cout << "The largest number of squares that can be used to accurrately calculate the number of grains (using an int) is 64." << endl;
	cout << endl;

	int q;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}
