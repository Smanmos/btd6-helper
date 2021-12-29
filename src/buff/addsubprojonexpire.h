#ifndef ADD_SUB_PROJ_ON_EXPIRE
#define ADD_SUB_PROJ_ON_EXPIRE
#include "buff/buff.h"
class AddSubProjOnExpire : public Buff {
	std::string target;
	Projectile subProjToAdd;
	int numSubProj;
	void printToOstream(std::ostream&);
public:
	AttackList buff(AttackList);
	AddSubProjOnExpire(std::string, Projectile, int);
	AddSubProjOnExpire(json buffJson);
};
#endif // !ADD_SUB_PROJ_ON_EXPIRE
