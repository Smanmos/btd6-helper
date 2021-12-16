#include "attackbuilder.h"
#include <stdexcept>

AttackBuilder::AttackBuilder() :
	p(1), d(1), j(1), isReloadSet(false) { }

AttackBuilder& AttackBuilder::reload(double reload) {
	r = reload;
	isReloadSet = true;
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
	if (!isReloadSet) {
		throw std::invalid_argument("Reload must be set");
	}
	return Attack("", r, p, d, j);
}

