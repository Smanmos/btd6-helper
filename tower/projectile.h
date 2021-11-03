#ifndef PROJECTILE
#define PROJECTILE
#include "damage.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class Projectile {
	Damage damage;
	int pierce;
	bool pierceExternalBuffable = true;
	bool damageExternalBuffable = true;
	Projectile* subProjOnHit = nullptr;
	int numSubProjOnHit = 0;
	Projectile* subProjOnExpire = nullptr;
	int numSubProjOnExpire = 0;
public:
	Projectile(Damage, int);
	Projectile(json);
	friend std::ostream& operator<<(std::ostream& os, Projectile& proj);
	Damage getDamage();
	int getPierce();
	int getTotalDamage();
};
#endif // !PROJECTILE
