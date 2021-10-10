#ifndef TOWER
#define TOWER
#include <string>
#include <vector>
#include "difficulty.h"
#include "attack.h"
class TowerBuilder;

class Tower {
private:
	std::string name;
	int cost;
	Attack attack;
public:
	Tower(std::string name, int cost, Attack attack);
	double getDamagePerSecond();
	double getSingleTargetDps();
	int getCost();
	int getCost(Difficulty diff);
	std::string getName();
	std::string getStats();
	friend class TowerBuilder;
};
#endif