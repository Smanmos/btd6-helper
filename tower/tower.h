#ifndef TOWER
#define TOWER
#include <string>
#include "../difficulty.h"
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
	int getCost();
	int getCost(Difficulty diff);
	std::string getName();
};
#endif