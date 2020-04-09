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
#include <numeric>
#include <vector>
using std::vector;

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
			cout << " " << setw(3) << left << i 
						<< setw(15) << left << k << "$" 
						<< setw(4) << left << v.unitPrice
						<< setw(4) << right << v.units << endl;
			i++;
		}

		cout << endl;
		cout << endl;
		cout << "Shoping Cart:" << endl;
		if (User_cart.empty())
			cout << "Your cart is empty." << endl;
		else
		{
			i = 1;
			cout << "Id: " << setw(15) << left << "Item: " << "Price:" << "  Units left: " << endl;
			vector <double> item_times_price { 0 };
			for (const auto& p : item_id)
			{
				auto id_ = p.first;
				auto item_name_ = p.second;
				auto item_price_ = Shop_items[p.second].unitPrice;
				auto item_count_ = User_cart[p.second].units;
				if (item_count_ > 0)
					cout << " " << setw(3) << left << id_ 
								<< setw(15) << left << item_name_ << "$" 
								<< setw(4) << left << item_price_ 
								<< setw(4) << right << item_count_ << endl;
				item_times_price.push_back(item_price_ * item_count_);
				i++;
			}
			double total_cost = std::accumulate(item_times_price.begin(), item_times_price.end(), 0.0);
			cout << endl;
			cout << "Your total: $" << total_cost << endl;
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
			if (item_count == 0)
				cout << "There is no item with that id." << endl;
			else
				break;
		}
		if (id == 0)
			break;
		else
		{
			cout << endl;
			cout << "How much of the " << item_id[id] << " do you want to add to or remove from your cart?" << endl;
			int max_take = Shop_items[item_id[id]].units;
			int current_item_count = User_cart[item_id[id]].units;
			cout << "Amount (purchase up to " << max_take << " items or remove up to " << current_item_count << " items from your cart):";
			int amount = 0;
			//int total_items = max_take + current_item_count;
			cin >> amount;
			if (amount > 0)
			{
				if (amount > max_take)
					amount = max_take;
				User_cart[item_id[id]].units += amount;
				Shop_items[item_id[id]].units -= amount;
			}
			if (amount < 0)
			{
				if (amount < (0 - current_item_count))
					amount = (0 - current_item_count);
				User_cart[item_id[id]].units += amount;
				Shop_items[item_id[id]].units -= amount;
			}
		}
		


		system("cls"); // refreshes the console screen.
	}

	// Stops the console from closing.
	cout << "Done" << endl;
	int q;
	cin >> q;
}

