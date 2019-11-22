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
#include <stdlib.h>
#include <time.h>

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

std::vector<char> gameWord;
std::vector<char> userGuess{
    '_', '_', '_', '_', 
};


void failedAttempt(){
    // this function will print the current hangman graphic based on number of past 
}


// takes input of a letter from the user and checks if they have tried it yet
void userInput(){
    std::cout << "Hey you! Yeah you. Guess a letter!" << std::endl;
    char inputChar;
    std::cin >> inputChar;
    charPair.first = inputChar;
    charPair.second = true;

    auto tempI = charInventory.find(inputChar);
    if (tempI != charInventory.end()){
        std::cout << std::endl << "Hey dummy, you already tried that! Try something different." << std::endl;
    }
    else
    {
        charInventory.insert(charPair);
        
        auto tempW = find(begin(gameWord), end(gameWord), inputChar);
        if (tempW == end(gameWord)){
            std::cout << std::endl << "WRONG!!" << std::endl;
            failedAttempt();
            return;
        }
        int position = std::distance(gameWord.begin(), tempW);
        userGuess[position] = inputChar;

        std::cout << std::endl << "What manner of man are you, to guess a letter in the word without prior knowledge?! (correct)" << std::endl;
    }
}



int main(){
    srand(time(NULL));
    int gameSeed = std::rand() % 6;
    gameWord = victor[gameSeed];
    bool playing = (std::equal(gameWord.begin(), gameWord.end(), userGuess.begin()));
    while (!playing)
    {
        userInput();
        playing = (std::equal(gameWord.begin(), gameWord.end(), userGuess.begin()));
    }
    
    std::cout << "You won. Now, for something completely different." << std::endl;
    
}