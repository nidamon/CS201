/**
 * @file     Lab 26.cpp
 * @author   Nathan Damon
 * @date     4/14/2020
 * John Quan
 *
 * Practice using lambda functions
 */

#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <algorithm>
#include <iterator>
#include <utility>
using std::pair;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <functional>

#include "lambdas.h"

int main() {

	// TODO: REQUIRED
	//       Create a vector<pair<size_t, string>> to enumerate
	//       each string in the WIKIPEDIA_CPP string vector.
	vector<pair<size_t, string>> WIKIPEDIA_CPP_size(WIKIPEDIA_CPP.size());
	for (size_t i = 0; i < WIKIPEDIA_CPP.size(); i++)
	{
		WIKIPEDIA_CPP_size[i].second = WIKIPEDIA_CPP[i];
		WIKIPEDIA_CPP_size[i].first = WIKIPEDIA_CPP_size[i].second.size();
	}
	auto iter1 = WIKIPEDIA_CPP_size.begin();
	auto iter2 = WIKIPEDIA_CPP_size.end();


	// TODO: REQUIRED
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the first member in descending order.
	sort(iter1, iter2, [](auto a, auto b) {return a > b; });


	// TODO: REQUIRED
	//       Use printVectorPairs() to print the vector

	cout << printVectorPairs(iter1, iter2);



	// TODO: ADDITIONAL 1
	//       Use std::sort with a comparison lambda function that sorts
	//       the vector pairs with the second member in ascending order.



	// TODO: ADDITIONAL 1
	//       Use printVectorPairs() to print the vector



	// TODO: ADDITIONAL 2
	//       Use std::find_if with a comparison lambda function that prints
	//       the vector pairs where the pair's second.length() > 15.
	//       Print the vector as described in the lab.



	// Stops the console from closing.
	cout << endl;
	int q;
	cin >> q;
}










