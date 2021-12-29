#include "ability.h"

Ability::Ability(std::string name, double cooldown) :
	name(name), cooldown(cooldown) {}

void Ability::printDetails(std::ostream& os) {
	os << "Ability " << name << ", cooldown " << cooldown << "s";
}

double Ability::getCooldown() {
	return cooldown;
}