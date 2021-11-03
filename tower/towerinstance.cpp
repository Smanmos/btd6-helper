#include "towerinstance.h"

TowerInstance::TowerInstance(Tower tower) :
	tower(tower), moneySpent(tower.getCost()), upgrades() {}