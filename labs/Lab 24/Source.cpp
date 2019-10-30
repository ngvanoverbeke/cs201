// Nathan VanOverbeke
// 10/30/19
// cs 201
// Lab 24

#include <iostream>;
#include <map>;
#include <algorithm>;
#include <vector>;
#include <string>;


int main() {

	std::vector<int> list = { 3, 6, 2, 9, 7, 1, 4, 8, 5, 10 };

	std::cout << "Unsorted: ";
	for (auto x : list) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::sort(list.begin(), list.end());

	std::cout << "Sorted:   ";
	for (auto x : list) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::sort(list.begin(), list.end(), std::greater<int>());
	std::cout << "Reversed: ";
	for (auto x : list) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::fill(list.begin(), list.end(), 5);
	std::cout << "Filled:   ";
	for (auto x : list) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}