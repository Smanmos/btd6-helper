#include "attacklist.h"

AttackList::AttackList() : attacks(std::vector<Attack>()) {}

AttackList::AttackList(Attack attack) : attacks(std::vector<Attack>{attack}) {}

AttackList::AttackList(std::vector<Attack> attackVector) : attacks(attackVector) {}

AttackList::AttackList(std::vector<Attack> attackVector, std::vector<AttackBuff> buffs) : 
	attacks(attackVector), appliedBuffs(buffs) {}

AttackList::AttackList(AttackList& copy) : 
	attacks(copy.attacks), appliedBuffs(copy.appliedBuffs){}

void AttackList::add(Attack attack) {
	Attack upgradedAttack = attack;
	for (auto buff = appliedBuffs.begin(); buff != appliedBuffs.end(); ++buff) {
		upgradedAttack = upgradedAttack.improve(*buff);
	}
	attacks.push_back(upgradedAttack);
}

double AttackList::getTotalDps() {
	double dps = 0;
	for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
		dps += attack->getDamagePerSecond();
	}
	return dps;
}

std::ostream& AttackList::streamStats(std::ostream& os) {
	for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
		attack->streamStats(os);
	}
	return os;
}

AttackList AttackList::improve(AttackBuff attackBuff) {
	std::vector<AttackBuff> newBuffs = appliedBuffs;
	newBuffs.push_back(attackBuff);
	std::vector<Attack> upgradedAttacks;
	for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
		upgradedAttacks.push_back(attack->improve(attackBuff));
	}
	return AttackList(upgradedAttacks, newBuffs);
}

AttackList AttackList::improve(AttackBuff attackBuff, std::vector<std::string> targets) {
	std::vector<AttackBuff> newBuffs = appliedBuffs;
	newBuffs.push_back(attackBuff);
	std::vector<Attack> upgradedAttacks;
	for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
		if (std::find(targets.begin(), targets.end(), attack->getName()) != targets.end()) {
			upgradedAttacks.push_back(attack->improve(attackBuff));
		}
		else {
			upgradedAttacks.push_back(*attack);
		}
	}
	return AttackList(upgradedAttacks, newBuffs);
}