#include "attacksbuff.h"

AttacksBuff::AttacksBuff(AttackBuff attackBuff) : attackBuff(attackBuff) {}

AttacksBuff::AttacksBuff(json buffJson) : attackBuff(buffJson) {}

AttackList AttacksBuff::buff(AttackList attacks) {
	return attacks.improve(attackBuff);
}