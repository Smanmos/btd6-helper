#ifndef TOWER
#define TOWER
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "tower/difficulty.h"
#include "tower/attacklist.h"
#include "tower/upgrade.h"
#include "tower/upgradepath.h"
#include "tower/upgradepattern.h"
using json = nlohmann::json;
class TowerBuilder;

class Tower {
private:
	std::string name;
	int cost;
	AttackList attacks;
	UpgradePath topUpgrades;
	UpgradePath midUpgrades;
	UpgradePath botUpgrades;
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
	AttackList getAttacks(UpgradePattern);
	friend class TowerBuilder;
};
#endif