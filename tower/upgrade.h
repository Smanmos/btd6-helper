#pragma once
#ifndef UPGRADE
#define UPGRADE
#include<nlohmann/json.hpp>
#include "damage.h"
#include "attacksbuff.h"
using json = nlohmann::json;
class Upgrade {
	std::string name;
	int cost;
	AttacksBuff attacksBuff;
public:
	Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
		int damageIncrease, int projectileIncrease);
	Upgrade(json upgradeJson);
	std::string getName();
	int getCost();
	AttacksBuff getBuff();
};
#endif // UPGRADE