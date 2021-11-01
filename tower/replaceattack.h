#ifndef REPLACE_ATTACK
#define REPLACE_ATTACK
#include "buff.h"

class ReplaceAttack : public Buff {
	std::string attackToReplace;
	Attack newAttack;
	void printToOstream(std::ostream&);
public:
	ReplaceAttack(std::string, Attack);
	ReplaceAttack(json replaceAttackJson);
	AttackList buff(AttackList);
};
#endif