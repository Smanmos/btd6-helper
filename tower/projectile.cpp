#include "projectile.h"

Projectile::Projectile() : Projectile("", 0, 0) {}

Projectile::Projectile(std::string name, Damage damage, int pierce) :
	name(name), damage(damage), pierce(pierce) {}

Projectile::Projectile(std::string name, Damage damage, int pierce, bool pierceExternalBuffable,
	bool damageExternalBuffable, Projectile* subProjOnHit, int numSubProjOnHit,
	Projectile* subProjOnExpire, int numSubProjOnExpire) :
	name(name), damage(damage), pierce(pierce), pierceExternalBuffable(pierceExternalBuffable),
	damageExternalBuffable(damageExternalBuffable), subProjOnHit(subProjOnHit),
	numSubProjOnHit(numSubProjOnHit), subProjOnExpire(subProjOnExpire),
	numSubProjOnExpire(numSubProjOnExpire) {}

Projectile::Projectile(json projJson) {
	name = projJson.at("name");
	pierce = projJson.value("pierce", 1);
	if (projJson.contains("damage")) {
		damage = Damage(projJson.at("damage"));
	}
	else {
		damage = Damage(1);
	}
	if (projJson.contains("onHit")) {
		subProjOnHit = new Projectile(projJson.at("onHit"));
		numSubProjOnHit = projJson.value("numProjOnHit", 1);
	}
	if (projJson.contains("onExpire")) {
		subProjOnExpire = new Projectile(projJson.at("onExpire"));
		numSubProjOnExpire = projJson.value("numProjOnExpire", 1);
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
	int totalDamage = damage.getDamage() * pierce;
	if (subProjOnHit != nullptr) {
		totalDamage += pierce * numSubProjOnHit * subProjOnHit->getTotalDamage();
	}
	if (subProjOnExpire != nullptr) {
		totalDamage += numSubProjOnExpire * subProjOnHit->getTotalDamage();
	}
	return totalDamage;
}

Projectile* Projectile::getProjectileOnHit() {
	return subProjOnHit;
}

int Projectile::getNumProjectileOnHit() {
	return numSubProjOnHit;
}

Projectile* Projectile::getProjectileOnExpire() {
	return subProjOnExpire;
}

int Projectile::getNumProjectileOnExpire() {
	return numSubProjOnExpire;
}

Projectile Projectile::addSubProjOnHit(Projectile subProj, int numSubProj) {
	return Projectile(name, damage, pierce, pierceExternalBuffable, damageExternalBuffable,
		new Projectile(subProj), numSubProj, subProjOnExpire, numSubProjOnExpire);
}

Projectile Projectile::addSubProjOnExpire(Projectile subProj, int numSubProj) {
	return Projectile(name, damage, pierce, pierceExternalBuffable, damageExternalBuffable,
		subProjOnHit, numSubProjOnHit, new Projectile(subProj), numSubProj);
}

std::ostream& operator<<(std::ostream& os, Projectile& proj) {
	os << proj.pierce << "p; ";
	os << proj.damage;
	if (proj.subProjOnHit != nullptr) {
		os << std::endl << proj.subProjOnHit->getName() << " on " << proj.name << " hit: ";
		os << *proj.subProjOnHit;
		if (proj.numSubProjOnHit > 1) {
			os << "; " << proj.numSubProjOnHit << "j";
		}
	}
	if (proj.subProjOnExpire != nullptr) {
		os << std::endl << proj.subProjOnExpire->getName() << " on " << proj.name << " expire: ";
		os << *proj.subProjOnExpire;
		if (proj.numSubProjOnExpire > 1) {
			os << "; " << proj.numSubProjOnExpire << "j";
		}
	}
	return os;
}