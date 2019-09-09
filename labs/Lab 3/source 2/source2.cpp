// Nathan VanOverbeke
// cs201
// 9/9/19
// Program creates a 60 x 10 box out of @ signs

#include <iostream>

using namespace std;

int w = 1;
int h = 1;

int main()
{
    while (h <= 10)
    {
        while (w <= 60)
        {
            cout << "@";
            w++;
        }
        cout << endl;
        w = 1;
        h++;
    }
    

}