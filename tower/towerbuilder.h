#ifndef TOWER_BUILDER
#define TOWER_BUILDER
#include "tower.h"
#include <string>
class TowerBuilder {
private:
	Tower tower;
public:
	TowerBuilder();
	TowerBuilder& name(std::string);
	TowerBuilder& cost(int);
	TowerBuilder& cooldown(double);
	TowerBuilder& pierce(int);
	TowerBuilder& damage(int);
	TowerBuilder& projectiles(int);
	Tower build();
};
#endif