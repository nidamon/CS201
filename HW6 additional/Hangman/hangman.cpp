/*hangman.cpp
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
#include <random>
using std::random_device;
#include <algorithm>
using std::find;
#include <Windows.h>

// Words for word search.
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
	std::uniform_int_distribution<int> uniform_dist(0, number_of_words-1);

	// Picks a random word.
	string Current_word = Words[uniform_dist(e1)];

	// Blanks for the word.
	string Current_word_blank = "";
	// Map for the used letters.
	map<char, int> used_letters;
	for (size_t i = 0; i < Current_word.size(); i++)
		Current_word_blank += "_ ";

	cout << Current_word << endl;


	// Counts the number of incorrect guesses.
	int wrong_guess = 0;
	char letter;

	// Checks if the letter entered is in the word.
	auto check_word = [](char letter, string& Current_word)
	{
		if (Current_word.find(letter) < Current_word.size())
			return true;
		else
			return false;
	};


	// Determines the letters used.
	auto is_letter_used = [](char letter, map<char, int>& used_letters, int& wrong_guess, string& Current_word, auto check_word)
	{
		int item_count = used_letters.count(letter);
		if (item_count != 0)
			cout << "That letter has already been used." << endl;
		else
		{
			if (check_word(letter, Current_word))
			{
				cout << "That \"" << letter << "\" is in the word!" << endl;
			}
			else
			{
				cout << "There are no " << letter << "'s in the word." << endl;
				wrong_guess++;
			}
			used_letters[letter] = 1;
		}
	};

	// Prints the used letters.
	auto print_used_letters = [](const map<char, int>& used_letters)
	{
		cout << "Letters used: ";
		for (const auto& p : used_letters)
		{
			auto k = p.first;
			auto v = p.second;
			cout << k << " ";
		}
		cout << endl;
	};



	// Changes the appropriate blank to its corresponding letter.
	auto blank_to_letter = [](char letter, string& Current_word, string& Current_word_blank)
	{
		for (size_t i = 0; i < Current_word.size(); i++)
		{
			if (Current_word[i] == letter)
				Current_word_blank[i*2] = letter;
		}
	};


	
	while (wrong_guess < 10)
	{
		cout << Current_word_blank << endl;
		cout << endl;
		cout << "Enter a letter: ";
		cin >> letter;

		system("cls"); // refreshes the console screen.

		is_letter_used(letter, used_letters, wrong_guess, Current_word, check_word);
		blank_to_letter(letter, Current_word, Current_word_blank);
		cout << "Incorrect guesses left: " << (10 - wrong_guess) << endl;
		print_used_letters(used_letters);
	}

	

	// Stops the console from closing.
	cout << endl;
	int q;
	cout << "GAME OVER";
	cin >> q;
}



