#include "addattack.h"

AddAttack::AddAttack(Attack attack) : attackToAdd(attack) {}

AddAttack::AddAttack(json attackJson) : attackToAdd(attackJson) {}

AttackList AddAttack::buff(AttackList attacks) {
	AttackList newAttacks = attacks;
	newAttacks.add(attackToAdd);
	return newAttacks;
}

void AddAttack::printToOstream(std::ostream& os) {
	os << "Add attack ";
	attackToAdd.streamStats(os);
}