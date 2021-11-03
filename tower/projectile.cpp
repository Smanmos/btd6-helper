#include "projectile.h"

Projectile::Projectile() : Projectile("", 0, 0) {}

Projectile::Projectile(std::string name, Damage damage, int pierce) :
	name(name), damage(damage), pierce(pierce) {}

Projectile::Projectile(json projJson) {
	name = projJson.at("name");
	pierce = projJson.value("pierce", 1);
	if (projJson.contains("damage")) {
		damage = Damage(projJson.at("damage"));
	}
	else {
		damage = Damage(1);
	}
}

std::string Projectile::getName() {
	return name;
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