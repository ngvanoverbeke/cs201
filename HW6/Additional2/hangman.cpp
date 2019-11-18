// Nathan VanOverbeke
// CS201 HW6: additiona; program 2 (hangman game)
// 11/17/19
// This will be a basic hangman game using a map to keep track of words used and no for/while loops

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <random>

using std::begin;
using std::end;
using std::find;

std::pair<char, bool> charPair;
std::map<char, bool> charInventory; // DONT TOUCH THIS!!

std::vector<std::vector<char>> victor{
    {'f','o','u','r'},
    {'f','i','v','e'},
    {'f','a','i','l'},
    {'f','o','r','d'},
    {'f','o','a','l'},
    {'f','o','u','l'}};

std::vector<char> bird;

// takes input of a letter from the user and checks if they have tried it yet
void userInput(){
    char inputChar;
    std::cin >> inputChar;
    auto temp = find(begin(charInventory), end(charInventory), inputChar);
    if (temp == end(charInventory)){
        std::cout << std::endl << "Hey dummy, you already tried that! Try something different." << std::endl;
        userInput();
    }

    charPair.first = inputChar;
    charPair.second = true;

    charInventory.insert(charPair);
    
}

void failedAttempt(){
    // this function will print the current hangman graphic based on number of past 
}

int main(){
    
}