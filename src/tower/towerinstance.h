#ifndef TOWER_INSTANCE
#define TOWER_INSTANCE
#include "tower/tower.h"
class TowerInstance {
private:
	Tower tower;
	int moneySpent;
	AttackList attacks;
	std::vector<AttackBuff> buffs;
	UpgradePattern upgrades;
public:
	TowerInstance(Tower);
	TowerInstance(Tower, UpgradePattern);
};
#endif // !TOWER_INSTANCE
