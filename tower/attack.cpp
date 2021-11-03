#include "attack.h"

Attack::Attack() :
	cooldown(1.0), projectile(1, 1), numProjectiles(1) {}

Attack::Attack(std::string name, double cooldown, int pierce, Damage damage, int numProjectiles) :
	name(name), cooldown(cooldown), projectile(damage, pierce), numProjectiles(numProjectiles) {}

Attack::Attack(json attackJson) {
	name = attackJson.at("name");
	cooldown = attackJson.at("cooldown").get<double>();
	int pierce = attackJson.value("pierce", 1);
	Damage damage;
	if (attackJson.contains("damage")) {
		damage = Damage(attackJson.at("damage"));
	}
	else {
		damage = Damage(1);
	}
	projectile = Projectile(damage, pierce);
	numProjectiles = attackJson.value("numProjectiles", 1);
}

std::string Attack::getName() {
	return name;
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
	os << name << ": ";
	os << cooldown << "s; ";
	os << projectile;
	if (numProjectiles > 1) {
		os << "; " << numProjectiles << "j";
	}
	os << std::endl;
	return os;
}

Attack Attack::improve(AttackBuff attackBuff) {
	return Attack(this->name,
		this->cooldown * attackBuff.getCooldownDecrease(),
		this->projectile.getPierce() + attackBuff.getPierceIncrease(),
		this->projectile.getDamage() + attackBuff.getDamageIncrease(),
		this->numProjectiles + attackBuff.getProjectileIncrease());
}