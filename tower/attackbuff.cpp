#include "attackbuff.h"

AttackBuff::AttackBuff(int pierceIncrease, double cooldownDecrease,
	Damage damageIncrease, int projectileIncrease) {
	this->pierceIncrease = pierceIncrease;
	this->cooldownDecrease = cooldownDecrease;
	this->damageIncrease = damageIncrease;
	this->projectileIncrease = projectileIncrease;
}

AttackBuff::AttackBuff(json buffJson) {
	pierceIncrease = buffJson.value("pierceIncrease", 0);
	cooldownDecrease = buffJson.value("cooldownDecrease", 1.0);
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

bool AttackBuff::isCooldownDecreased() {
	return cooldownDecrease != 1.0;
}

double AttackBuff::getCooldownDecrease() {
	return cooldownDecrease;
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