// Nathan VanOverbeke
// cs201
// 9/11/19
// This program will print the numbers 1-100 while numbers divisible by 3 will be replaced with fizz

#include <iostream>

using namespace std;

int n = 1;

int main() {
    
    // ensures we count to 100 and then stop
    while (n <= 100)
    {    
        // checks if divisble by 3
        if (n % 3 == 0)
        {
            cout << "fizz" << endl;
            n++;
        }

        // prints the number if it is not divisible by 3
        else
        {
            cout << n << endl;
            n++;
        }
    }
}