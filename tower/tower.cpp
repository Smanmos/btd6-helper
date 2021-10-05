#include "tower.h"

Tower::Tower(std::string name, double cooldown, int pierce, int damage, int numProjectiles) :
	name(name), cooldown(cooldown), pierce(pierce), damage(damage), numProjectiles(numProjectiles) {}

double Tower::getDamagePerSecond() {
	return pierce * damage * numProjectiles / cooldown;
}
