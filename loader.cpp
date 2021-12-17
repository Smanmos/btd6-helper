#include "loader.h"
#include "tower/tower.h"
#include "tower/attackbuilder.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

std::vector<Tower> loadTowers() {
	std::vector<Tower> towers = std::vector<Tower>();
	std::fstream towerFile("resources/towers.json");
	try {
		json towerJsons;
		towerFile >> towerJsons;
		for (json::iterator towerIt = towerJsons.begin(); towerIt != towerJsons.end(); ++towerIt) {
			try {
				Tower tower = Tower(towerIt.key(), towerIt.value());
				towers.push_back(tower);
			}
			catch (json::exception &e) {
				std::cout << "Error parsing tower " << towerIt.key() << ":" << std::endl;
				std::cout << e.what() << std::endl;
			}
		}
	}
	catch (json::parse_error &e) {
		std::cout << "Error reading file:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return towers;
}