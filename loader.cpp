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
	Attack bullet = AttackBuilder()
		.cooldown(1.59)
		.damage(2)
		.build();
	Tower sniperMonkey = Tower("Sniper Monkey", 350, bullet);
	Attack subDart = AttackBuilder()
		.cooldown(0.75)
		.pierce(2)
		.build();
	Tower monkeySub = Tower("Monkey Sub", 325, subDart);
	Attack boatDart = AttackBuilder().cooldown(1.0).pierce(4).projectiles(2).build();
	Tower monkeyBuccaneer = Tower("Monkey Buccaneer", 500, boatDart);
	Attack aceDart = AttackBuilder().cooldown(1.68).pierce(5).projectiles(8).build();
	Tower monkeyAce = Tower("Monkey Ace", 800, aceDart);
	Attack heliDart = AttackBuilder().cooldown(0.57).pierce(3).projectiles(2).build();
	Tower heliPilot = Tower("Heli Pilot", 1600, heliDart);
	Attack shell = AttackBuilder().cooldown(2.0).pierce(40).build();
	Tower mortarMonkey = Tower("Mortar Monkey", 750, shell);
	std::vector<Tower> towers{ dartMonkey, boomerangMonkey, bombShooter, tackShooter, sniperMonkey, 
			monkeySub, monkeyBuccaneer, monkeyAce, heliPilot, mortarMonkey};
	return towers;
}