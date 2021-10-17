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
            tokener >> towerName;
            towerName = trim(towerName);
            try {
                std::string upgradeStr;
                tokener >> upgradeStr;
                UpgradePattern* upgradePattern;
                if (upgradeStr.size() == 0) {
                    upgradePattern = new UpgradePattern();
                }
                else if (upgradeStr.size() == 3) {
                    upgradePattern = new UpgradePattern(
                        upgradeStr[0] - '0', upgradeStr[1] - '0', upgradeStr[2] - '0');
                }
                else {
                    throw std::invalid_argument("Illegal upgrade pattern");
                }
                bool towerFound = false;
                for (auto tower = towers.begin(); tower != towers.end(); ++tower) {
                    if (tower->matches(towerName)) {
                        std::cout << tower->getDamagePerSecond(*upgradePattern);
                        towerFound = true;
                        break;
                    }
                }
                if (!towerFound) {
                    std::cout << "Tower not found" << std::endl;
                }
            }
            catch (std::invalid_argument e) {
                std::cout << "Invalid Upgrade format" << std::endl;
            }
        }
        else if (command == std::string("info")) {
            std::string towerName;
            tokener >> towerName;
            towerName = trim(towerName);
            try {
                std::string upgradeStr;
                tokener >> upgradeStr;
                UpgradePattern* upgradePattern;
                if (upgradeStr.size() == 0) {
                    upgradePattern = new UpgradePattern();
                }
                else if (upgradeStr.size() == 3) {
                    upgradePattern = new UpgradePattern(
                        upgradeStr[0] - '0', upgradeStr[1] - '0', upgradeStr[2] - '0');
                }
                else {
                    throw std::invalid_argument("Illegal upgrade pattern");
                }
                bool towerFound = false;
                for (auto tower = towers.begin(); tower != towers.end(); ++tower) {
                    if (tower->matches(towerName)) {
                        std::cout << tower->getStats(*upgradePattern);
                        towerFound = true;
                        break;
                    }
                }
                if (!towerFound) {
                    std::cout << "Tower not found" << std::endl;
                }
            }
            catch (std::invalid_argument e) {
                std::cout << "Invalid Upgrade format" << std::endl;
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
