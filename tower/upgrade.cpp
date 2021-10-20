#include "upgrade.h"

Upgrade::Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
	int damageIncrease, int projectileIncrease) : cost(cost) {
	internalBuff = new AttacksBuff(
		AttackBuff(pierceIncrease, cooldownDecrease, damageIncrease, projectileIncrease));
}

Upgrade::Upgrade(json upgradeJson) : internalBuff(new AttacksBuff(AttackBuff(upgradeJson))) {
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