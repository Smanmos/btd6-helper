#ifndef ADD_ATTACK
#define ADD_ATTACK
#include "buff.h"
class AddAttack : public Buff {
	Attack attackToAdd;
public:
	AddAttack(Attack);
	AddAttack(json);
	AttackList buff(AttackList);
	friend std::ostream& operator<<(std::ostream&, const AddAttack&);
};
#endif // !ADD_ATTACK
