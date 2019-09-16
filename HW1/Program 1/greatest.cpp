// Nathan VanOverbeke
// cs201
// 9/15/19
// This program will intake values and store the largest until a number less than or equal to 0 is entered

int i = 1;
int b = 1;

#include <iostream>

int main() {
    while (i > 0){
    std::cout << "please enter a number  " ;
    std::cin >> i;

        if (i > b) {
            b = i;
        }
    }
    std::cout << b;
}