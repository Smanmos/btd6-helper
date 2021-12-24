#include "ability.h"

Ability::Ability(std::string name, double cooldown) :
	name(name), cooldown(cooldown) {}

double Ability::getCooldown() {
	return cooldown;
}