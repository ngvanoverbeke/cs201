// Nathan VanOverbeke
// cs201
// 9/15/19
// This program will print a diamond given the size by a user

#include <iostream>

using namespace std;

int i = 1; // input
int h = 0; // height
int w = 0; // width

int main() {
    cout << "Please enter the size of the diamond you would like to create" << endl;
    cin >> i;

    if (i < 1)
    {
        cout << "Sorry, please try a positive number" << endl;
        return 0;
    }

    else
    {
        while ( i >= h )
        {
            while (h > w)
            {
                cout << "#" ;
                w++;
            }   
            cout << endl;
            h++;
        }
    }
    
    return 0;
    
}