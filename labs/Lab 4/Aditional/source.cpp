// Nathan VanOverbeke
// cs201
// 9/11/19
// This program will print the numbers 1-100 while numbers divisible by 3 will be replaced with fizz and numbers divisible by 5 will be replaced by buzz

#include <iostream>

using namespace std;

int main() {
    
    for (int n = 1; n <= 100; n++)
    {
        {    
            if (n % 3 == 0)
            {
                if (n % 5 == 0)
                {
                cout << "fizz buzz" << endl;
                }

                else{
                cout << "fizz" << endl;
                }
            }
            
            if (n % 5 == 0)
            {
                cout << "buzz" << endl;
            }
            
        
            else
            {
                cout << n << endl;
            }
        }
    }
}