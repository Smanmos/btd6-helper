#include "attackbuff.h"

AttackBuff::AttackBuff(int pierceIncrease, double reloadDecrease,
	Damage damageIncrease, int projectileIncrease) {
	this->pierceIncrease = pierceIncrease;
	this->reloadDecrease = reloadDecrease;
	this->damageIncrease = damageIncrease;
	this->projectileIncrease = projectileIncrease;
}

AttackBuff::AttackBuff(json buffJson) {
	pierceIncrease = buffJson.value("pierceIncrease", 0);
	reloadDecrease = buffJson.value("reloadDecrease", 1.0);
	if (buffJson.contains("damageIncrease")) {
		damageIncrease = buffJson.at("damageIncrease");
	}
	projectileIncrease = buffJson.value("projectileIncrease", 0);
}

bool AttackBuff::isPierceIncreased() {
	return pierceIncrease != 0;
}

int AttackBuff::getPierceIncrease() {
	return pierceIncrease;
}

bool AttackBuff::isReloadDecreased() {
	return reloadDecrease != 1.0;
}

double AttackBuff::getReloadDecrease() {
	return reloadDecrease;
}

bool AttackBuff::isDamageIncreased() {
	return damageIncrease.isNonzero();
}

Damage AttackBuff::getDamageIncrease() {
	return damageIncrease;
}

bool AttackBuff::isProjectileIncreased() {
	return projectileIncrease != 0;
}

int AttackBuff::getProjectileIncrease() {
	return projectileIncrease;
}