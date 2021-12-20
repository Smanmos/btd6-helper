#include "attacksbuff.h"

AttacksBuff::AttacksBuff(AttackBuff attackBuff) : attackBuff(attackBuff) {}

AttacksBuff::AttacksBuff(json buffJson) : attackBuff(buffJson) {
	targets = std::vector<std::string>();
	for (json::iterator target = buffJson.at("targets").begin(); target != buffJson.at("targets").end(); ++target) {
		targets.push_back(target->get<std::string>());
	}
}

AttackList AttacksBuff::buff(AttackList attacks) {
	return attacks.improve(attackBuff, targets);
}

void AttacksBuff::printToOstream(std::ostream& os) {
	AttackBuff attackBuff = this->attackBuff;
	if (attackBuff.isReloadDecreased()) {
		os << attackBuff.getReloadDecrease() << "s" << std::endl;
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