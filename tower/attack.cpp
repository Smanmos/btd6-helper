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
	cooldown = attackJson.at("cooldown").get<double>();
	pierce = attackJson.value("pierce", 1);
	damage = attackJson.value("damage", 1);
	numProjectiles = attackJson.value("numProjectiles", 1);
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