/*tokenizertest.cpp
Nathan Damon
CS 201
2/22/2020
This program will test the tokenizer program.
*/

#include "tokenizer.h"

int main()
{
	int finish = 1;
	cout << "Please type in some text. When you are done, type \"End\", \"end\" or \"END\":" << endl;
	string str;
	vector<string> tokens;
	while (finish != 0) // Continues to allow the user to enter text until they enter one of the three ends.
	{
		ReadLine(str);
		StringToTokenWS(str, tokens);

		if (str == "end")
			finish = 0;
		if (str == "End")
			finish = 0;
		if (str == "END")
			finish = 0;
	}
	tokens.pop_back();

	AnalyzeTokens(tokens);

	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}