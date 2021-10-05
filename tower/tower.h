#ifndef TOWER
#define TOWER
#include <string>
class Tower {
private:
	std::string name;
	double cooldown; // Attack speed
	int pierce;
	int damage;
	int numProjectiles;
public:
	Tower(std::string name, double cooldown, int pierce, int damage = 1, int numProjectiles = 1);
	double getDamagePerSecond();
};
#endif