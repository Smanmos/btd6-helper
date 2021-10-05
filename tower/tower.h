#ifndef TOWER
#define TOWER
#include <string>
class Tower {
private:
	std::string name;
	int cost;
	double cooldown; // Attack speed
	int pierce;
	int damage;
	int numProjectiles;
public:
	Tower(std::string name, int cost, double cooldown, int pierce, int damage = 1, int numProjectiles = 1);
	double getDamagePerSecond();
	double getSingleTargetDps();
	double getCost();
};
#endif