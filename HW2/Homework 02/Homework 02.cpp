// Nathan VanOverbeke
// CS 201
// 9/22/2019
// Homework 02
// 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void InputNames()
{

	std::vector<std::string> names;
	for (int i = 0; i < 10; i++)
	{
		std::string name;
		std::cout << "Please type a name:	";
		std::getline(std::cin, name);
		names.push_back(name);

	}
}


int main(int argc, char **argv)
{
	InputNames();

	return 0;

}
