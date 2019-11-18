#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

std::random_device r;
std::default_random_engine e1(r());

int RandomBetweenU(int first, int last){
    std::uniform_int_distribution<int> uniform_dist(first, last);
    int mean = uniform_dist(e1);
    return mean;
}

int RandomBetweenN(int first, int last){
    std::uniform_int_distribution<int> uniform_dist(first, last);
    int mean = uniform_dist(e1);
    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()}; 
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);
    return std::round(normal_dist(e2));
}

void PrintDistribution(const std::map <int, int> &hist){
    for (auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

int main()
{
    std::map<int, int> histN;
    for (int n = 0; n < 100000; ++n) {
        ++histN[RandomBetweenN(1, 6)];
    }
    std::cout << "Normal distribution of random number N" << std::endl;
    PrintDistribution(histN);
    std::cout << std::endl;

    std::map<int, int> histU;
    for (int n = 0; n < 100000; ++n) {
        ++histU[RandomBetweenU(1, 6)];
    }
    std::cout << "Uniform distribution of random number U" << std::endl;
    PrintDistribution(histU);
    std::cout << std::endl;
}