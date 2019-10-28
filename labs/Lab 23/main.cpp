// Nathan VanOverbeke
// 10/28/19
// cs 201
// Lab 23

#include <iostream>;
#include <map>;
#include <string>;


int main() {

	std::map<std::string, int> names;
	names["sally"] = 1;
	names["john"] = 2;
	names["eric"] = 3;
	names["emily"] = 4;
	names["derick"] = 5;

	names.erase("derick");

	for (auto i : names)
	{
		std::cout << i.first << std::endl;
	}
}