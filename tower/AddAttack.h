#ifndef ADD_ATTACK
#define ADD_ATTACK
#include "buff.h"
class AddAttack : public Buff {
	Attack attackToAdd;
	void printToOstream(std::ostream&);
public:
	AddAttack(Attack);
	AddAttack(json);
	AttackList buff(AttackList);
};
#endif // !ADD_ATTACK
