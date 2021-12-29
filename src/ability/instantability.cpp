#include "instantability.h"

InstantAbility::InstantAbility(json abilityJson) :
	Ability(abilityJson["name"], abilityJson["cooldown"]),
	projectile(abilityJson["projectile"]), numProjectiles(abilityJson["numProjectiles"]) {}

void InstantAbility::printToOstream(std::ostream& os) {
	printDetails(os);
	os << ":" << std::endl;
	os << projectile;
	if (numProjectiles > 1) {
		os << "; " << numProjectiles << "j";
	}
	os << std::endl;
}
