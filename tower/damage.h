#ifndef DAMAGE
#define DAMAGE
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class Damage {
	int base;
	int ceramic;
	int moab;
public:
	Damage(int base);
	Damage(int base, int ceramic, int moab);
	Damage(json damageJson);
	int getDamage();
	int getCeramicDamage();
	int getMoabDamage();
};
#endif // !DAMAGE
