#include "buff.h"
#include "attacksbuff.h"
#include "addattack.h"

Buff* createBuff(json buffJson) {
	if (buffJson.contains("buffAttacks")) {
		return new AttacksBuff(buffJson.at("buffAttacks"));
	}
	else if (buffJson.contains("addAttack")) {
		return new AddAttack(buffJson.at("addAttack"));
	}
	throw std::invalid_argument("Invalid buff json");
}