#ifndef ATTACK
#define ATTACK
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class AttackBuilder;
class Attack {
	double cooldown;
	int pierce;
	int damage;
	int numProjectiles;
public:
	Attack();
	Attack(double, int, int, int);
	Attack(json);
	double getCooldown();
	int getPierce();
	int getDamage();
	int getNumProjectiles();
	friend class AttackBuilder;
};
#endif // !ATTACK
