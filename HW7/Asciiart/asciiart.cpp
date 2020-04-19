/*asciiart.cpp
Nathan Damon
CS 201
4/16/2020
This program will read a PPM image and then output an ASCII Art version of that image.
*/

#include "Image3.h"

struct RGB {
	int R = 0;
	int G = 0;
	int B = 0;
};
vector <RGB> Total_data;

int main()
{
	int max = 0;
	int set_size = 0;
	int width = 0;
	int height = 0;
	int RGB_color = 0;
	int R = 0;
	int G = 0;
	int B = 0;
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
					//Total_data.resize(width * height);
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
					//cout << Total_data.size() << endl;
				}
			}
			else if ((repeat % 3) == 2) ///////////////////////////////////////////////////////////
			{
				string RGBline = line;
				getline(fin, line);
				RGBline += (" " + line);
				getline(fin, line);
				RGBline += (" " + line);
				cout << RGBline;
				/*istringstream instream(line);
				instream >> RGB_color;
				if ((repeat % 3) == 0)
					R = RGB_color;
				if ((repeat % 3) == 1)
					G = RGB_color;
				if ((repeat % 3) == 2)
					B = RGB_color;*/

				printASCII(std::ostream & operator<<(std::ostream & ostr, const Color3 & color));
				repeat++;
			}		
		}
	}
	//cout << "Width: " << width << endl;
	//cout << "Height: " << height << endl;
	//cout << "Set size: " << set_size << endl;
	//cout << "Max RGB value: " << max << endl;
	//int Y = 0;
	//unsigned darkness = 0;
	//const char values[] =  "#80kbha;oc*\",-. "; //"MNmdhysso+/:-.`.";
	//cout << endl;


	//for (int i = 0; i < height; i++)
	//{
	//	for (int j = 0; j < width; j++)
	//	{
	//		Y = 0.2126 * Total_data[((i* width) + j)].R + 0.7152 * Total_data[(i * width + j)].G + 0.0722 * Total_data[(i * width + j)].B;
	//		darkness = 16 -(Y / 16);
	//		cout << values[darkness] << " "; // Needed a space to make it not seem squished.
	//	}
	//	cout << endl;
	//}





	// Stops the console from closing.
	cout << "Program end" << endl;
	int q;
	cin >> q;

	return 0;
}





