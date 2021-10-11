#ifndef TOWER
#define TOWER
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "difficulty.h"
#include "attack.h"
using json = nlohmann::json;
class TowerBuilder;

class Tower {
private:
	std::string name;
	int cost;
	Attack attack;
public:
	Tower(std::string name, int cost, Attack attack);
	Tower(std::string name, json towerJson);
	double getDamagePerSecond();
	double getSingleTargetDps();
	int getCost();
	int getCost(Difficulty diff);
	std::string getName();
	std::string getStats();
	friend class TowerBuilder;
};
#endif