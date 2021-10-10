#include "loader.h"
#include "tower/towerbuilder.h"

std::vector<Tower> loadTowers() {
	Tower dartMonkey = TowerBuilder()
		.name("Dart Monkey")
		.cost(200)
		.cooldown(0.95)
		.pierce(2)
		.build();
	Tower boomerangMonkey = TowerBuilder()
		.name("Boomerang Monkey")
		.cost(325)
		.cooldown(1.2)
		.pierce(4)
		.build();
	Tower tackShooter = TowerBuilder()
		.name("Tack Shooter")
		.cost(280)
		.cooldown(1.4)
		.pierce(1)
		.projectiles(8)
		.build();
	std::vector<Tower> towers{ dartMonkey, boomerangMonkey, tackShooter };
	return towers;
}