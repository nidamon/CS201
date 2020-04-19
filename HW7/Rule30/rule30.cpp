/*rule30.cpp
Nathan Damon
CS 201
4/19/2020
This program will output a cellular automata.
Lots of help from The Coding Train and his video:
        "7.2: Wolfram Elementary Cellular Automata - The Nature of Code"
*/

#include "RuleWolfram.h"

int main()
{
    RuleWolfram rule30;
    vector<int> rule_30 = { 0, 0, 0, 1, 1, 1, 1, 0 };
    int rows = 20;
    int columns = 40;
    int temp = 0;
    string str;

    cout << "Enter 0 to use rule 30 or 1 for custom ruleset: ";
    int select;
    while (true) // Gets the users selection
    {
        std::getline(cin, str);
        istringstream instream(str);
        instream >> select;
        if (instream)
            if (select == 1 || select == 0)
                break;
        cout << "You need to enter 0 or 1: ";
    }
    if (select == 1)
    {
        // Input for a ruleset
        for (int i = 0; i < 8; i++)
        {
            cout << "Enter a number (0 or 1) in slot " << (i + 1) << " for the custom ruleset (8 in total): ";
            while (true)
            {
                std::getline(cin, str);
                istringstream instream(str);
                instream >> temp;
                if (instream)
                    if (temp == 1 || temp == 0)
                    {
                        rule_30[i] = temp;
                        break;
                    }
                cout << "You need to enter 0 or 1: ";
            }

        }
    }

    // Input for the number of columns
    cout << "Enter a number for columns (minimum of 40, 400 recommended): ";
    while (true)
    {
        std::getline(cin, str);
        istringstream instream(str);
        instream >> columns;
        if (instream)
            if (columns > 39)
                break;
        cout << "You need to enter a number for columns (minimum of 40, 400 recommended): ";
    }

    //  Input for the number of rows
    cout << "Enter a number for rows (minimum of 20, half the value of columns is recommended): ";
    while (true)
    {
        std::getline(cin, str);
        istringstream instream(str);
        instream >> rows;
        if (instream)
            if (rows > 19)
                break;
        cout << "You need to enter a number for rows (minimum of 20, 200 recommended): ";
    }
    system("cls"); // refreshes the console screen.

    int i = 0;
    if (i == 0)
    {
        ofstream fout("rule30.txt");
        if (!fout)
        {
            cout << "Error opening file" << endl;
            return false;
        }
        else
            cout << "File contents removed";
    }

    
    rule30.set_gen_size(columns);
    rule30.ruleset = rule_30; // Sets the ruleset in the class to rule 30
    for (int i = 0; i < (rows / 15); i++)
        cout << endl;


    Image3 image;


    for (int i = 0; i < rows; i++)
    {
        image.savePPM("rule30.txt", rule30);
        rule30.output();
    }
 

    // Stops the console from closing.
    cout << "Don't Scroll or the pixels will be lost!" << endl;
    int q;
    cin >> q;

    return 0;
}


// Rules for rule30
int RuleWolfram::rules(int a, int b, int c)
{
    if (a == 1 && b == 1 && c == 1) return ruleset[0];
    if (a == 1 && b == 1 && c == 0) return ruleset[1];
    if (a == 1 && b == 0 && c == 1) return ruleset[2];
    if (a == 1 && b == 0 && c == 0) return ruleset[3];
    if (a == 0 && b == 1 && c == 1) return ruleset[4];
    if (a == 0 && b == 1 && c == 0) return ruleset[5];
    if (a == 0 && b == 0 && c == 1) return ruleset[6];
    if (a == 0 && b == 0 && c == 0) return ruleset[7];
}


// Sets the size of each row
void RuleWolfram::set_gen_size(int columns)
{
    current_generation.resize(columns, 0);
    current_generation[(current_generation.size()/2)] = 1;
    next_generation.resize(columns, 0);
}


// Creates the new generation based on the previous one
void RuleWolfram::generate()
{
    for (size_t i = 1; i < current_generation.size()-1; i++)
    {
        int left = current_generation[i - 1];
        int middle = current_generation[i];
        int right = current_generation[i + 1];
        next_generation[i] = rules(left, middle, right);
    }
    current_generation = next_generation; // Sets the current gen to the new gen
    gen_count++;
}


// Displays the row of the current generation
void RuleWolfram::output()
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);

    // Colors
    COLORREF light = RGB(0, 0, 0);
    COLORREF dark = RGB(255, 255, 255);
    COLORREF Color = RGB(255, 255, 255);

    //Draw pixels
    for (int i = 0; i < current_generation.size(); i++)
    {
        if (current_generation[i] == 0)
            Color = dark;
        if (current_generation[i] == 1)
            Color = light;
        SetPixel(mydc, i, gen_count, Color);
    }
    generate();
}



bool Image3::savePPM(const std::string& path, const RuleWolfram& rule) const {
    // TODO: Save the image to the disk
    // REQUIREMENT: Use the STREAM operators for the file contents
    ofstream fout(path, ios::app);
    if (!fout)
    {
        cout << "Error opening file" << endl;
        return false;
    }
    else
    {
        for (int i = 0; i < rule.current_generation.size(); i++)
        {
            if (rule.current_generation[i] == 0)
                fout << "W";
            if (rule.current_generation[i] == 1)
                fout << " ";
            if (!fout)
            {
                cout << "Error writing to file" << endl;
                return false;
            }
        }
        fout << endl;
    }
    return false;
}