#ifndef ATTACK
#define ATTACK
class Attack {
	double cooldown;
	int pierce;
	int damage;
	int numProjectiles;
public:
	Attack();
	Attack(double, int, int, int);
};
#endif // !ATTACK
