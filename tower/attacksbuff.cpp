#include "attacksbuff.h"

AttacksBuff::AttacksBuff(AttackBuff attackBuff) : attackBuff(attackBuff) {}

AttacksBuff::AttacksBuff(json buffJson) : attackBuff(buffJson) {
	if (buffJson.contains("targets")) {
		targets = new std::vector<std::string>();
		for (json::iterator target = buffJson.at("target").begin(); target != buffJson.at("target").end(); ++target) {
			targets->push_back(target->get<std::string>());
		}
	}
	else {
		targets = nullptr;
	}
}

AttackList AttacksBuff::buff(AttackList attacks) {
	return attacks.improve(attackBuff);
}

void AttacksBuff::printToOstream(std::ostream& os) {
	AttackBuff attackBuff = this->attackBuff;
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
}