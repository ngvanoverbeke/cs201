// Nathan VanOverbeke
// cs201
// 9/3/2019
// This is the main program of HW0; it simply prints the given text 5 times

#include <iostream>

using namespace std;
    
int main()
{
    // I used a simple while loop instead of copy/pasting "Hello world" like I did in the original version. It is much easier to change the number of times or what is printed while using this design

    int n = 0;

    while (n <= 4)
    {
        cout<<"Hello world"<<endl;
        n++;
    }
    return 0;
}