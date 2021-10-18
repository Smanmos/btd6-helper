#include "upgrade.h"

Upgrade::Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
	int damageIncrease, int projectileIncrease) : cost(cost), 
	attackBuff(pierceIncrease, cooldownDecrease, damageIncrease, projectileIncrease) {}

Upgrade::Upgrade(json upgradeJson) : attackBuff(upgradeJson) {
	name = upgradeJson.at("name");
	cost = upgradeJson.at("cost");
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

std::string Upgrade::getName() {
	return name;
}

int Upgrade::getCost() {
	return cost;
}

bool Upgrade::isPierceIncreased() {
	return attackBuff.isPierceIncreased();
}

int Upgrade::getPierceIncrease() {
	return attackBuff.getPierceIncrease();
}

bool Upgrade::isCooldownDecreased() {
	return attackBuff.isCooldownDecreased();
}

double Upgrade::getCooldownDecrease() {
	return attackBuff.getCooldownDecrease();
}

bool Upgrade::isDamageIncreased() {
	return attackBuff.isDamageIncreased();
}

Damage Upgrade::getDamageIncrease() {
	return attackBuff.getDamageIncrease();
}

bool Upgrade::isProjectileIncreased() {
	return attackBuff.isProjectileIncreased();
}

int Upgrade::getProjectileIncrease() {
	return attackBuff.getProjectileIncrease();
}