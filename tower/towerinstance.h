#ifndef TOWER_INSTANCE
#define TOWER_INSTANCE
#include "tower.h"
class TowerInstance {
private:
	Tower tower;
	int moneySpent;
	UpgradePattern upgrades;
public:
	TowerInstance(Tower);
	TowerInstance(Tower, UpgradePattern);
};
#endif // !TOWER_INSTANCE
