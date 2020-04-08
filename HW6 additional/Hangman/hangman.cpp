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
	auto is_letter_used = [](char letter, map<char, int>& used_letters, 
		int& wrong_guess, string& Current_word, auto check_word)
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
		std::for_each(used_letters.begin(), used_letters.end(), [](const auto& used_letters_Pair) {
			cout << used_letters_Pair.first << " ";
			});
		cout << endl;
	};



	// Changes the appropriate blank to its corresponding letter.
	auto blank_to_letter = [](char letter, string& Current_word, string& Current_word_blank)
	{

		string letter_str(1, letter);
		
		auto iter1 = Current_word.begin();
		auto iter2 = Current_word.end();

		auto result = iter1;
		while (result != iter2)
		{
			auto result = std::find_first_of(iter1, iter2, letter_str.begin(), letter_str.end());
			if (result != iter2)
			{
				Current_word_blank[(std::distance(Current_word.begin(), result)) * 2] = letter;
				iter1 = next(result, 1);
			}
			else
				break;
		}
	};



	// Checks is the game has been won.
	auto check_if_win = [](const string& Current_word_blank)
	{
		if (Current_word_blank.find('_') < Current_word_blank.size())
			return false;
		else
			return true;
	};


	// Shows the hanged man.
	auto hanged_man = [](const int& wrong_guess)
	{
		switch (wrong_guess) // Picks the appropriate hanged man.
		{
		case 0:
			cout << "     |>----+" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 1:
			cout << "     |>----+" <<endl;
			cout << "    ()     |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 2:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << "   [  ]    |" << endl;
			cout << "   \\__/    |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 3:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]    |" << endl;
			cout << " | \\__/    |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 4:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]+\\  |" << endl;
			cout << " | \\__/ |  |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 5:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]+\\  |" << endl;
			cout << " | \\__/ |  |" << endl;
			cout << "   /       |" << endl;
			cout << "   |       |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 6:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]+\\  |" << endl;
			cout << " | \\__/ |  |" << endl;
			cout << "   /  \\    |" << endl;
			cout << "   |  |    |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 7:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]+\\  |" << endl;
			cout << " | \\__/ |  |" << endl;
			cout << " ^ /  \\    |" << endl;
			cout << "   |  |    |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 8:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]+\\  |" << endl;
			cout << " | \\__/ |  |" << endl;
			cout << " ^ /  \\ ^  |" << endl;
			cout << "   |  |    |" << endl;
			cout << "           |" << endl;
			cout << " ==========|" << endl;
			break;
		case 9:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]+\\  |" << endl;
			cout << " | \\__/ |  |" << endl;
			cout << " ^ /  \\ ^  |" << endl;
			cout << "   |  |    |" << endl;
			cout << "   ^       |" << endl;
			cout << " ==========|" << endl;
			break;
		case 10:
			cout << "     |>----+" << endl;
			cout << "    ()     |" << endl;
			cout << " /+[  ]+\\  |" << endl;
			cout << " | \\__/ |  |" << endl;
			cout << " ^ /  \\ ^  |" << endl;
			cout << "   |  |    |" << endl;
			cout << "   ^  ^    |" << endl;
			cout << " ==========|" << endl;
			break;
		}
	};
	

	cout << Current_word_blank << endl;
	cout << endl;
	while (wrong_guess < 10)
	{
		
		cout << "Enter a letter: ";
		cin >> letter;

		system("cls"); // refreshes the console screen.

		is_letter_used(letter, used_letters, wrong_guess, Current_word, check_word);
		blank_to_letter(letter, Current_word, Current_word_blank);
		print_used_letters(used_letters);
		hanged_man(wrong_guess);
		cout << Current_word_blank << endl;
		cout << endl;
		if (check_if_win(Current_word_blank))
		{
			cout << "Yay! You win!" << endl;
			break;
		}
		if (wrong_guess > 9)
			cout << "GAME OVER";
	}

	

	// Stops the console from closing.
	cout << endl;
	int q;
	cin >> q;
}



