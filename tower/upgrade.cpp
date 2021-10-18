#include "upgrade.h"

Upgrade::Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
	int damageIncrease, int projectileIncrease) : cost(cost), 
	attacksBuff(AttackBuff(pierceIncrease, cooldownDecrease, damageIncrease, projectileIncrease)) {}

Upgrade::Upgrade(json upgradeJson) : attacksBuff(upgradeJson) {
	name = upgradeJson.at("name");
	cost = upgradeJson.at("cost");
}

std::string Upgrade::getName() {
	return name;
}

int Upgrade::getCost() {
	return cost;
}

AttacksBuff Upgrade::getBuff() {
	return attacksBuff;
}