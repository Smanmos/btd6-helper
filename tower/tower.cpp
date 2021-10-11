#include "tower.h"
#include <sstream>

Tower::Tower(std::string name, int cost, Attack attack) :
	name(name), cost(cost), attack(attack) {}

Tower::Tower(std::string name, json towerJson) :
	name(name), attack(Attack(towerJson["attack"])) {}

double Tower::getDamagePerSecond() {
	return attack.getPierce() * attack.getDamage() * attack.getNumProjectiles() / attack.getCooldown();
}

double Tower::getSingleTargetDps() {
	return attack.getDamage() * attack.getNumProjectiles() / attack.getCooldown();
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
	statStream << "Cooldown: " << attack.getCooldown() << std::endl;
	statStream << "Pierce: " << attack.getPierce() << std::endl;
	statStream << "Damage: " << attack.getDamage() << std::endl;
	statStream << "Projectiles: " << attack.getNumProjectiles() << std::endl;
	return statStream.str();
}
