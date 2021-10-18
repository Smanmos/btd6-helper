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
	AttackList(std::vector<Attack>);
	AttackList(AttackList&);
	double getTotalDps();
	std::ostream& streamStats(std::ostream&);
	AttackList improve(Upgrade);
};
#endif // !ATTACK_LIST
