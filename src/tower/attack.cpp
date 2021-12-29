#include "attack.h"

Attack::Attack() :
	reload(1.0), projectile("", 1, 1), numProjectiles(1) {}

Attack::Attack(std::string name, double reload, int pierce, Damage damage, int numProjectiles) :
	reload(reload), projectile(name, damage, pierce), numProjectiles(numProjectiles) {}

Attack::Attack(double reload, Projectile projectile, int numProjectiles) :
	reload(reload), projectile(projectile), numProjectiles(numProjectiles) {}

Attack::Attack(json attackJson) {
	reload = attackJson.at("reload").get<double>();
	projectile = Projectile(attackJson);
	numProjectiles = attackJson.value("numProjectiles", 1);
}

std::string Attack::getName() {
	return projectile.getName();
}

double Attack::getReload() {
	return reload;
}

int Attack::getPierce() {
	return projectile.getPierce();
}

Damage Attack::getDamage() {
	return projectile.getDamage();
}

int Attack::getBaseDamage() {
	return getDamage().getDamage();
}

int Attack::getCeramicDamage() {
	return getDamage().getCeramicDamage();
}

int Attack::getMoabDamage() {
	return getDamage().getMoabDamage();
}

int Attack::getNumProjectiles() {
	return numProjectiles;
}

double Attack::getDamagePerSecond() {
	return projectile.getTotalDamage() * numProjectiles / reload;
}

std::ostream& Attack::streamStats(std::ostream& os) {
	os << projectile.getName() << ": ";
	os << reload << "s; ";
	os << projectile;
	if (numProjectiles > 1) {
		os << "; " << numProjectiles << "j";
	}
	os << std::endl;
	return os;
}

Attack Attack::improve(AttackBuff attackBuff) {
	return Attack(reload * attackBuff.getReloadDecrease(),
		projectile.improve(attackBuff),
		numProjectiles + attackBuff.getProjectileIncrease());
}

Attack Attack::addSubProjOnHit(Projectile subProj, int numSubProj) {
	return Attack(reload, projectile.addSubProjOnHit(subProj, numSubProj), numProjectiles);
}

Attack Attack::addSubProjOnExpire(Projectile subProj, int numSubProj) {
	return Attack(reload, projectile.addSubProjOnExpire(subProj, numSubProj), numProjectiles);
}