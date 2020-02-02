/*Nathan Damon
CS 201
2/2/2020
This program will calculate the dot product and cross product of a 3-component vector.
*/

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main() {
	float Ax, Ay, Az, Bx, By, Bz;

	cout << "Enter the x, y, and z for vector A:" << endl; //asks for the components for vector A
	cout << "x = ";
	cin >> Ax;
	cout << "y = ";
	cin >> Ay;
	cout << "z = ";
	cin >> Az;

	cout << "Enter the x, y, and z for vector B:" << endl; //asks for the components for vector B
	cout << "x = ";
	cin >> Bx;
	cout << "y = ";
	cin >> By;
	cout << "z = ";
	cin >> Bz;

	cout << "A dot B = " << std::setprecision(5) << Ax * Bx + Ay * By + Az * Bz << endl;
	cout << "A cross B = (";
	cout << std::setprecision(5) << Ay * Bz - Az * By << ",";
	cout << std::setprecision(5) << Az * Bx - Ax * Bz << ",";
	cout << std::setprecision(5) << Ax * By - Ay * Bx << ")" << endl;
	//system("pause"); //Needed to use this again
	return 0;
}