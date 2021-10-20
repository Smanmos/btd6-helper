#include "attack.h"

Attack::Attack() {
	cooldown = 1.0;
	pierce = 1;
	damage = Damage(1);
	numProjectiles = 1;
}

Attack::Attack(double cooldown, int pierce, Damage damage, int numProjectiles) :
	cooldown(cooldown), pierce(pierce), damage(damage), numProjectiles(numProjectiles) {}

Attack::Attack(json attackJson) {
	name = attackJson.at("name");
	cooldown = attackJson.at("cooldown").get<double>();
	pierce = attackJson.value("pierce", 1);
	if (attackJson.contains("damage")) {
		damage = Damage(attackJson.at("damage"));
	}
	else {
		damage = Damage(1);
	}
	numProjectiles = attackJson.value("numProjectiles", 1);
}

std::string getName() {
	return name;
}

double Attack::getCooldown() {
	return cooldown;
}

int Attack::getPierce() {
	return pierce;
}

Damage Attack::getDamage() {
	return damage;
}

int Attack::getBaseDamage() {
	return damage.getDamage();
}

int Attack::getCeramicDamage() {
	return damage.getCeramicDamage();
}

int Attack::getMoabDamage() {
	return damage.getMoabDamage();
}

int Attack::getNumProjectiles() {
	return numProjectiles;
}

double Attack::getDamagePerSecond() {
	return pierce * damage.getDamage() * numProjectiles / cooldown;
}

std::ostream& Attack::streamStats(std::ostream& os) {
	os << name << ": ";
	os << cooldown << "s";
	os << ", " << pierce << "p";
	os << ", " << damage;
	if (numProjectiles > 1) {
		os << ", " << numProjectiles << "j";
	}
	os << std::endl;
	return os;
}

Attack Attack::improve(AttackBuff attackBuff) {
	return Attack(this->cooldown * attackBuff.getCooldownDecrease(),
		this->pierce + attackBuff.getPierceIncrease(),
		this->damage + attackBuff.getDamageIncrease(),
		this->numProjectiles + attackBuff.getProjectileIncrease());
}