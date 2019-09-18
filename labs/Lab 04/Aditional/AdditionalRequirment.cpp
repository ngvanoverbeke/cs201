// Nathan VanOverbeke
// cs201
// 9/11/19
// This program will print the numbers 1-100 while numbers divisible by 3 will be replaced with fizz and numbers divisible by 5 will be replaced by buzz

#include <iostream>

using namespace std;

int main() {
    
    // ensures we go to 100 and then stop
    for (int n = 1; n <= 100; n++)
    {
        {   
            // checks if divisible by 3
            if (n % 3 == 0)
            {
                //checks if also divisible by 5
                if (n % 5 == 0)
                {
                    cout << "fizz buzz" << endl;
                }

                else{
                    cout << "fizz" << endl;
                }
            }
            
            // checks if divisible by 5
            if (n % 5 == 0)
            {
                cout << "buzz" << endl;
            }
            
            // prints the number if it's found to not be divisible by 3 or 5
            else
            {
                cout << n << endl;
            }
        }
    }
}