/*boxprint.cpp
Nathan Damon
CS 201
2/15/2020
This program will print a box with words in it.
*/

#include <iostream>
#include "boxer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str;
	int n;
	int k=0;

	cout << "This program will print a box with a word or phrase in it." << endl;
	while (k == 0){
		cout << "Please specify a word or phrase that you want in the box: ";
		cin >> str;
		cout << "Please specify how thick you want the border of the box: ";
		cin >> n;
		while (n < 1) {
			cout << "The border's thickness cannot be less then 1. Enter a number greater than 0: ";
			cin >> n;
		}
		boxer(str,n);

		cout << endl;
		cout << "If you want to make and print another custom box type 0, If you do not, type a different number: ";
		cin >> k;
	}
	return 0;
}
