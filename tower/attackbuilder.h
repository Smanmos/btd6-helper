#ifndef ATTACK_BUILDER
#define ATTACK_BUILDER
#include "attack.h"
class AttackBuilder {
	double cd;
	int p;
	int d;
	int j;
	bool isCooldownSet;
public:
	AttackBuilder();
	AttackBuilder& cooldown(double);
	AttackBuilder& pierce(int);
	AttackBuilder& damage(int);
	AttackBuilder& projectiles(int);
	Attack build();
};
#endif // !ATTACK_BUILDER
