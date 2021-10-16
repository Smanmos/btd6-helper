#ifndef DAMAGE
#define DAMAGE
#include <nlohmann/json.hpp>
#include <ostream>
using json = nlohmann::json;
class Damage {
	int base;
	int ceramic;
	int moab;
public:
	Damage();
	Damage(int base);
	Damage(int base, int ceramic, int moab);
	Damage(json damageJson);
	int getDamage();
	int getCeramicDamage();
	int getMoabDamage();
	bool isNonzero();
	Damage operator+(const Damage&);
	friend std::ostream& operator<<(std::ostream&, const Damage&);
};
#endif // !DAMAGE
