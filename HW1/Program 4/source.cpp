// Nathan VanOverbeke
// cs201
// 9/15/19
// This program will intake miles from a user and output kilometers

#include <iostream>

using namespace std;

double m;
double k;
int r;
int main() {
    start:
    cout << "Please enter the number of miles you would like to convert" << endl;
    cin>> m;
    k = m * 1.609344;
    cout << k << endl;
    cout << "would you like to convert another? Enter 1 for yes or 2 for no." << endl;
    cin>> r;
    if (r = 1){
        goto start;
    }

    else {
        exit(EXIT_SUCCESS);
    }

}