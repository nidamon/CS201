/*Lab 28.cpp
Nathan Damon
CS 201
4/14/2020
This program will send output to a text file.
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <iomanip>
using std::setw;

int main()
{





	if (true)
	{
		ofstream fout("test.txt"); //, ios::app);
		if (!fout)
		{
			cout << "Error opening file" << endl;
			return 0;
		}
		else
		{
			for (int i = 0; i < 10; i++)
				fout << "Hello World!" << endl;

			fout << endl;

			for (int i = 0; i < 10; i++)
			{
				for (int j = 1; j < 11; j++)
				{
					fout << setw(2) << std::right << (i * 10 + j) << " ";
				}
				fout << endl;
			}



			if (!fout)
			{
				cout << "Error writing to file" << endl;
				return 0;
			}
			cout << "Text inputted" << endl;
		}
	}

	if (true)
	{
		ifstream fin("test.txt");
		if (!fin)
		{
			cout << "Error opening file" << endl;
			return 0;
		}
		else
		{
			while (true)
			{
				string line;
				getline(fin, line);
				if (!fin)
				{
					if (fin.eof())
					{
						cout << "Finished reading file" << endl;
					}
					else
					{
						cout << "Error during transmit." << endl;
						
					}
					cout << line << endl;
					break;
				}

			}
		}
	}


	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;
}








