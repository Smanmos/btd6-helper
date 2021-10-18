#ifndef TOWER
#define TOWER
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "difficulty.h"
#include "attacklist.h"
#include "upgrade.h"
#include "upgradepattern.h"
using json = nlohmann::json;
class TowerBuilder;

class Tower {
private:
	std::string name;
	int cost;
	AttackList attacks;
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
	Tower(const Tower&);
	double getDamagePerSecond();
	double getDamagePerSecond(UpgradePattern);
	double getSingleTargetDps();
	int getCost();
	int getCost(Difficulty diff);
	std::string getName();
	bool matches(std::string);
	std::string getStats();
	std::string getStats(UpgradePattern);
	friend class TowerBuilder;
};
#endif