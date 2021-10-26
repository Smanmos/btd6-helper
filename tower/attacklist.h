#ifndef ATTACK_LIST
#define ATTACK_LIST
#include "attack.h"
#include "attackbuff.h"
#include <vector>
class AttackList {
	std::vector<Attack> attacks;
	std::vector<AttackBuff> appliedBuffs;
public:
	AttackList();
	AttackList(Attack);
	AttackList(std::vector<Attack>);
	AttackList(std::vector<Attack>, std::vector<AttackBuff>);
	AttackList(AttackList&);
	void add(Attack);
	double getTotalDps();
	std::ostream& streamStats(std::ostream&);
	AttackList improve(AttackBuff);
	AttackList improve(AttackBuff, std::vector<std::string>);
};
#endif // !ATTACK_LIST
