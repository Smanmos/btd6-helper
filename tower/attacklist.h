#ifndef ATTACK_LIST
#define ATTACK_LIST
#include "attack.h"
#include <vector>
class AttackList {
	std::vector<Attack> attacks;
	void add(Attack);
public:
	AttackList();
	AttackList(Attack);
	AttackList(AttackList&);
	double getTotalDps();
	AttackList improve(Upgrade);
};
#endif // !ATTACK_LIST
