#ifndef ATTACK_BUFF
#define ATTACK_BUFF
#include "tower/damage.h"
#include <nlohmann/json.hpp>
class AttackBuff {
	int pierceIncrease = 0;
	double reloadDecrease = 1.0;
	Damage damageIncrease = Damage(0);
	int projectileIncrease = 0;
public:
	AttackBuff(int, double, Damage, int);
	AttackBuff(json);
	bool isPierceIncreased();
	int getPierceIncrease();
	bool isReloadDecreased();
	double getReloadDecrease();
	bool isDamageIncreased();
	Damage getDamageIncrease();
	bool isProjectileIncreased();
	int getProjectileIncrease();
};
#endif // !ATTACK_BUFF
