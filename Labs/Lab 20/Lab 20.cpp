/*Lab 20.cpp
Nathan Damon
CS 201
3/24/2020
This program will calculate the cosine of an angle that increases by five degrees with each iteration
and displays the results in a well formatted way.
*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdlib>
using std::cout;
using std::endl;
using std::setprecision;
using std::setw;
using std::cos;

const double PI = std::acos(-1);

int main()
{
	for (int i = 0; i <= 180; i += 5)
		cout << setw(3) << i << setw(12) << std::fixed << setprecision(8) << cos(i * (PI / 180.0)) << endl;

	int q;
	std::cin >> q;
}