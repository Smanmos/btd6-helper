// Btd6Helper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "tower/towers.h"

int main(int argc, char *argv[]){
    std::string input;
    std::getline(std::cin, input);
    std::istringstream tokener(input);
    std::string command;
    tokener >> command;
    if (command == std::string("info")) {
        std::string towerName;
        tokener >> towerName;
        Tower* tower = nullptr;
        if (towerName == std::string("dart")) {
            tower = new DartMonkey();
        }
        else if (towerName == std::string("boomerang")) {
            tower = new BoomerangMonkey();
        }
        if (tower != nullptr) {
            std::cout << "dps: " << tower->getDamagePerSecond();
        }
    }
    else {
        std::cout << "Command not recognised" << std::endl;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
