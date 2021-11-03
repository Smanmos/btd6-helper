#ifndef ATTACK
#define ATTACK
#include <nlohmann/json.hpp>
#include "projectile.h"
using json = nlohmann::json;
class AttackBuilder;
class Attack {
	double cooldown;
	Projectile projectile;
	int numProjectiles;
public:
	Attack();
	Attack(std::string, double, int, Damage, int);
	Attack(double, Projectile, int);
	Attack(json);
	std::string getName();
	double getCooldown();
	int getPierce();
	Damage getDamage();
	int getBaseDamage();
	int getCeramicDamage();
	int getMoabDamage();
	int getNumProjectiles();
	double getDamagePerSecond();
	std::ostream& streamStats(std::ostream&);
	Attack improve(AttackBuff);
	Attack addSubProjOnHit(Projectile, int);
	Attack addSubProjOnExpire(Projectile, int);
	friend class AttackBuilder;
};
#endif // !ATTACK
