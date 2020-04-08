/*shopping.cpp
Nathan Damon
CS 201
4/08/2020
This program will imitate an online shopping cart.
*/

#include <map>
using std::map;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
#include <ios>
using std::left;
using std::right;

struct Record {
	double unitPrice;
	int units;
};

map<string, Record> Shop_items = {
	{ "Cereal", { 4.97 , 5 } },
	{ "Peanut_butter", { 3.99 , 6 } },
	{ "Bananas", { 0.69 , 9 } },
	{ "Tomatoes", { 0.99 , 4 } },
	{ "Cheese", { 2.49 , 3 } },
	{ "Chips", { 1.99 , 5 } },
	{ "Cake", { 8.99 , 2 } }
};

map<string, Record> User_cart;

int main()
{
	cout <<  setw(15) << left << "Item: " << "Price:" << "  Units left: " << endl;
	for (const auto& p : Shop_items)
	{
		auto k = p.first;
		auto v = p.second;
		cout << setw(15) << left << k << "$" << v.unitPrice << setw(13) << right << v.units;
		cout << endl;;
	}

	// Stops the console from closing.
	cout << endl;
	int q;
	cin >> q;
}

