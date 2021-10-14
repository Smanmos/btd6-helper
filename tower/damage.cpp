#include "damage.h"

Damage::Damage(int dmg) : dmg(dmg), ceramicDmg(0), moabDmg(0) {}

Damage::Damage(int dmg, int ceramicDmg, int moabDmg) :
	dmg(dmg), ceramicDmg(ceramicDmg), moabDmg(moabDmg) {}

Damage::Damage(json damageJson) {
	dmg = damageJson.at("dmg");
	ceramicDmg = damageJson.value("ceramic", 0);
	moabDmg = damageJson.value("moab", 0);
}