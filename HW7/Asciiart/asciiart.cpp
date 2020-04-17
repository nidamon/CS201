/*asciiart.cpp
Nathan Damon
CS 201
4/16/2020
This program will read a PPM image and then output an ASCII Art version of that image.
*/

int main()
{
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
}





