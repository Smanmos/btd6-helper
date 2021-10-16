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

Attack Attack::improve(Upgrade upgrade) {
	return Attack(this->cooldown * upgrade.getCooldownDecrease(),
		this->pierce + upgrade.getPierceIncrease(),
		this->damage + upgrade.getDamageIncrease(),
		this->numProjectiles + upgrade.getProjectileIncrease());
}