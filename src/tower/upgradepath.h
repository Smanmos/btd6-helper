#ifndef UPGRADE_PATH
#define UPGRADE_PATH
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "tower/upgrade.h"
class UpgradePath {
private:
	std::vector<Upgrade> upgrades;
public:
	UpgradePath();
	UpgradePath(json upgradePathJson);
	UpgradePath(std::vector<Upgrade> upgrades);
	Upgrade getTier(int tier);
	Upgrade& operator[](int index);
	int getNumberOfTiers();
	std::string getStats();
};
#endif
