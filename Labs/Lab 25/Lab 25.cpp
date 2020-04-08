/*Lab 25.cpp
Nathan Damon
CS 201
4/07/2020
This program will use iterators returned by a C++ Standard Template Library algorithm.
*/

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <algorithm>

vector <int> data1 { 5, 1, 8, 7, 2, 4, 2, 9, 6, 5, 4, 1, 0, 3, 7, 9 };
vector <int> data2 { 5, 0, 8, 1, 2, 3, 2, 9, 6, 5, 4, 2, 0, 3, 7, 9 };
vector <int> data3 { 5, 1, 8, 7, 2, 4, 2, 9, 6, 5, 4, 1, 0, 3, 7, 9 };

int main()
{
	auto iter1 = data1.begin();
	auto iter2 = data3.begin();
	auto data_mismatch = std::mismatch(iter1, data1.end(), iter2);
	auto number_of = data_mismatch.first;
	if (data_mismatch.first == data1.end())
		cout << "They are the same." << endl;
	else
		cout << "These are all of the mismatches." << endl;
		while (true)
		{
			data_mismatch = std::mismatch(iter1, data1.end(), iter2);
			if (data_mismatch.first == data1.end())
				break;
			cout << data_mismatch.first[0] << " " << data_mismatch.second[0] << endl;
			iter1 = next(data_mismatch.first, 1);
			iter2 = next(data_mismatch.second, 1);
		}
	// Stops the console from closing.
	cout << endl;
	int q;
	cin >> q;
}





