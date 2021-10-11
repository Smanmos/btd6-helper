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
	double getCooldown();
	int getPierce();
	int getDamage();
	int getNumProjectiles();
	friend class AttackBuilder;
};
#endif // !ATTACK
