#include "attack.h"

Attack::Attack() {
	cooldown = 1.0;
	pierce = 1;
	damage = 1;
	numProjectiles = 1;
}

Attack::Attack(double cooldown, int pierce, int damage, int numProjectiles) :
	cooldown(cooldown), pierce(pierce), damage(damage), numProjectiles(numProjectiles) {}

Attack::Attack(json attackJson) {
	cooldown = attackJson["cooldown"].get<double>();
	pierce = attackJson.contains("pierce") ? attackJson["pierce"].get<int>() : 1;
	damage = attackJson.contains("damage") ? attackJson["damage"].get<int>() : 1;
	numProjectiles = attackJson.contains("numProjectiles") ? attackJson["numProjectiles"].get<int>() : 1;
}

double Attack::getCooldown() {
	return cooldown;
}

int Attack::getPierce() {
	return pierce;
}

int Attack::getDamage() {
	return damage;
}

int Attack::getNumProjectiles() {
	return numProjectiles;
}