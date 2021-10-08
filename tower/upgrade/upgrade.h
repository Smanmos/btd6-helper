#pragma once
#ifndef UPGRADE
#define UPGRADE
class Upgrade {
	int cost;
	int pierceIncrease = 0;
	double cooldownDecrease = 1.0;
	int damageIncrease = 0;
	int projectileIncrease = 0;
public:
	Upgrade(int cost, int pierceIncrease, double cooldownDecrease,
		int damageIncrease, int projectileIncrease);
	static Upgrade ofPierceUpgrade(int cost, int pierceIncrease);
	static Upgrade ofCooldownUpgrade(int cost, double cooldownDecrease);
	static Upgrade ofDamageUpgrade(int cost, int damageIncrease);
	static Upgrade ofProjectileUpgrade(int cost, int projectileIncrease);
};
#endif // UPGRADE