#ifndef ATTACK_BUILDER
#define ATTACK_BUILDER
#include "attack.h"
class AttackBuilder {
	double r;
	int p;
	int d;
	int j;
	bool isReloadSet;
public:
	AttackBuilder();
	AttackBuilder& reload(double);
	AttackBuilder& pierce(int);
	AttackBuilder& damage(int);
	AttackBuilder& projectiles(int);
	Attack build();
};
#endif // !ATTACK_BUILDER
