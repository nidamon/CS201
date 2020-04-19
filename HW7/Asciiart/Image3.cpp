// Image3.hpp
// Implementation for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include "Image3.h"

// Image3 Constructor
Image3::Image3(unsigned width, unsigned height) {
	// TODO: resize the pixels array
	//pixels.resize(width * height); // Attempted to go with resizing 
									 //but found using pushback to be easier
	// TODO: initialize the internal w and h members
	w = width;
	h = height;
}

// Return a pixel from the image
const Color3& Image3::getPixel(unsigned x, unsigned y) const {
	// TODO: Add error handling for unknown pixels
	if (x > w)
	{
		cout << "Error with x value" << endl;
		x = w;
	}
	if (y > h)
	{
		cout << "Error with y value" << endl;
		y = h;
	}
	// TERRIBLE OPTION 1: throw
	// BETTER OPTION 2: return a color
	// Hint: maybe this is already in the class?

	return pixels[y * w + x];
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) {
	// TODO: Set the pixel to the new color

}

bool Image3::savePPM(const std::string& path) const {
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	return false;
}

bool Image3::loadPPM(const std::string& path) {
	// TODO: Load an image from the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	Color3 pixel;
	int RGB_color = 0; //Place holder for the ints read from the ppm file
	ifstream fin(path);
	if (!fin) // If file doesn't open, inform user
	{
		cout << "Error opening file" << endl;
		Sleep(1000); // sits for a second or so
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
				if (fin.eof()) // Stop reading at the end of the file
				{
					cout << "Finished reading file" << endl;
					Sleep(1000); // sits for a second or so
					break;
				}
				else
				{
					cout << "Error during transmit." << endl;
					Sleep(1000); // sits for a second or so
					break;
				}
			}
			else
			{
				istringstream instream(line); // Gets the line from getline
				instream >> RGB_color; // Pulls out the RGB int
				if ((repeat % 3) == 0) // Picks what should be the R
				{
					pixel.R = RGB_color; // Sets pixel's R to RGB_color
				}
				if ((repeat % 3) == 1) // Picks what should be the G
				{
					pixel.G = RGB_color; // Sets pixel's G to RGB_color
				}
				if ((repeat % 3) == 2) // Picks what should be the B
				{
					pixel.B = RGB_color; // Sets pixel's B to RGB_color
					pixels.push_back(pixel); // Adds the pixel and its color data to vector pixels
				}
				repeat++;
			}
		}
	}
	cout << "Load complete" << endl; // Informs of completed load
	cout << endl;
	return false;
}

void Image3::printASCII(std::ostream& ostr) const {
	// TODO: Print an ASCII version of this image
}

// STREAM OPERATORS for IMAGE3 class

std::ostream& operator<<(std::ostream& ostr, const Image3& image) {
	// TODO: Write out PPM image format to stream
	// ASSUME FORMAT WILL BE GOOD
	return ostr;
}

std::istream& operator>>(std::istream& istr, Image3& image) {
	// TODO: Read in PPM image format from stream
	// MAKE SURE FORMAT IS GOOD!!!
	return istr;
}
