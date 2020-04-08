/*Lab 24.cpp
Nathan Damon
CS 201
4/07/2020
This program will use the C++ Standard Template Library algorithms to modify a dataset.
*/

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>

vector <int> data{ 5, 1, 8, 7, 2, 4, 2, 9, 6, 5, 4, 1, 0, 3, 7, 9 };

int main()
{
	// Prints data
	auto print_data = [](vector <int>& data)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	};

	cout << "Data:                     ";
	print_data(data);

	cout << "Sorted data:              ";
	auto iter1 = data.begin();
	auto iter2 = data.end();
	sort(iter1, iter2);
	print_data(data);

	cout << "Reversed data after sort: ";
	reverse(iter1, iter2);
	print_data(data);

	cout << "Filled subset in data:    ";
	fill(iter1, iter2, 0);
	print_data(data);


	// Stops the console from closing.
	cout << endl;
	int q;
	cin >> q;
}





