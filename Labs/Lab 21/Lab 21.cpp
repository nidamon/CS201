/*Lab 21.cpp
Nathan Damon
CS 201
3/31/2020
This file will use a function "trunc8" defined within truncstruct.cpp.
Now it will also use FLTK.
*/

#include "truncstruct.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <FL/Fl.h>
#include <FL/Fl_Box.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Input.h>
#include <FL/Fl_Output.h>
#include <FL/Fl_Value_Input.h>
#include <FL/Fl_Button.h>

int integer;

int main(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(500, 300);

    Fl_Box* box1 = new Fl_Box(150, 20, 200, 30, "Welcome to Truncate!");
    box1->box(FL_UP_BOX);
    box1->labelfont(FL_BOLD + FL_ITALIC);
    box1->labelsize(16);
    
    //Instructions
    Fl_Box* box2 = new Fl_Box(60, 60, 400, 20, "To truncate, you need to input a string and an integer value.");
    box2->box(FL_UP_BOX);
    box2->labelfont(FL_ITALIC);
    box2->labelsize(12);

    
    //String input
    Fl_Input* input1 = new Fl_Input(140, 90, 130, 20, "Enter a string:");
    input1->box(FL_UP_BOX);
    input1->labelfont(FL_ITALIC);
    input1->labelsize(12);
    input1->value("String Here");

    //Instructions - integer
    Fl_Box* box3 = new Fl_Box(60, 120, 300, 20, "Enter the number of characters you want to truncate.");
    box3->box(FL_UP_BOX);
    box3->labelfont(FL_ITALIC);
    box3->labelsize(12);

    //Integer input
    Fl_Value_Input* input2 = new Fl_Value_Input(150, 150, 130, 20, "Pick an integer:");
    input2->box(FL_UP_BOX);
    input2->labelfont(FL_ITALIC);
    input2->labelsize(12);
    input2->value(integer);

    //Button Truncate
    Fl_Button* button1 = new Fl_Button(130, 180, 100, 20, "Truncate");
    button1->box(FL_UP_BOX);
    button1->labelfont(FL_BOLD + FL_ITALIC);
    button1->labelsize(12);
    button1->value();

    //Button Quit
    Fl_Button* button2 = new Fl_Button(250, 180, 100, 20, "Quit");
    button2->box(FL_UP_BOX);
    button2->labelfont(FL_BOLD + FL_ITALIC);
    button2->labelsize(12);
    button2->value();

    //Output
    Fl_Output* output = new Fl_Output(180, 210, 200, 30, "Your string, truncated:");
    output->box(FL_UP_BOX);
    output->labelfont(FL_ITALIC);
    output->labelsize(12);
    output->value();
    
    window->end();
    window->show(argc, argv);
    return Fl::run();
}




// If using within Lab 21 project comment out the above and uncomment the below.


//int main()
//{
//	string str;
//	cout << "Enter a string: ";
//	cin >> str;
//
//	int len = -1;
//
//	cout << "Enter a positive number: ";
//	cin >> len;
//	while (len < 0)
//	{
//		cout << "Please enter a positive number: ";
//		cin >> len;
//	}
//
//	cout << endl;
//
//	StringInfo User_string;
//
//	if (len > 0)
//	{
//		StringInfo User_input{ str, len };
//		User_string = trunc(User_input);
//	}
//	else
//	{
//		User_string = trunc8(str);
//	}
//	
//	string s = User_string.str;
//	len = User_string.len;
//
//	cout << "Your new string is: " << s 
//		 << " And your string's new length is: " << len 
//		 << "." << endl;
//
//	int q;
//	cin >> q;
//}