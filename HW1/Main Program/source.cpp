// Nathan VanOverbeke
// cs201
// 9/15/19
// This program will print a diamond given the size by a user

#include <iostream>

using namespace std;

int i = 1; // input

int x;

int main() {

    // asks the the user for a value but also tells the user what the value will do
    cout << "Please enter the size of the diamond you would like to create" << endl;
    cin >> x;

    // checks if the given input is useable and exits if its not
    if (x < 1)
    {
        cout << "Sorry, please try a positive number" << endl;
        return 0;
    }

    else
    {
        // init value l so that it can be used in the for loop after this one
        int l;

        // this for loop handles the top half of the diamond
        for (int i = 0; i <= x; i++)
        {

            // this for loop handles the spaces on each line that are put in before the hashes start
            for (int k = 0; k < x - i; k++)
            {
                cout << " ";
            }

            // this for loop outputs the correct number of hashes
            for (int p = 0; p < 2 * i - 1; p++)
            {
                cout << "#";
            }

            // after the line is finished this ends the line and resets the value of r to the input
            cout << endl;
            l = i;
        }

        // this is the 2nd loop that will handle the bottom half of the diamond by subtracting each time it loops
        for (int i = l-=1; i > 0; i--)
        {
            // this for loop is the same as the one above, it handles the spaces before the hashes
            for (int k = 0; k < x - i; k++)
            {
                cout << " ";
            }

            // this 
            for (int p = 0; p < 2 * i - 1; p++)
            {
                cout << "#";
            }
            cout << endl;
        }
    }
}