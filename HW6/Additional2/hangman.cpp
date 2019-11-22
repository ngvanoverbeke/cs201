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

void draw();

using std::begin;
using std::end;
using std::find;

std::pair<char, bool> charPair;
std::map<char, bool> charInventory; // DONT TOUCH THIS!!

int WRONG = 0;


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
    draw();
    std::cout << userGuess[0] << userGuess[1] << userGuess[2] << userGuess[3] << std::endl;

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
            WRONG++;
            return;
        }
        int position = std::distance(gameWord.begin(), tempW);
        userGuess[position] = inputChar;

        std::cout << std::endl << "What manner of man are you, to guess a letter in the word without prior knowledge?! (correct)" << std::endl;
    }
}

int main(){
    srand(time(NULL));
    int gameSeed = std::rand() % 6; // NOTE: to add more words, simply make sure this number (6 by default) matches the number of words you have!
    gameWord = victor[gameSeed];
    bool playing = (std::equal(gameWord.begin(), gameWord.end(), userGuess.begin()));

    while (!playing)
    {
        userInput();
        //std::cout << userGuess << std::endl;
        playing = (std::equal(gameWord.begin(), gameWord.end(), userGuess.begin()));

        if (WRONG == 10){
            failedAttempt();
            std::cout << "You get nothing! You lose, good day sir!" << std::endl;
            break;
        }
    failedAttempt();
    }
    if(playing){
        std::cout << "You won. Now, for something completely different." << std::endl;   
    }
    
    
}


void draw(){
    switch (WRONG)
    {
    case 1:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |      (_)" << std::endl <<
        " |         " << std::endl <<
        " |        " << std::endl <<
        " |         " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;

    case 2:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |      (_)" << std::endl <<
        " |       |  " << std::endl <<
        " |       | " << std::endl <<
        " |         " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 3:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |      (_) " << std::endl <<
        " |      \\|  " << std::endl <<
        " |       | " << std::endl <<
        " |         " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 4:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |      (_)" << std::endl <<
        " |      \\|/  " << std::endl <<
        " |       | " << std::endl <<
        " |         " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 5:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |     _(_)" << std::endl <<
        " |      \\|  " << std::endl <<
        " |       | " << std::endl <<
        " |         " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 6:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |     _(_)_" << std::endl <<
        " |      \\|/  " << std::endl <<
        " |       | " << std::endl <<
        " |         " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 7:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |     _(_)_" << std::endl <<
        " |      \\|/  " << std::endl <<
        " |       | " << std::endl <<
        " |      /  " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 8:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |     _(_)_" << std::endl <<
        " |      \\|/  " << std::endl <<
        " |       | " << std::endl <<
        " |      / \\ " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 9:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |     _(_)_" << std::endl <<
        " |      \\|/  " << std::endl <<
        " |       | " << std::endl <<
        " |     _/ \\ " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    case 10:
        std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |     _(_)_" << std::endl <<
        " |      \\|/  " << std::endl <<
        " |       | " << std::endl <<
        " |     _/ \\_ " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    default:
     std::cout <<
        "  _______" << std::endl <<
        " |/      |" << std::endl <<
        " |         " << std::endl <<
        " |         " << std::endl <<
        " |        " << std::endl <<
        " |         " << std::endl <<
        " |" << std::endl <<
        "_|___" << std::endl;
        break;
    }
}