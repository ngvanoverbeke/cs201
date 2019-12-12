#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

std::random_device r;
std::default_random_engine e1(r());

// returns a uniform distribution of random numbers within the given range
int RandomBetweenU(int first, int last){
    std::uniform_int_distribution<int> uniform_dist(first, last);
    int mean = uniform_dist(e1);
    return mean;
}

// returns a normal distribution of random numbers within the given range
int RandomBetweenN(int first, int last){
    std::uniform_int_distribution<int> uniform_dist(first, last);
    int mean = uniform_dist(e1);
    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()}; 
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);
    return std::round(normal_dist(e2));
}

// sources random numbers
int RandomBetween(int first, int last){
    return std::rand() % last + 1;
}

// outputs a list of the random numbers to show how they are diistributed
void PrintDistribution(const std::map <int, int> &hist){
    for (auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

int main()
{
    srand(time(NULL));
    std::map<int, int> histN;
    for (int n = 0; n < 50000; ++n) {
        ++histN[RandomBetweenN(1, 6)];
    }
    std::cout << "Normal distribution of random number N" << std::endl;
    PrintDistribution(histN);
    std::cout << std::endl;

    std::map<int, int> histU;
    for (int n = 0; n < 50000; ++n) {
        ++histU[RandomBetweenU(1, 6)];
    }
    std::cout << "Uniform distribution of random number U" << std::endl;
    PrintDistribution(histU);
    std::cout << std::endl;

    std::map<int, int> hist;
    for (int n = 0; n < 50000; ++n) {
        ++hist[RandomBetween(1, 6)];
    }
    std::cout << "Distribution of std::rand()" << std::endl;
    PrintDistribution(hist);
    std::cout << std::endl;
}