#include "loader.h"
#include "tower/tower.h"
#include "tower/attackbuilder.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

std::vector<Tower> loadTowers() {
	std::vector<Tower> towers = std::vector<Tower>();
	std::fstream towerFile("resources/towers.json");
	json towerJsons;
	towerFile >> towerJsons;
	for (json::iterator towerIt = towerJsons.begin(); towerIt != towerJsons.end(); ++towerIt) {
		Tower tower = Tower(towerIt.key(), towerIt.value());
		towers.push_back(tower);
	}
	return towers;
}