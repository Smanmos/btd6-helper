#include "instantability.h"

InstantAbility::InstantAbility(json abilityJson) :
	Ability(abilityJson["name"], abilityJson["cooldown"]),
	projectile(abilityJson["projectile"]), numProjectiles(abilityJson["numProjectiles"]) {}
