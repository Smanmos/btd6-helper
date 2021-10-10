#include "tower.h"
#include <sstream>

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

std::string Tower::getStats() {
	std::ostringstream statStream = std::ostringstream();
	statStream << "Cost: " << cost << std::endl;
	statStream << "Cooldown: " << cooldown << std::endl;
	statStream << "Pierce: " << pierce << std::endl;
	statStream << "Damage: " << damage << std::endl;
	statStream << "Projectiles: " << numProjectiles << std::endl;
	return statStream.str();
}

Tower dartMonkey = Tower(std::string("Dart Monkey"), 200, 0.95, 2);
Tower boomerangMonkey = Tower(std::string("Boomerang Monkey"), 325, 1.2, 4);
Tower tackShooter = Tower(std::string("Tack Shooter"), 280, 1.4, 1, 1, 8);
std::vector<Tower> TOWERS{dartMonkey, boomerangMonkey};