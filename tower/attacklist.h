#ifndef ATTACK_LIST
#define ATTACK_LIST
#include "attack.h"
#include "attackbuff.h"
#include <vector>
class AttackList {
	std::vector<Attack> attacks;
public:
	AttackList();
	AttackList(Attack);
	AttackList(std::vector<Attack>);
	AttackList(AttackList&);
	void add(Attack);
	double getTotalDps();
	std::ostream& streamStats(std::ostream&);
	AttackList improve(AttackBuff);
};
#endif // !ATTACK_LIST
