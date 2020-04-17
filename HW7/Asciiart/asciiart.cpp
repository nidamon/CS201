/*asciiart.cpp
Nathan Damon
CS 201
4/16/2020
This program will read a PPM image and then output an ASCII Art version of that image.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iomanip>
using std::setw;
using std::right;
#include <sstream>
using std::istringstream;
#include <fstream>
//using std::ofstream;
using std::ifstream;
//using std::ios;
#include <Windows.h>


int main()
{
	struct RGB {
		int R = 0;
		int G = 0;
		int B = 0;
	};
	vector <RGB> Total_data;
	int max = 0;
	int set_size = 0;
	int width = 0;
	int height = 0;
	int RGB_color = 0;
	ifstream fin("Parrot.txt");
	if (!fin)
	{
		cout << "Error opening file" << endl;
		Sleep(1000);
		return 0;
	}
	else
	{
		int repeat = 0;
		while (true)
		{
			string line;
			getline(fin, line);
			if (!fin)
			{
				if (fin.eof())
				{
					cout << "Finished reading file" << endl;
					Sleep(1000);
					break;
				}
				else
				{
					cout << "Error during transmit." << endl;
					Sleep(1000);
					break;
				}
			}
			if (line.substr(0, 1) == "P")
			{
				cout << line << endl;
				istringstream instream(line.substr(1, 1));
				instream >> set_size;
			}
			else if (width == 0)
			{
				if (line.substr(0, 1) != "#")
				{
					istringstream instream(line);
					instream >> width >> height;
					Total_data.resize(width * height);
					repeat = -1;
					cout << Total_data.size() << endl;
				}
			}
			else if (repeat == -1)
			{
				if (line.substr(0, 1) != "#")
				{
					istringstream instream(line);
					instream >> max;
					repeat = 0;
					cout << line << endl;
					cout << Total_data.size() << endl;
				}
			}
			else if (repeat > -1)
			{
				istringstream instream(line);
				instream >> RGB_color;
				if ((repeat % 3) == 0)
					Total_data[(repeat / 3)].R = RGB_color;
				if ((repeat % 3) == 1)
					Total_data[(repeat / 3)].G = RGB_color;
				if ((repeat % 3) == 2)
					Total_data[(repeat / 3)].B = RGB_color;
				repeat++;
			}		
		}
	}
	cout << Total_data.size() << endl;
	for (size_t i = 0; i < (Total_data.size()); i++)
	{
		cout << Total_data[i].R << " " << Total_data[i].G << " " << Total_data[i].B << endl;
	}

	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Set size: " << set_size << endl;
	cout << "Max RGB value: " << max << endl;
	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;

	return 0;
}





