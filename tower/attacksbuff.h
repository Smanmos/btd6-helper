#ifndef ATTACKS_BUFF
#define ATTACKS_BUFF
#include "buff.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class AttacksBuff : public Buff {
	AttackBuff attackBuff;
public:
	AttacksBuff(AttackBuff);
	AttacksBuff(json);
	AttackList buff(AttackList);
	std::ostream& operator<<(std::ostream&);
};
#endif // !ATTACKS_BUFF
