#ifndef TOWER
#define TOWER
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "difficulty.h"
#include "attack.h"
#include "upgrade/upgrade.h"
using json = nlohmann::json;
class TowerBuilder;

class Tower {
private:
	std::string name;
	int cost;
	Attack attack;
	std::vector<Upgrade> topUpgrades;
	std::vector<Upgrade> midUpgrades;
	std::vector<Upgrade> botUpgrades;
	std::string getUpgradePathStats(char initial, std::vector<Upgrade> &upgrades);
	std::string getTopUpgradeStats();
	std::string getMidUpgradeStats();
	std::string getBotUpgradeStats();
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