// Nathan VanOverbeke
// cs201
// 9/13/19
// This program will use a switch statement to pair a given number with it's corresponding day of the week... or not

#include <iostream>

int main() {
    std::cout << "Please enter a number:     ";
    int n;
    std::cin >> n;
    switch (n)
    {
    case 1:
        std::cout << "Monday";
        break;
    case 2:
        std::cout << "Tuesday";
        break;
    case 3:
        std::cout << "Wednesday";
        break;    
    default:
        std::cout << "Not monday, Tuesday, or Wednesday!";
        break;
    }

}