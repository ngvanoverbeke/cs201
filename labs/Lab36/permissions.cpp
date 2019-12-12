// Nathan VanOvebeke
// Lab 36
// 12/2/2019
// This program is inspired by the example; sandwich.cpp
// It will use binary and flags to make a single integer represent the level of permission(s) a user has

#include <iostream>

const int plebian = 0b1;
const int basic = 0b10;
const int moderator = 0b100;
const int admin = 0b1000;
const int bot = 0b10000;
const int superUser = 0b100000;
const int root = 0b1000000;
const int hiddenBackDoorRoot = 0b10000000;


void printperms(int& perms){
    std::cout << " your have: ";
    if ((perms & plebian) != 0){
        std::cout << "Plebian ";
    }
    if ((perms & basic) != 0){
        std::cout << "Basic ";
    }
    if ((perms & moderator) != 0){
        std::cout << "Moderator ";
    }
    if ((perms & admin) != 0){
        std::cout << "Admin ";
    }
    if ((perms & bot) != 0){
        std::cout << "Bot ";
    }
    if ((perms & superUser) != 0){
        std::cout << "Super User ";
    }
    if ((perms & root) != 0){
        std::cout << "Root ";
    }
    
    if ((perms & hiddenBackDoorRoot) != 0){
        std::cout << "Hidden Backdoor Root ";
    }
    std::cout << "priveledges.\n";
}

int main () {
    int permission;
    std::cout << "What level of permissions would you like?   ";
    std::cin >> permission;

    printperms(permission);
}