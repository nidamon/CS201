/*kelvin.cpp
Nathan Damon
CS 201
2/16/2020
This program will take in a tempurature in Celsius and will convert it 
	to Kelvin and specify in comments what was changed to fix it.
*/

// Converts Celsius to Kelvin

#include <iostream> // Did not have iostream or the using std::... below.
using std::cin;
using std::cout;
using std::endl;

double ctok(double c)
{
	while (c < -273.15)
	{
		cout << "Enter a value greater than -273.15: ";
		cin >> c;
	}
		
	double k = c + 273.15; // If k is an int then the 0.15 that is added to c will be lost.
		return k; // We are returning k not a type.
}

int main()
{
	double c = 0;
	cout << "Enter a tempurature in Celsius and it shall be converted to Kelvin: "; // The user should recieve a prompt about what to input.
	cin >> c; // We are asking for c not some new undeclared variable d.

	if (c < -273.15) { // We need to check for when the inputted value of c is less than -273.15 as the tempurature cannot be below that.
		cout << "A tempurature less than -273.15 degrees Celsius cannot be evaluated." << endl;
	}
	double k = ctok(c); // c should not be in quotes.
	cout << k - 273.15 << " degrees Celsius is equal to "; // This will make things easier to read/understand.
	cout << k << " degrees Kelvin" << endl; /* /n should not be in single quotes and it's better to use endl here instead of /n.
						Cout should be lower case cout. The units of k should be outputted with k.*/
}