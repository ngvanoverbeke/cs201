// Nathan VanOverbeke
// cs201
// 9/13/19
// This program will use an if statement to pair a given number with it's corresponding day of the week... or not

#include <iostream>

int main() {
    std::cout << "Please enter a number:     ";
    int n;
    std::cin >> n;
    
    if (n == 1)
    {
        std::cout << "Monday";
        return 0;
    }
        else if (n == 2)
        {
            std::cout << "Tuesday";
            return 0;
        }

        else if (n == 3)
        {
            std::cout << "Wednesday";
            return 0;
        }
        
        else
        {
            std::cout << "Not Monday, Tuesday, or Wednesday!";
            return 0;
        }

}