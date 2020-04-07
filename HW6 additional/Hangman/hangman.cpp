/*random-map.cpp
Nathan Damon
CS 201
4/07/2020
This program will allow the user to play hangman.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <iomanip>
#include <random>
using std::random_device;
#include <algorithm>
using std::find;

// Words for word search
map<int, string> Words = {
	{ 0, "happy"},
	{ 1, "supercalifragilisticexpialidocious"},
	{ 2, "algorithms"},
	{ 3, "ambidextrous"},
	{ 4, "philanthropist"},
	{ 5, "entrepreneur"},
	{ 6, "segmentation"},
	{ 7, "excalibur"},
	{ 8, "germaniun"},
	{ 9, "cantaloupe"},
	{ 10, "zoologist"},
	{ 11, "exoskeleton"},
	{ 12, "dragonfly"},
	{ 13, "monologue"},
	{ 14, "chimichanga"}
};

int main()
{
	size_t number_of_words = Words.size();

	random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, number_of_words);

	string str = Words[uniform_dist(e1)];


	string letter;
	int wrong_guess = 0;
	bool check = [](string letter)
	{
		if (str.find(letter) < str.size())
			return true;
		else
			return false;
	};

	while (wrong_guess < 10)
	{
		cout << "Enter a letter: ";
		cin >> letter;


	}

	

	// Stops the console from closing
	int q;
	cin >> q;
}



