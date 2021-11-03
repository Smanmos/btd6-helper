#include "projectile.h"

Projectile::Projectile(Damage damage, int pierce) :
	damage(damage), pierce(pierce) {}

Projectile::Projectile(json projJson) {
	pierce = projJson.at("pierce");
	if (projJson.contains("damage")) {
		damage = Damage(projJson.at("damage"));
	}
	else {
		damage = Damage(1);
	}
}

Damage Projectile::getDamage() {
	return damage;
}

int Projectile::getPierce() {
	return pierce;
}

int Projectile::getTotalDamage() {
	return damage.getDamage() * pierce;
}

std::ostream& operator<<(std::ostream& os, Projectile& proj) {
	os << proj.pierce << "p; ";
	os << proj.damage;
	return os;
}