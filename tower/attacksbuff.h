#ifndef ATTACKS_BUFF
#define ATTACKS_BUFF
#include "buff.h"
class AttacksBuff : public Buff {
	AttackBuff attackBuff;
public:
	AttacksBuff(AttackBuff);
	AttackList buff(AttackList);
};
#endif // !ATTACKS_BUFF
