// Nathan VanOverbeke
// 9/26/19
// cs 201
// lab 10
// This program will have a main function that calls another function with an integer as a parameter that will return a bool

#include "isdiv3.hpp"

int main() {
	for (int n = 1; n <= 40; n++)
	{
		if (isdiv3(n) == true) {
			std::cout << n << " is divisible by 3" << std::endl;
		}
	}
	return 0;
}