// Nathan VanOverbeke
// 10/23/19
// 
#include <iostream>;
#include "truncstruct.hpp"


int main() {
	std::string strukt;
	std::cin >> strukt;

	std::cout << trunc8(strukt).str << std::endl;

}