// Nathan VanOverbeke
// cs201
// 9/18/19
// This program will interface with intio.cpp and intio.hpp to make them do what we want

#include <iostream>
#include "intio.hpp"

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    cout << "please stype some numbers" << endl;
    int input = getInt();
    putInt(input, 10);

}