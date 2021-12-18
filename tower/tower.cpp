#include "tower.h"
#include <sstream>

Tower::Tower(std::string name, int cost, Attack attack) :
	name(name), cost(cost), attacks(attack) {}

Tower::Tower(std::string name, json towerJson) :
		name(name), cost(towerJson.at("cost").get<int>()), attacks(Attack(towerJson.at("attack"))) {
	topUpgrades = UpgradePath(towerJson.value("topUpgrades", json::array()));
	midUpgrades = UpgradePath(towerJson.value("midUpgrades", json::array()));
	botUpgrades = UpgradePath(towerJson.value("botUpgrades", json::array()));
}

Tower::Tower(const Tower& tower) :
		name(tower.name), cost(tower.cost), topUpgrades(tower.topUpgrades), 
		midUpgrades(tower.midUpgrades), botUpgrades(tower.botUpgrades) {
	attacks = tower.attacks;
}

double Tower::getDamagePerSecond() {
	return attacks.getTotalDps();
}

double Tower::getDamagePerSecond(UpgradePattern upgradePattern) {
	AttackList upgradedAttacks = getAttacks(upgradePattern);
	return upgradedAttacks.getTotalDps();
}

double Tower::getSingleTargetDps() {
	return 0;
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

AttackList Tower::getAttacks(UpgradePattern upgradePattern) {
	if (upgradePattern.top > topUpgrades.getNumberOfTiers()
		|| upgradePattern.mid > midUpgrades.getNumberOfTiers()
		|| upgradePattern.bot > botUpgrades.getNumberOfTiers()) {
		throw std::invalid_argument(name + "does not have that many upgrades");
	}
	AttackList upgradedAttacks = attacks;
	for (int i = 0; i < upgradePattern.top; i++) {
		std::vector<Buff*> topBuffs = topUpgrades[i].getBuffs();
		for (std::vector<Buff*>::iterator topBuff = topBuffs.begin(); topBuff != topBuffs.end(); ++topBuff) {
			upgradedAttacks = (*topBuff)->buff(upgradedAttacks);
		}
	}
	for (int i = 0; i < upgradePattern.mid; i++) {
		std::vector<Buff*> midBuffs = midUpgrades[i].getBuffs();
		for (std::vector<Buff*>::iterator midBuff = midBuffs.begin(); midBuff != midBuffs.end(); ++midBuff) {
			upgradedAttacks = (*midBuff)->buff(upgradedAttacks);
		}
	}
	for (int i = 0; i < upgradePattern.bot; i++) {
		std::vector<Buff*> botBuffs = botUpgrades[i].getBuffs();
		for (std::vector<Buff*>::iterator botBuff = botBuffs.begin(); botBuff != botBuffs.end(); ++botBuff) {
			upgradedAttacks = (*botBuff)->buff(upgradedAttacks);
		}
	}
	return upgradedAttacks;
}

std::string Tower::getStats() {
	std::ostringstream statStream = std::ostringstream();
	statStream << "Cost: " << cost << std::endl;
	attacks.streamStats(statStream);
	statStream << "Top Path:" << std::endl;
	statStream << topUpgrades.getStats() << std::endl;
	statStream << "Mid Path:" << std::endl;
	statStream << midUpgrades.getStats() << std::endl;
	statStream << "Bottom Path:" << std::endl;
	statStream << botUpgrades.getStats() << std::endl;
	return statStream.str();
}

std::string Tower::getStats(UpgradePattern upgradePattern) {
	std::ostringstream statStream = std::ostringstream();
	AttackList upgradedAttacks = getAttacks(upgradePattern);
	int totalCost = cost;
	for (int i = 0; i < upgradePattern.top; i++) {
		totalCost += topUpgrades[i].getCost();
	}
	for (int i = 0; i < upgradePattern.mid; i++) {
		totalCost += midUpgrades[i].getCost();
	}
	for (int i = 0; i < upgradePattern.bot; i++) {
		totalCost += botUpgrades[i].getCost();
	}
	statStream << "Cost: " << totalCost << std::endl;
	upgradedAttacks.streamStats(statStream);
	return statStream.str();
}