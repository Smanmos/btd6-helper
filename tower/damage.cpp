#include "damage.h"

Damage::Damage(int base) : base(base), ceramic(0), moab(0) {}

Damage::Damage(int base, int ceramic, int moab) :
	base(base), ceramic(ceramic), moab(moab) {}

Damage::Damage(json damageJson) {
	base = damageJson.at("base");
	ceramic = damageJson.value("ceramic", 0);
	moab = damageJson.value("moab", 0);
}