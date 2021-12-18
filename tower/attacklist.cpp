#include "attacklist.h"

AttackList::AttackList() : attacks(std::vector<Attack>()), appliedBuffs() {}

AttackList::AttackList(Attack attack) : attacks(std::vector<Attack>{attack}), appliedBuffs() {}

AttackList::AttackList(std::vector<Attack> attackVector) : 
	attacks(attackVector), appliedBuffs() {}

AttackList::AttackList(std::vector<Attack> attackVector, 
	std::vector<std::pair<AttackBuff, std::vector<std::string>* > > buffs) :
	attacks(attackVector), appliedBuffs(buffs) {
	;
}

AttackList::AttackList(AttackList& copy) : 
	attacks(copy.attacks), appliedBuffs(copy.appliedBuffs){}

std::vector<Attack> AttackList::getBuffedAttacks() {
	std::vector<Attack> buffedAttacks{};
	for (auto attack : attacks) {
		Attack buffedAttack = attack;
		for (auto appliedBuff : appliedBuffs) {
			std::vector<std::string>* targets = appliedBuff.second;
			if (targets == nullptr ||
				std::find(targets->begin(), targets->end(), attack.getName()) != targets->end()) {
				buffedAttack = buffedAttack.improve(appliedBuff.first);
			}
		}
		buffedAttacks.push_back(buffedAttack);
	}
	return buffedAttacks;
}

void AttackList::add(Attack attack) {
	attacks.push_back(attack);
}

void AttackList::replace(std::string target, Attack newAttack) {
	for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
		if (attack->getName() == target) {
			*attack = newAttack;
			return;
		}
	}
	// Attack to replace wasn't found
	add(newAttack);
}

double AttackList::getTotalDps() {
	std::vector<Attack> buffedAttacks = getBuffedAttacks();
	double dps = 0;
	for (auto attack = buffedAttacks.begin(); attack != buffedAttacks.end(); ++attack) {
		dps += attack->getDamagePerSecond();
	}
	return dps;
}

std::ostream& AttackList::streamStats(std::ostream& os) {
	std::vector<Attack> buffedAttacks = getBuffedAttacks();
	for (auto attack = buffedAttacks.begin(); attack != buffedAttacks.end(); ++attack) {
		attack->streamStats(os);
	}
	return os;
}

AttackList AttackList::improve(AttackBuff attackBuff) {
	std::vector<std::pair<AttackBuff, std::vector<std::string>* > > newBuffs = appliedBuffs;
	newBuffs.push_back(std::pair<AttackBuff, std::vector<std::string>* >(attackBuff, nullptr));
	return AttackList(attacks, newBuffs);
}

AttackList AttackList::improve(AttackBuff attackBuff, std::vector<std::string> targets) {
	std::vector<std::pair<AttackBuff, std::vector<std::string>* > > newBuffs = appliedBuffs;
	newBuffs.push_back(std::pair<AttackBuff, std::vector<std::string>* >(attackBuff, 
		new std::vector<std::string>(targets)));
	return AttackList(attacks, newBuffs);
}

AttackList AttackList::addSubProjOnHit(std::string target, Projectile subProj, int numSubProj) {
	std::vector<Attack> newAttacks = attacks;
	for (auto attack = newAttacks.begin(); attack != newAttacks.end(); ++attack) {
		if (attack->getName() == target) {
			*attack = attack->addSubProjOnHit(subProj, numSubProj);
		}
	}
	return AttackList(newAttacks, appliedBuffs);
}

AttackList AttackList::addSubProjOnExpire(std::string target, Projectile subProj, int numSubProj) {
	std::vector<Attack> newAttacks = attacks;
	for (auto attack = newAttacks.begin(); attack != newAttacks.end(); ++attack) {
		if (attack->getName() == target) {
			*attack = attack->addSubProjOnExpire(subProj, numSubProj);
		}
	}
	return AttackList(newAttacks, appliedBuffs);
}