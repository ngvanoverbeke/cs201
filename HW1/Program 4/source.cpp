// Nathan VanOverbeke
// cs201
// 9/15/19
// This program will intake miles from a user and output kilometers

#include <iostream>

using namespace std;

// m will be the value (in miles) the user inputs to be converted
double m;

// k (kilometers) will be the output of the converted value
double k;

int main() {
    start:
    cout << "Please enter the number of miles you would like to convert" << endl;
    
    // recieves user input
    cin>> m;

    // caclulates the conversion
    k = m * 1.609344;

    // prints out the converted value
    cout << k << endl;

}