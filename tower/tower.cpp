#include "tower.h"
#include <sstream>

Tower::Tower(std::string name, int cost, Attack attack) :
	name(name), cost(cost), attack(attack) {}

Tower::Tower(std::string name, json towerJson) :
		name(name), cost(towerJson.at("cost").get<int>()), attack(Attack(towerJson.at("attack"))) {
	json topUpgradesJson = towerJson.value("topUpgrades", json::array());
	for (auto topUpgrade = topUpgradesJson.begin(); topUpgrade != topUpgradesJson.end(); ++topUpgrade) {
		topUpgrades.push_back(Upgrade(*topUpgrade));
	}
	json midUpgradesJson = towerJson.value("midUpgrades", json::array());
	for (auto midUpgrade = midUpgradesJson.begin(); midUpgrade != midUpgradesJson.end(); ++midUpgrade) {
		midUpgrades.push_back(Upgrade(*midUpgrade));
	}
	json botUpgradesJson = towerJson.value("botUpgrades", json::array());
	for (auto botUpgrade = botUpgradesJson.begin(); botUpgrade != botUpgradesJson.end(); ++botUpgrade) {
		botUpgrades.push_back(Upgrade(*botUpgrade));
	}
}

double Tower::getDamagePerSecond() {
	return attack.getPierce() * attack.getDamage() * attack.getNumProjectiles() / attack.getCooldown();
}

double Tower::getSingleTargetDps() {
	return attack.getDamage() * attack.getNumProjectiles() / attack.getCooldown();
}

int Tower::getCost() {
	return cost;
}

int roundToNearestFive(int value) {
	return (value + 2) / 5 * 5;
}

int Tower::getCost(Difficulty difficulty) {
	int raw_cost = int(cost * DIFFICULTY_MULTIPLIERS[difficulty]);
	return roundToNearestFive(raw_cost);
}

std::string Tower::getName() {
	return name;
}

bool Tower::matches(std::string str) {
	std::istringstream iss(name);
	std::string token;
	while (iss >> token) {
		if (str.length() == token.length()) {
			int len = str.length();
			bool matches = true;
			for (int i = 0; i < len; i++) {
				if (tolower(str[i]) != tolower(token[i])) {
					matches = false;
					break;
				}
			}
			if (matches) {
				return true;
			}
		}
	}
	return false;
}

std::string Tower::getUpgradePathStats(char initial, std::vector<Upgrade>& upgrades) {
	std::ostringstream statStream{};
	for (int i = 0; i < upgrades.size(); i++) {
		statStream << initial << i + 1 << ":" << std::endl;
		statStream << upgrades[i].getName() << " " << upgrades[i].getCost() << std::endl;
		if (upgrades[i].isCooldownDecreased()) {
			statStream << upgrades[i].getCooldownDecrease() << "s" << std::endl;
		}
		if (upgrades[i].isPierceIncreased()) {
			statStream << "+" << upgrades[i].getPierceIncrease() << "p" << std::endl;
		}
		if (upgrades[i].isDamageIncreased()) {
			statStream << "+" << upgrades[i].getDamageIncrease() << "d" << std::endl;
		}
		if (upgrades[i].isProjectileIncreased()) {
			statStream << "+" << upgrades[i].getProjectileIncrease() << "j" << std::endl;
		}
	}
	return statStream.str();
}

std::string Tower::getTopUpgradeStats() {
	return getUpgradePathStats('T', topUpgrades);
}

std::string Tower::getMidUpgradeStats() {
	return getUpgradePathStats('M', midUpgrades);
}

std::string Tower::getBotUpgradeStats() {
	return getUpgradePathStats('B', botUpgrades);
}

std::string Tower::getStats() {
	std::ostringstream statStream = std::ostringstream();
	statStream << "Cost: " << cost << std::endl;
	statStream << "Cooldown: " << attack.getCooldown() << std::endl;
	statStream << "Pierce: " << attack.getPierce() << std::endl;
	statStream << "Damage: " << attack.getDamage() << std::endl;
	statStream << "Projectiles: " << attack.getNumProjectiles() << std::endl;
	statStream << getTopUpgradeStats();
	statStream << getMidUpgradeStats();
	statStream << getBotUpgradeStats();
	return statStream.str();
}
