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
	Buff* internalBuff;
public:
	Upgrade(json upgradeJson);
	std::string getName();
	int getCost();
	Buff* getBuff();
};
#endif // UPGRADE