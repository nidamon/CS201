/*floating point main.cpp
Nathan Damon
CS 201
3/23/2020
This program will use floating point.cpp to do floating point computation.
*/

#include "floating point.h"

// using sin, cos


int main() {
	// TODO Turn on "error on warnings" so this doesn't*****************
	// compile.  Make it compile by using std::size_t
	// You can comment this for loop out after that.
	/*std::vector<int> v{ 1, 2, 3, 4, 5 };
	for (size_t i = 2; i < v.size(); ++i) {
		++v[i];
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl << std::endl;*/
	// *****************************************************************

	// TODO Declare and initialize a vector of radians by calling*******
	//        degreesToRadians(360).
	std::vector<double> radians = degreesToRadians(360);
	//      Print degree,cos(radian),sin(radian) as a comma separated
	//        values (CSV) list.
	cout << "degree,cos,sin" << endl;
	for (size_t i = 0; i < radians.size(); i++)
	{
		cout << i << ", " << std::cos(radians[i]) << ", " << std::sin(radians[i]) << endl;
	}
	// *****************************************************************

	int q;
	std::cin >> q;

	return 0;
}
