#include "replaceattack.h"

ReplaceAttack::ReplaceAttack(std::string target, Attack newAttack) :
	attackToReplace(target), newAttack(newAttack) {}

ReplaceAttack::ReplaceAttack(json replaceAttackJson) {
	attackToReplace = replaceAttackJson.at("target");
	newAttack = Attack(replaceAttackJson.at("newAttack"));
}

AttackList ReplaceAttack::buff(AttackList attacks) {
	AttackList newAttacks = attacks;
	newAttacks.replace(attackToReplace, newAttack);
	return newAttacks;
}

void ReplaceAttack::printToOstream(std::ostream& os) {
	os << attackToReplace << " replaced with " << newAttack.getName() << ":" << std::endl;
	newAttack.streamStats(os);
}