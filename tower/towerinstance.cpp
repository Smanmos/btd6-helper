#include "towerinstance.h"

TowerInstance::TowerInstance(Tower tower) :
	tower(tower), moneySpent(tower.getCost()), topTier(0), midTier(0), botTier(0) {}