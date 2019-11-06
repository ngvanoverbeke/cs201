// Nathan VanOverbeke
// 11/6/19
// Lab 27

#include <random>
#include <iostream>



int main() {
int tails = 0;
int heads = 0;

std::random_device seed;
std::mt19937_64 gen(seed());
std::uniform_int_distribution<int> coin(0, 1);

for (size_t i = 0; i < 1000; i++)
{
	int flip = coin(gen);

	if (flip == 0)
	{
		tails++;
	}

	if (flip == 1) {
		heads++;
	}
}
std::cout <<"heads:" << heads << std::endl << "tails" << tails;
}