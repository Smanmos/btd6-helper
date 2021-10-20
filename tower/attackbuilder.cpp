#include "attackbuilder.h"
#include <stdexcept>

AttackBuilder::AttackBuilder() :
	p(1), d(1), j(1), isCooldownSet(false) { }

AttackBuilder& AttackBuilder::cooldown(double cooldown) {
	cd = cooldown;
	isCooldownSet = true;
	return *this;
}

AttackBuilder& AttackBuilder::pierce(int pierce) {
	p = pierce;
	return *this;
}

AttackBuilder& AttackBuilder::damage(int damage) {
	d = damage;
	return *this;
}

AttackBuilder& AttackBuilder::projectiles(int numProjectiles) {
	j = numProjectiles;
	return *this;
}

Attack AttackBuilder::build() {
	if (!isCooldownSet) {
		throw std::invalid_argument("Cooldown must be set");
	}
	return Attack("", cd, p, d, j);
}

