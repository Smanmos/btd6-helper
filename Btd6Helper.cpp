// Btd6Helper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "tower/tower.h"
#include "loader.h"

std::string trim(std::string &str) {
    size_t start = str.find_first_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start);
}

int main(int argc, char *argv[]){
    std::vector<Tower> towers = loadTowers();
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream tokener(input);
        std::string command;
        tokener >> command;
        if (command == std::string("dps")) {
            std::string towerName;
            std::getline(tokener, towerName);
            towerName = trim(towerName);
            bool towerFound = false;
            for (auto tower = towers.begin(); tower != TOWERS.end(); ++tower) {
                if (towerName == tower->getName()) {
                    std::cout << "dps: " << tower->getDamagePerSecond() << std::endl;
                    towerFound = true;
                    break;
                }
                if (!towerFound) {
                    std::cout << "No such tower found" << std::endl;
                }
            }
        }
        else if (command == std::string("info")) {
            std::string towerName;
            std::getline(tokener, towerName);
            towerName = trim(towerName);
            bool towerFound = false;
            for (auto tower = TOWERS.begin(); tower != TOWERS.end(); ++tower) {
                if (towerName == tower->getName()) {
                    std::cout << tower->getStats();
                    towerFound = true;
                    break;
                }
            }
            if (!towerFound) {
                std::cout << "Tower not found" << std::endl;
            }
        }
        else if (command == std::string("exit")) {
            std::cout << "Thanks for using Btd6Helper!" << std::endl;
            break;
        }
        else {
            std::cout << "Command not recognised" << std::endl;
        }
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
