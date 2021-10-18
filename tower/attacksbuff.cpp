#include "attacksbuff.h"

AttacksBuff::AttacksBuff(AttackBuff attackBuff) : attackBuff(attackBuff) {}

AttackList AttacksBuff::buff(AttackList attacks) {
	return attacks.improve(attackBuff);
}