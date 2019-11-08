// Nathan VanOverbeke
// Lab 28
// CS 201
// 11/8/2019
// This program will output a line 10 times into a new file, and will later output integers from 1-100

#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
	std::ofstream outputfile("output.txt");
	for (size_t a = 0; a < 10; a++)
	{
		for (int i = 1; i < 11; i++)
		{
			outputfile << std::setw(4) << (10 * a) + i;
		}
		outputfile << std::endl;
	}
	outputfile.close();
	return 0;
}