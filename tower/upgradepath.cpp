#include "upgradepath.h"

UpgradePath::UpgradePath(std::vector<Upgrade> upgrades) :
	upgrades(upgrades) {}

UpgradePath::UpgradePath(json upgradePathJson) {
	for (json::iterator upgrade = upgradePathJson.begin(); upgrade != upgradePathJson.end(); upgrade++) {
		upgrades.push_back(Upgrade(*upgrade));
	}
}

Upgrade UpgradePath::getTier(int index) {
	return upgrades[index-1];
}

Upgrade& UpgradePath::operator[](int index) {
	return upgrades[index];
}