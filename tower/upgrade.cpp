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
	pierceIncrease = upgradeJson.value("pierceIncrease", 0);
	cooldownDecrease = upgradeJson.value("cooldownDecrease", 1.0);
	if (upgradeJson.contains("damageIncrease")) {
		damageIncrease = upgradeJson.at("damageIncrease");
	}
	projectileIncrease = upgradeJson.value("projectileIncrease", 0);
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
	return pierceIncrease != 0;
}

int Upgrade::getPierceIncrease() {
	return pierceIncrease;
}

bool Upgrade::isCooldownDecreased() {
	return cooldownDecrease != 1.0;
}

double Upgrade::getCooldownDecrease() {
	return cooldownDecrease;
}

bool Upgrade::isDamageIncreased() {
	return damageIncrease.isNonzero();
}

Damage Upgrade::getDamageIncrease() {
	return damageIncrease;
}

bool Upgrade::isProjectileIncreased() {
	return projectileIncrease != 0;
}

int Upgrade::getProjectileIncrease() {
	return projectileIncrease;
}