#ifndef DAMAGE
#define DAMAGE
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class Damage {
	int dmg;
	int ceramicDmg;
	int moabDmg;
public:
	Damage(int dmg);
	Damage(int dmg, int ceramicDmg, int moabDmg);
	Damage(json damageJson);
};
#endif // !DAMAGE
