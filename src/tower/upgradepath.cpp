#include "upgradepath.h"
#include <sstream>

UpgradePath::UpgradePath() :
	upgrades() {}

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

int UpgradePath::getNumberOfTiers() {
	return upgrades.size();
}

std::string UpgradePath::getStats() {
	std::ostringstream statStream{};
	for (int i = 0; i < upgrades.size(); i++) {
		statStream << "Tier " << i + 1 << ":" << std::endl;
		statStream << upgrades[i].getName() << " " << upgrades[i].getCost() << std::endl;
		for (std::vector<Buff*>::iterator buff = upgrades[i].getBuffs().begin();
				buff != upgrades[i].getBuffs().end(); ++buff) {
			statStream << **buff << std::endl;
		}
	}
	return statStream.str();
}