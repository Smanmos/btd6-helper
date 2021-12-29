#ifndef ATTACKS_BUFF
#define ATTACKS_BUFF
#include "buff/buff.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class AttacksBuff : public Buff {
	AttackBuff attackBuff;
	std::vector<std::string> targets;
	void printToOstream(std::ostream&);
public:
	AttacksBuff(AttackBuff);
	AttacksBuff(json);
	AttackList buff(AttackList);
};
#endif // !ATTACKS_BUFF
