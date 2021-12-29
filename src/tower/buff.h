#ifndef BUFF
#define BUFF
#include "tower/attacklist.h"
class Buff {
	virtual void printToOstream(std::ostream&) = 0;
public:
	virtual AttackList buff(AttackList) = 0;
	friend std::ostream& operator<<(std::ostream& os, Buff& buff) {
		buff.printToOstream(os);
		return os;
	}
};

Buff* createBuff(json);
#endif // !BUFF
