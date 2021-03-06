#ifndef ATTACK_LIST
#define ATTACK_LIST
#include "tower/attack.h"
#include "buff/attackbuff.h"
#include <vector>
class AttackList {
	std::vector<Attack> attacks;
	std::vector<std::pair<AttackBuff, std::vector<std::string> > > appliedBuffs;
	std::vector<Attack> getBuffedAttacks();
public:
	AttackList();
	AttackList(Attack);
	AttackList(std::vector<Attack>);
	AttackList(std::vector<Attack>, std::vector<std::pair<AttackBuff, std::vector<std::string> > >);
	AttackList(AttackList&);
	void add(Attack);
	void replace(std::string, Attack);
	double getTotalDps();
	std::ostream& streamStats(std::ostream&);
	AttackList improve(AttackBuff, std::vector<std::string>);
	AttackList addSubProjOnHit(std::string, Projectile, int);
	AttackList addSubProjOnExpire(std::string, Projectile, int);
};
#endif // !ATTACK_LIST
