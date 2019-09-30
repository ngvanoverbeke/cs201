// Nathan VanOverbeke
// 9/29/2019
// CS 201
// This program will use a broken bit of code to make a working celsius to kelvin converter

#include <iostream>


using std::cin;
using std::cout;
using std::endl;

double ctok(double c) {
	double k = c + 273.15;
	return k;
}

int main() {
	double c = 0;
	cout << "This program will convert celsius to Kelvin" << std::endl;
	cout << "Degrees Celsius: ";
	cin >> c;
	while (c < 273.15){
		cout << "Sorry, but that is not a valid temperature! Absolute 0 is at 273.15 degrees!" << endl;
		cout << "Please enter a VALID temperature!: ";
		cin >> c;
	}
	double k = ctok(c);
	cout << k << std::endl;
}