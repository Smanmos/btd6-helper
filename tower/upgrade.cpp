#include "upgrade.h"

Upgrade::Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
	int damageIncrease, int projectileIncrease) : cost(cost), 
	attackBuff(pierceIncrease, cooldownDecrease, damageIncrease, projectileIncrease) {}

Upgrade::Upgrade(json upgradeJson) : attackBuff(upgradeJson) {
	name = upgradeJson.at("name");
	cost = upgradeJson.at("cost");
}

std::string Upgrade::getName() {
	return name;
}

int Upgrade::getCost() {
	return cost;
}

AttackBuff Upgrade::getBuff() {
	return attackBuff;
}