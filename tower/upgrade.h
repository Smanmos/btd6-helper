#pragma once
#ifndef UPGRADE
#define UPGRADE
#include<nlohmann/json.hpp>
#include "damage.h"
#include "attackbuff.h"
using json = nlohmann::json;
class Upgrade {
	std::string name;
	int cost;
	AttackBuff attackBuff;
public:
	Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
		int damageIncrease, int projectileIncrease);
	Upgrade(json upgradeJson);
	std::string getName();
	int getCost();
	AttackBuff getBuff();
};
#endif // UPGRADE