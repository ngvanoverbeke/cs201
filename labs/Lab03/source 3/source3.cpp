// Nathan VanOverbeke
// cs201
// 9/9/19
// Program creates a 60 x 10 box out of @ and $ signs

#include <iostream>

using namespace std;

// These initialized values will be used in the while loops to print the box
int w = 0;
int h = 0;

int main()
{
    // This will ensure that only 10 lines will be written
    while (h < 10)
    {
        //using if/else and nested while loops I alternate between two different line styles
        if (h % 2 == 0) {
            while (w < 30) {
            cout << "@$";
            w++;
        }
        }
        else {
            while (w < 30)
        {
            cout << "$@";
            w++;
        }

        }

        // Ends previous line, resets width to 0, and adds 1 to the height, as the previous line has been finished
        cout << endl;
        w = 0;
        h++;
    }
    

}