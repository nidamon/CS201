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
#include <Windows.h>

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

map<string, Record> User_cart = {};
map<int, string> item_id = {};

int main()
{
	int id = 1;
	while (id != 0)
	{
		int i = 1;
		cout << "Id: " << setw(15) << left << "Item: " << "Price:" << "  Units left: " << endl;
		for (const auto& p : Shop_items)
		{
			auto k = p.first;
			auto g = item_id[i];
			item_id[i] = k;
			auto v = p.second;
			cout << " " << setw(3) << left << i << setw(15) << left << k << "$" << v.unitPrice << setw(4) << right << v.units << endl;
			i++;
		}

		cout << endl;
		cout << endl;
		cout << "Shoping Cart:" << endl;
		if (User_cart.empty())
			cout << "Your cart is empty." << endl;
		else
		{
			cout << "Id: " << setw(15) << left << "Item: " << "Price:" << "  Units left: " << endl;
			for (const auto& p : User_cart)
			{
				auto k = p.first;
				auto v = p.second;
				cout << " " << setw(3) << left << i << setw(15) << left << k << "$" << v.unitPrice << setw(4) << right << v.units << endl;
			}
		}

		cout << endl;
		cout << "What would you like to buy?" << endl;

		int id;
		int item_count = 0;
		while (item_count == 0)
		{
			cout << "Enter an id or 0 if you are done: ";
			cin >> id;

			if (id == 0)
				break;

			int item_count = item_id.count(id);
			if (item_count != 0)
				cout << "There is no item with that id." << endl;
		}
		if (id == 0)
			break;


		system("cls"); // refreshes the console screen.
	}

	// Stops the console from closing.
	cout << "Done" << endl;
	int q;
	cin >> q;
}

