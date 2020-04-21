/*Lab 33.cpp
Nathan Damon
CS 201
4/21/2020
This program will define a class with member functions 
	and data members and will create objects of the class
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

class Lab33
{
public:
	void prints_something();
	void setter(int input);
	int getter();

private:
	string something = "What were you expecting?";
	int value;
};

void tostring(Lab33 object1, Lab33 object2);


int main()
{
	Lab33 labclass1;
	Lab33 labclass2;
	cout << "Function to print something: ";
	labclass1.prints_something();
	cout << endl;
	int a = 0;
	int b = 0;

	cout << "Enter value for labclass1: ";
	cin >> a;
	cout << "Enter value for labclass2: ";
	cin >> b;

	labclass1.setter(a);
	labclass2.setter(b);

	cout << endl;

	tostring(labclass1, labclass2);

	Lab33 labclass3 = labclass2;
	cout << "labclass3 is copied from labclass2: " << endl;
	cout << "labclass3 value: " << labclass3.getter();

	cout << endl;
	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}



void Lab33::prints_something() { cout << something << endl; }

void Lab33::setter(int input){ value = input; }

int Lab33::getter() { return value; }

void tostring(Lab33 object1, Lab33 object2)
{
	cout << "labclass1 value: " << object1.getter() << endl;
	cout << "labclass2 value: " << object2.getter() << endl;
}