#include "buff.h"
#include "attacksbuff.h"
#include "addattack.h"
#include "replaceattack.h"

Buff* createBuff(json buffJson) {
	if (buffJson[0] == "buffAttacks") {
		return new AttacksBuff(buffJson[1]);
	}
	else if (buffJson[0] == "addAttack") {
		return new AddAttack(buffJson[1]);
	}
	else if (buffJson[0] == "replaceAttack") {
		return new ReplaceAttack(buffJson[1]);
	}
	throw std::invalid_argument("Invalid buff json");
}