// dynamic.cpp  INCOMPLETE
// Glenn G. Chappell
// 13 Apr 2018
//
// For CS 201 Spring 2018
// Dynamic Allocation
//
// Modified 11/19/18
// Chris Hartman
// For CS 201 Fall 2018

#include <iostream>
#include <random>
#include <time.h>
using std::cout;
using std::endl;
using std::cin;


int size;

// printThree
// Takes a pointer to an int array, which must have size at least 3 --
// or a null pointer. Prints the first three items in the array, or
// "NULL POINTER", if the passed pointer is null.
void printThree(int const * p)
{
    if (p == nullptr)
    {
        cout << "NULL POINTER" << endl;
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << p[i] << endl;
        }
        
        
        // cout << p[0] << " " << p[1] << " " << p[2] << endl;
    }
}


// Main Program
// Do some dynamic allocation. Call printThree multiple times.
int main()
{
    srand(time(0));
    // Make a dynamic array of int, with size at least three. Set the
    // values of the first three items in the array.
    // Then call printThree, passing (a pointer to) the array.
    std::cout << "please enter a number of at least three: ";
    std::cin >> size;
    int *myArray = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        myArray[i] = i * (rand() % 6);
    }
    printThree(myArray);

    cout << endl;

    // Call printThree with a null pointer.
    int *a = nullptr;
    printThree(a);

    // Deallocate the dynamic array.
    delete [] myArray;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
}