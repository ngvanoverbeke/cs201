// Nathan VanOverbeke
// cs201
// 9/9/19
// Print 1-20 by using a while loop

#include <iostream>

using namespace std;

// init n, which will be used throughout
int n = 1;

int main() {
    // This is the while loop that will check that will stop printing after n reaches 20
    while (n <= 20)
    {   
        // This cout will simply print n
        cout << n << endl;

        // n++ simply adds one to n, as n has been printed and needs to be increased by 1
        n++;
    }
    return 0;
    
}