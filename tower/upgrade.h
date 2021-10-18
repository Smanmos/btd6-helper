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
	static Upgrade ofPierceUpgrade(int cost, int pierceIncrease);
	static Upgrade ofCooldownUpgrade(int cost, double cooldownDecrease);
	static Upgrade ofDamageUpgrade(int cost, int damageIncrease);
	static Upgrade ofProjectileUpgrade(int cost, int projectileIncrease);
	std::string getName();
	int getCost();
	bool isPierceIncreased();
	int getPierceIncrease();
	bool isCooldownDecreased();
	double getCooldownDecrease();
	bool isDamageIncreased();
	Damage getDamageIncrease();
	bool isProjectileIncreased();
	int getProjectileIncrease();
};
#endif // UPGRADE