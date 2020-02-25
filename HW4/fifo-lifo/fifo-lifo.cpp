/*fifo-lifo.cpp
Nathan Damon
CS 201
2/23/2020
This program will allow the user to put items into a conainer and take them out as well as display them.
*/

#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<string> container;
string item;
string answer;
int finish = 1;
string str;
int not_Fifo_or_Lifo_count;
int Fifo_item_add_count;
int Lifo_item_add_count;
int yes_no = 1;
bool b;

// First-In First-Out
void FifoPush(vector<string>& container, const string& item);
void FifoPop(vector<string>& container, string& item);

// Last-In First-Out
void LifoPush(vector<string>& container, const string& item);
void LifoPop(vector<string>& container, string& item);

// Shared functionality
bool IsContainerEmpty(const vector<string>& container);
void PrintContainer(const vector<string>& container);

bool TestFifo();
bool TestLifo();



int main()
{
	cout << "Would you like to fill a container? Type \"Yes\" if you do. ";
	cin >> answer;
	if (answer == "yes")
		finish = 0;
	else if (answer == "Yes")
		finish = 0;
	else if (answer == "YES")
		finish = 0;
	else
		cout << "Goodbye."; // If the user doesn't want to enter "yes".

	cout << endl;

	if (finish == 0)
	{
		cout << "How would you like to fill your container?" << endl;
		cout << "With Fifo (First-In First-Out) or with Lifo (Last-In First-Out)?" << endl;
		cout << "Enter \"Fifo\" for Fifo or \"Lifo\" for Lifo: ";
		while (true)
		{
			if (not_Fifo_or_Lifo_count > 0) // Notifies the user of what they need to enter.
				cout << "Please specifically enter \"Fifo\" or \"Lifo\"." << endl;
			cin >> str;
			if (str == "Fifo")
				break;
			if (str == "Lifo")
				break;
			not_Fifo_or_Lifo_count++;
		}

		cout << endl;


		// Fifo section


		if (str == "Fifo") // If user picks Fifo in previous selection.
		{
			cout << "You have chosen Fifo. Enter what you would like to place in your container: ";
			yes_no = 1;
			while (yes_no != 0)
			{
				if (Fifo_item_add_count > 0)
					cout << "Enter another item to place in your container: ";

				cin >> item;
				FifoPush(container, item);

				cout << "Would you like to add another item? Enter \"1\" for yes or \"0\" for no: ";
				cin >> yes_no;

				Fifo_item_add_count++;
			}

			yes_no = 1;
			while (yes_no != 0)
			{
				cout << endl;
				cout << "Would you like to \"Pop\" the last item in your container with Fifo pop? Enter \"1\" for yes or \"0\" for no: ";
				cin >> yes_no;
				if (yes_no == 1)
				{
					if (container.size() == 0)
					{
						cout << "Your container is empty.";
						break;
					}
					cout << "Your last item was: ";
					FifoPop(container, item);
				}
				
			}
		}


		// Lifo section


		else if (str == "Lifo") // If user picks Lifo in previous selection.
		{
			cout << "You have chosen Lifo. Enter what you would like to place in your container: ";
			yes_no = 1;
			while (yes_no != 0)
			{
				if (Lifo_item_add_count > 0)
					cout << "Enter another item to place in your container: ";

				cin >> item;
				LifoPush(container, item);

				cout << "Would you like to add another item? Enter \"1\" for yes or \"0\" for no: ";
				cin >> yes_no;

				Lifo_item_add_count++;
			}

			yes_no = 1;
			while (yes_no != 0)
			{
				cout << endl;
				cout << "Would you like to \"Pop\" the last item in your container with Lifo pop? Enter \"1\" for yes or \"0\" for no: ";
				cin >> yes_no;
				if (yes_no == 1)
				{
					if (container.size() == 0)
					{
						cout << "Your container is empty.";
						break;
					}
					cout << "Your last item was: ";
					LifoPop(container, item);
				}
			}


		}

		finish = 1;
		cout << "Do want to know what is in your container? Type: yes or no: ";
		while (finish != 0)
		{
			cin >> answer;
			if (answer == "yes")
				finish = 0;
			else if (answer == "Yes")
				finish = 0;
			else if (answer == "YES")
				finish = 0;
			else if (answer == "no")
				finish = 1;
			else if (answer == "No")
				finish = 1;
			else if (answer == "NO")
				finish = 1;
			else
				cout << "You need to type: yes or no: ";
		}

		if (finish == 1) // Checks container if the user indicates to do so.
			b = IsContainerEmpty(container);
			if (b)
				cout << "Your container is empty." << endl; // If true ---> empty.
			else
				cout << "Your container has items in it." << endl; // If false ---> has items.



		for (int i = 0; i < container.size(); i++)
			cout << container[i] << endl;

	}




	int q;
	cout << endl;
	cout << "Program has finished. Enter a character to return: ";
	cin >> q; //Stops the console from closing after the program has run.
	return 0;
}

// First-In First-Out
void FifoPush(vector<string>& container, const string& item) // Takes the user's inputted item and places it in front of 
                                                             //all the other items in the container.
{
	int container_size = container.size(); 
	if (container_size > 0)
	{
		container.resize(container_size + 1);
		for (int i = (container_size); i > 0; i--)
		{
			container[i] = container[i - 1];
		}
		container[0] = item;
	}
	else
		container.push_back(item);
}
void FifoPop(vector<string>& container, string& item) // Outputs the last item in the container (the first item inputted by the user).
{
	cout << container.back() << endl;
	container.pop_back();
}

// Last-In First-Out
void LifoPush(vector<string>& container, const string& item) // Just need a simple push_back to fill the container.
{
	container.push_back(item);
}
void LifoPop(vector<string>& container, string& item)
{
	cout << container.back() << endl;
	container.pop_back();
}

// Shared functionality
bool IsContainerEmpty(const vector<string>& container) // Determines if the container is empty.
{
	if (container.size() == 0)
		return true;
	else
		return false;
}
void PrintContainer(const vector<string>& container);

bool TestFifo();
bool TestLifo();