#include "loader.h"
#include "tower/tower.h"
#include "tower/attackbuilder.h"

std::vector<Tower> loadTowers() {
	Attack dartAttack = AttackBuilder()
		.cooldown(0.95)
		.pierce(2)
		.build();
	Tower dartMonkey = Tower("Dart Monkey", 200, dartAttack);
	Attack boomerangAttack = AttackBuilder()
		.cooldown(1.2)
		.pierce(4)
		.build();
	Tower boomerangMonkey = Tower("Boomerang Monkey", 325, boomerangAttack);
	Attack bombAttack = AttackBuilder()
		.cooldown(1.4)
		.pierce(14)
		.build();
	Tower bombShooter = Tower("Bomb Shooter", 600, bombAttack);
	Attack tackAttack = AttackBuilder()
		.cooldown(1.4)
		.pierce(1)
		.projectiles(8)
		.build();
	Tower tackShooter = Tower("Tack Shooter", 280, tackAttack);
	std::vector<Tower> towers{ dartMonkey, boomerangMonkey, bombShooter, tackShooter };
	return towers;
}