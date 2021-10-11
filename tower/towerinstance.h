#ifndef TOWER_INSTANCE
#define TOWER_INSTANCE
#include "tower.h"
class TowerInstance {
private:
	Tower tower;
	int moneySpent;
	int topTier;
	int midTier;
	int botTier;
public:
	TowerInstance(Tower);
};
#endif // !TOWER_INSTANCE
