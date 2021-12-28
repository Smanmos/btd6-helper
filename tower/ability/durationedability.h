#ifndef DURATIONED_ABILITY
#define DURATIONED_ABILITY
#include "ability.h"
#include "tower/buff.h"
class DurationedAbility : public Ability {
	double duration;
	std::vector<Buff*> buffs;
public:
	DurationedAbility(json abilityJson);
};
#endif // !DURATIONED_ABILITY
