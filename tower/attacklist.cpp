#include "attacklist.h"

AttackList::AttackList() : attacks(std::vector<Attack>()) {}

AttackList::AttackList(Attack attack) : attacks(std::vector<Attack>{attack}) {}

AttackList::AttackList(std::vector<Attack> attackVector) : attacks(attackVector) {}

AttackList::AttackList(AttackList& copy) : attacks(std::vector<Attack>(copy.attacks)) {}

void AttackList::add(Attack attack) {
	attacks.push_back(attack);
}

double AttackList::getTotalDps() {
	double dps = 0;
	for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
		dps += attack->getDamagePerSecond();
	}
	return dps;
}

AttackList AttackList::improve(Upgrade upgrade) {
	std::vector<Attack> upgradedAttacks;
	for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
		upgradedAttacks.push_back(attack->improve(upgrade));
	}
	return AttackList(upgradedAttacks);
}