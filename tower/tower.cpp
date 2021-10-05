#include "tower.h"

Tower::Tower(std::string name, int cost, double cooldown, int pierce, int damage, int numProjectiles) :
	name(name), cost(cost), cooldown(cooldown), pierce(pierce), damage(damage), numProjectiles(numProjectiles) {}

double Tower::getDamagePerSecond() {
	return pierce * damage * numProjectiles / cooldown;
}

double Tower::getSingleTargetDps() {
	return damage * numProjectiles / cooldown;
}

double Tower::getCost() {
	return cost;
}

std::string Tower::getName() {
	return name;
}