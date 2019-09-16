// Nathan VanOverbeke
// cs201
// 9/16/19
// This program will do a number of different tasks as defined for lab 06

#include <iostream>
#include <string>

int main () {
    std::string i;
    std::cout << "please type a string:  ";
    std::getline(std::cin, i);
    std::cout << "your string was: " << i << " and it was " << i.size() << " characters long.";
    return 0;
}