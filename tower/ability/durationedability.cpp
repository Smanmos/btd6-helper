#include "durationedability.h"

DurationedAbility::DurationedAbility(json abilityJson) :
	Ability(abilityJson["name"], abilityJson["cooldown"]),
	duration(abilityJson["duration"]) {
	for (auto buffJson : abilityJson["buffs"]) {
		buffs.push_back(createBuff(buffJson));
	}
}