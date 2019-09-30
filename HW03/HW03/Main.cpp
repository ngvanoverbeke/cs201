// Nathan VanOverbeke
// 9/29/2019
// CS 201
// This prgoram will take two inputs for the user. A string, which will be printed inside am asterisk box, and an integer; the size of the box to be made.

#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


// Creates the full line of asterisks that apears on the top and bottom of the box
void bar(int & size) {
	for (int i = 0; i < size; i++){
		cout << "*";
	}
	cout << endl;
}

// Used to create the bar on the left side of a middle/space line
void LeftBar(int& size) {
	for (int i = 0; i < size; i++){
		cout << "*";
	}
	cout << " ";
}

// Same as LeftBar, but reversed and with an end line statement on the end;
void RightBar(int& size) {
	cout << " ";
	for (int i = 0; i < size; i++) {
		cout << "*";
	}
	cout << endl;
}

// Will create the middle/filler bar of spaces on the top and bottom of the string line
void SpaceBar(int& size) {
	for (int i = 0; i < size; i++) {
		cout << " ";
	}
}

// called by main; prompts for the string and size of the bar, then uses the other functions to create the box itself
void create() {
	int Isize = 0;
	std::string BoxContents;

	cout << "Please enter a string: ";
	cin >> BoxContents;
	cout << "Please enter the number of layers you would like: ";
	cin >> Isize;

	// this while loop not only checks the input variable's size, but it also wont leave the loop until the user inputs a correct number
	while (Isize <= 0) {
		cout << "I'm sorry, that's an invalid size, please enter a number greater than 0: ";
		cin >> Isize;
	}

	// both of the integers are specifically for the size of the top bar and space bar
	int BarSize = BoxContents.size() + (Isize * 2) + 2;
	int SpaceSize = BoxContents.size();

	// this for loop, which also apears on the bottom ensures the correct number of bars are printed
	for (int i = 0; i < Isize; i++) {
		bar(BarSize);
	}
	LeftBar(Isize);

	SpaceBar(SpaceSize);

	RightBar(Isize);

	LeftBar(Isize);

	cout << BoxContents;

	RightBar(Isize);

	LeftBar(Isize);

	SpaceBar(SpaceSize);

	RightBar(Isize);

	for (int i = 0; i < Isize; i++) {
		bar(BarSize);
	}
}

int main() {
	int run = 0;
	while (run <= 0) {
		
		cout << "Would you like to create a custom box?!" << endl;
		cout << "enter 0 for yes or 1 for no" << endl;
		cin >> run;
		if (run >= 1) {
			cout << "Thank you for playing, goodbye!";
			return 0;
		}
		else {
			create();
		}
	}
}