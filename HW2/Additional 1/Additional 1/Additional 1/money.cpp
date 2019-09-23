// Nathan VanOverbeke
// 9/22/19
// CS 201
// This program will take the number if each coin a user has and output the number of each and then total them up

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> coinSlot() {
	vector<int> coins;
	int buffer;
	for (int i = 1; i <= 5; i++) {
		int n = i;
		switch (n) {
		case 1:
			cout << "Please enter the number of pennies you have:	";
			break;
		case 2:
			cout << "Please enter the number of nickles you have:	";
			break;
		case 3:
			cout << "Please enter the number of dimes you have:		";
			break;
		case 4:
			cout << "Please enter the number of quarters you have:	";
			break;
		case 5:
			cout << "Please enter the number of half-dollars you have:	";
			break;
		}
		n++;
		cin >> buffer;
		coins.push_back(buffer);
		cout << endl;
	}

	return coins;
}


int main() {
	vector<int> coins = coinSlot();


}