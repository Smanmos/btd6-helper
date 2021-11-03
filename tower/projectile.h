#ifndef PROJECTILE
#define PROJECTILE
#include "damage.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class Projectile {
	std::string name;
	Damage damage;
	int pierce;
	bool pierceExternalBuffable = true;
	bool damageExternalBuffable = true;
	Projectile* subProjOnHit = nullptr;
	int numSubProjOnHit = 0;
	Projectile* subProjOnExpire = nullptr;
	int numSubProjOnExpire = 0;
	Projectile(std::string name, Damage damage, int pierce, bool pierceExternalBuffable,
		bool damageExternalBuffable, Projectile* subProjOnHit, int numSubProjOnHit,
		Projectile* subProjOnExpire, int numSubProjOnExpire);
public:
	Projectile();
	Projectile(std::string, Damage, int);
	Projectile(json);
	friend std::ostream& operator<<(std::ostream& os, Projectile& proj);
	std::string getName();
	Damage getDamage();
	int getPierce();
	int getTotalDamage();
	Projectile* getProjectileOnHit();
	int getNumProjectileOnHit();
	Projectile* getProjectileOnExpire();
	int getNumProjectileOnExpire();
	Projectile addSubProjOnHit(Projectile, int);
	Projectile addSubProjOnExpire(Projectile, int);
};
#endif // !PROJECTILE
