#ifndef BUFF
#define BUFF
#include "attacklist.h"
class Buff {
	virtual AttackList buff(AttackList) = 0;
};
#endif // !BUFF
