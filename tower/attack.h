#ifndef ATTACK
#define ATTACK
#include <nlohmann/json.hpp>
#include "damage.h"
using json = nlohmann::json;
class AttackBuilder;
class Attack {
	double cooldown;
	int pierce;
	Damage damage;
	int numProjectiles;
public:
	Attack();
	Attack(double, int, int, int);
	Attack(json);
	double getCooldown();
	int getPierce();
	Damage getDamage();
	int getNumProjectiles();
	friend class AttackBuilder;
};
#endif // !ATTACK
