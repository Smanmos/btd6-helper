#include "damage.h"

Damage::Damage() : Damage(0) {}

Damage::Damage(int base) : base(base), ceramic(0), moab(0) {}

Damage::Damage(int base, int ceramic, int moab) :
	base(base), ceramic(ceramic), moab(moab) {}

Damage::Damage(json damageJson) {
	base = damageJson.at("base");
	ceramic = damageJson.value("ceramic", 0);
	moab = damageJson.value("moab", 0);
}

int Damage::getDamage() {
	return base;
}

int Damage::getCeramicDamage() {
	return base + ceramic;
}

int Damage::getMoabDamage() {
	return base + moab;
}

std::ostream& operator<<(std::ostream& os, const Damage& damage) {
	os << damage.base + "d";
	if (damage.ceramic > 0) {
		os << ", +" << damage.ceramic << "cd (" << damage.base + damage.ceramic << ")";
	}
	if (damage.moab > 0) {
		os << ", +" << damage.moab << "md (" << damage.base + damage.moab << ")";
	}
	return os;
}