#include "towerbuilder.h"

TowerBuilder::TowerBuilder() {
	tower = Tower();
}

TowerBuilder& TowerBuilder::name(std::string name) {
	tower.name = name;
	return *this;
}

TowerBuilder& TowerBuilder::cost(int cost) {
	tower.cost = cost;
	return *this;
}

TowerBuilder& TowerBuilder::cooldown(double cooldown) {
	tower.cooldown = cooldown;
	return *this;
}

TowerBuilder& TowerBuilder::pierce(int pierce) {
	tower.pierce = pierce;
	return *this;
}

TowerBuilder& TowerBuilder::damage(int damage) {
	tower.damage = damage;
	return *this;
}

TowerBuilder& TowerBuilder::projectiles(int numProjectiles) {
	tower.numProjectiles = numProjectiles;
	return *this;
}

Tower TowerBuilder::build() {
	return tower;
}