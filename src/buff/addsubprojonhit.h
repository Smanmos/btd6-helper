#ifndef ADD_SUB_PROJ_ON_HIT
#define ADD_SUB_PROJ_ON_HIT
#include "buff/buff.h"
class AddSubProjOnHit : public Buff {
	std::string target;
	Projectile subProjToAdd;
	int numSubProj;
	void printToOstream(std::ostream&);
public:
	AttackList buff(AttackList);
	AddSubProjOnHit(std::string, Projectile, int);
	AddSubProjOnHit(json buffJson);
};
#endif // !ADD_SUB_PROJ_ON_HIT
