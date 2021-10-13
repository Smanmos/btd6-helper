#include "upgrade.h"

Upgrade::Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
	int damageIncrease, int projectileIncrease) {
	this->cost = cost;
	this->pierceIncrease = pierceIncrease;
	this->cooldownDecrease = cooldownDecrease;
	this->damageIncrease = damageIncrease;
	this->projectileIncrease = projectileIncrease;
}

Upgrade::Upgrade(json upgradeJson) {
	name = upgradeJson.at("name");
	cost = upgradeJson.at("cost");
	pierceIncrease = upgradeJson.value("pierce", 0);
	cooldownDecrease = upgradeJson.value("cooldown", 1.0);
	damageIncrease = upgradeJson.value("damage", 0);
	projectileIncrease = upgradeJson.value("numProjectile", 0);
}

Upgrade Upgrade::ofPierceUpgrade(int cost, int pierceIncrease) {
	return Upgrade(cost, pierceIncrease, 1.0, 0, 0);
}

Upgrade Upgrade::ofCooldownUpgrade(int cost, double cooldownDecrease) {
	return Upgrade(cost, 0, cooldownDecrease, 0, 0);
}

Upgrade Upgrade::ofDamageUpgrade(int cost, int damageIncrease) {
	return Upgrade(cost, 0, 1.0, damageIncrease, 0);
}

Upgrade Upgrade::ofProjectileUpgrade(int cost, int projectileIncrease) {
	return Upgrade(cost, 0, 1.0, 0, projectileIncrease);
}