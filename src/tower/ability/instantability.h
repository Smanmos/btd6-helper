#ifndef INSTANT_ABILITY
#define INSTANT_ABILITY
#include "ability.h"
#include "tower/projectile.h"
class InstantAbility : public Ability {
	Projectile projectile;
	int numProjectiles;
	void printToOstream(std::ostream&);
public:
	InstantAbility(json abilityJson);
};
#endif