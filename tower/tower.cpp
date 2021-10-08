#include "tower.h"

Tower::Tower(std::string name, int cost, double cooldown, int pierce, int damage, int numProjectiles) :
	name(name), cost(cost), cooldown(cooldown), pierce(pierce), damage(damage), numProjectiles(numProjectiles) {}

double Tower::getDamagePerSecond() {
	return pierce * damage * numProjectiles / cooldown;
}

double Tower::getSingleTargetDps() {
	return damage * numProjectiles / cooldown;
}

int Tower::getCost() {
	return cost;
}

int roundToNearestFive(int value) {
	return (value + 2) / 5 * 5;
}

int Tower::getCost(Difficulty difficulty) {
	int raw_cost = int(cost * DIFFICULTY_MULTIPLIERS[difficulty]);
	return roundToNearestFive(raw_cost);
}

std::string Tower::getName() {
	return name;
}

Tower dartMonkey = Tower(std::string("Dart Monkey"), 200, 0.95, 2);
std::vector<Tower> TOWERS{dartMonkey};