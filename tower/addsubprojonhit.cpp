#include "addsubprojonhit.h"

AddSubProjOnHit::AddSubProjOnHit(std::string target, Projectile proj, int numProj) :
	target(target), subProjToAdd(proj), numSubProj(numProj) {}

AddSubProjOnHit::AddSubProjOnHit(json buffJson) :
	target(buffJson.at("target")), subProjToAdd(buffJson.at("subProjectile")),
	numSubProj(buffJson.at("num")) {}

AttackList AddSubProjOnHit::buff(AttackList attacks) {
	return attacks.addSubProjOnHit(target, subProjToAdd, numSubProj);
}

void AddSubProjOnHit::printToOstream(std::ostream& os) {
	os << "Add sub-projectile to " << target << " on hit:" << std::endl;
	os << numSubProj << "j; " << subProjToAdd;
}