// Nathan VanOverbeke
// CS 201
// 9/22/2019
// Homework 02
// 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::vector<std::string> inputNames()
{
	std::vector<std::string> names;
	std::string pulled;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Enter a name: ";
		getline(std::cin, pulled);
		names.push_back(pulled);
	}

	return names;
}

void nameSearch(std::vector<std::string> x) {
	std::vector<std::string> namelist = x;
	std::string localName;
	std::cout << "Name Search:	";
	getline(std::cin, localName);

	int appears = 0;

	for (int i = 0; i < 10; i++) {
		if (localName == namelist.at(i)) {
			appears++;
		}
	}

	if (appears > 1) {
		std::cout << "That name apears " << appears << " times" << std::endl;
	}
	else if (appears == 1) {
		std::cout << "That name appears once" << std::endl;
	}
	else {
		std::cout << "Sorry. That name did not appear" << std::endl;
	}
}

void printNames(std::vector<std::string> x) {
	std::vector<std::string> namelist = x;
	for (int i = 0; i < 10; i++) {
		std::cout << namelist.at(i);
		std::cout << std::endl;
	}
}

void reverseOrder(std::vector<std::string> x) {
	std::vector<std::string> namelist = x;
	std::vector<std::string> reversedSpelling;

	int y;
	std::string normal;
	std::string temporary;

	for (int i = 0; i < 10; i++){
		normal = namelist.at(i);

		y = normal.size();

		temporary.resize(y);

		while (y > 0) {
			temporary.at(y - 1) = normal.at(normal.size() - y);
			--y;
		}
		reversedSpelling.push_back(temporary);		

	}
	
	
	std::reverse(reversedSpelling.begin(), reversedSpelling.end());
	std::cout << "Now that list backwards is:	" << std::endl;

	for (std::vector<std::string>::iterator rev = reversedSpelling.begin(); rev != reversedSpelling.end(); ++rev)
		std::cout << ' ' << *rev << std::endl;

	
}


int main(int argc, char **argv)
{
	std::vector<std::string> namelist = inputNames();
	std::string name;	

	nameSearch(namelist);

	printNames(namelist);

	reverseOrder(namelist);

	return 0;

}
