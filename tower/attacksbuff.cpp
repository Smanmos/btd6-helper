#include "attacksbuff.h"

AttacksBuff::AttacksBuff(AttackBuff attackBuff) : attackBuff(attackBuff) {}

AttacksBuff::AttacksBuff(json buffJson) : attackBuff(buffJson) {}

AttackList AttacksBuff::buff(AttackList attacks) {
	return attacks.improve(attackBuff);
}


std::ostream& operator<<(std::ostream& os, const AttacksBuff& attacksBuff) {
	AttackBuff attackBuff = attacksBuff.attackBuff;
	if (attackBuff.isCooldownDecreased()) {
		os << attackBuff.getCooldownDecrease() << "s" << std::endl;
	}
	if (attackBuff.isPierceIncreased()) {
		os << "+" << attackBuff.getPierceIncrease() << "p" << std::endl;
	}
	if (attackBuff.isDamageIncreased()) {
		os << "+" << attackBuff.getDamageIncrease() << "d" << std::endl;
	}
	if (attackBuff.isProjectileIncreased()) {
		os << "+" << attackBuff.getProjectileIncrease() << "j" << std::endl;
	}
	return os;
}