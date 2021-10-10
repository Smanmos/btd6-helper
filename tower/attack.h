#ifndef ATTACK
#define ATTACK
class AttackBuilder;
class Attack {
	double cooldown;
	int pierce;
	int damage;
	int numProjectiles;
public:
	Attack();
	Attack(double, int, int, int);
	friend class AttackBuilder;
};
#endif // !ATTACK
