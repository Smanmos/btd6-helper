#pragma once
#ifndef UPGRADE
#define UPGRADE
#include<nlohmann/json.hpp>
#include "tower/damage.h"
#include "buff/attacksbuff.h"
using json = nlohmann::json;
class Upgrade {
	std::string name;
	int cost;
	std::vector<Buff*> internalBuffs;
public:
	Upgrade(json upgradeJson);
	std::string getName();
	int getCost();
	std::vector<Buff*> getBuffs();
};
#endif // UPGRADE