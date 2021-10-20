#include "upgrade.h"

Upgrade::Upgrade(json upgradeJson) : internalBuff(createBuff(upgradeJson)) {
	name = upgradeJson.at("name");
	cost = upgradeJson.at("cost");
}

std::string Upgrade::getName() {
	return name;
}

int Upgrade::getCost() {
	return cost;
}

Buff* Upgrade::getBuff() {
	return internalBuff;
}