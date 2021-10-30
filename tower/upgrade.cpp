#include "upgrade.h"

Upgrade::Upgrade(json upgradeJson) {
	name = upgradeJson.at("name");
	cost = upgradeJson.at("cost");
	for (json::iterator buff = upgradeJson["buffs"].begin(); buff != upgradeJson["buffs"].end(); ++buff) {
		internalBuffs.push_back(createBuff(*buff));
	}
}

std::string Upgrade::getName() {
	return name;
}

int Upgrade::getCost() {
	return cost;
}

std::vector<Buff*> Upgrade::getBuffs() {
	return internalBuffs;
}