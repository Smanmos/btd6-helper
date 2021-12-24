#ifndef INSTANT_ABILITY
#define INSTANT_ABILITY
#include "ability.h"
#include "tower/projectile.h"
class InstantAbility : public Ability {
	Projectile projectile;
	int numProjectiles;
public:
	InstantAbility(json abilityJson);
};
#endif