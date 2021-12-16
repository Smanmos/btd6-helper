#include "addsubprojonexpire.h"

AddSubProjOnExpire::AddSubProjOnExpire(std::string target, Projectile proj, int numProj) :
	target(target), subProjToAdd(proj), numSubProj(numProj) {}

AddSubProjOnExpire::AddSubProjOnExpire(json buffJson) :
	target(buffJson.at("target")), subProjToAdd(buffJson.at("subProjectile")),
	numSubProj(buffJson.value("num", 1)) {}

AttackList AddSubProjOnExpire::buff(AttackList attacks) {
	return attacks.addSubProjOnExpire(target, subProjToAdd, numSubProj);
}

void AddSubProjOnExpire::printToOstream(std::ostream& os) {
	os << "Add sub-projectile to " << target << " on expire:" << std::endl;
	os << numSubProj << "j; " << subProjToAdd;
}