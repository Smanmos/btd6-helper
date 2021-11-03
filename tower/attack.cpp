#include "attack.h"

Attack::Attack() :
	cooldown(1.0), projectile("", 1, 1), numProjectiles(1) {}

Attack::Attack(std::string name, double cooldown, int pierce, Damage damage, int numProjectiles) :
	cooldown(cooldown), projectile(name, damage, pierce), numProjectiles(numProjectiles) {}

Attack::Attack(json attackJson) {
	cooldown = attackJson.at("cooldown").get<double>();
	projectile = Projectile(attackJson);
	numProjectiles = attackJson.value("numProjectiles", 1);
}

std::string Attack::getName() {
	return projectile.getName();
}

double Attack::getCooldown() {
	return cooldown;
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
	return projectile.getTotalDamage() * numProjectiles / cooldown;
}

std::ostream& Attack::streamStats(std::ostream& os) {
	os << projectile.getName() << ": ";
	os << cooldown << "s; ";
	os << projectile;
	if (numProjectiles > 1) {
		os << "; " << numProjectiles << "j";
	}
	os << std::endl;
	return os;
}

Attack Attack::improve(AttackBuff attackBuff) {
	return Attack(this->projectile.getName(),
		this->cooldown * attackBuff.getCooldownDecrease(),
		this->projectile.getPierce() + attackBuff.getPierceIncrease(),
		this->projectile.getDamage() + attackBuff.getDamageIncrease(),
		this->numProjectiles + attackBuff.getProjectileIncrease());
}