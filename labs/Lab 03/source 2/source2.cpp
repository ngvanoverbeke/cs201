// Nathan VanOverbeke
// cs201
// 9/9/19
// Program creates a 60 x 10 box out of @ signs

#include <iostream>

using namespace std;

// These initialized values will be used in the while loops to print the box
int w = 1;
int h = 1;

int main()
{
    // This will ensure that only 10 lines will be written
    while (h <= 10)
    {
        // This will ensure there are 60 "@" symbols per line
        while (w <= 60)
        {
            cout << "@";
            w++;
        }
        // Ends previous line, resets width to 1, and adds 1 to the height, as the previous line has been finished
        cout << endl;
        w = 1;
        h++;
    }
    

}