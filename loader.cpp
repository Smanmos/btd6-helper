#include "loader.h"

std::vector<Tower> loadTowers() {
	Tower dartMonkey = Tower(std::string("Dart Monkey"), 200, 0.95, 2);
	Tower boomerangMonkey = Tower(std::string("Boomerang Monkey"), 325, 1.2, 4);
	Tower tackShooter = Tower(std::string("Tack Shooter"), 280, 1.4, 1, 1, 8);
	std::vector<Tower> TOWERS{ dartMonkey, boomerangMonkey, tackShooter };
}