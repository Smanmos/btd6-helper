#ifndef ABILITY
#define ABILITY
#include <iostream>
#include <string>
class Ability {
	std::string name;
	double cooldown;
	virtual void printToOstream(std::ostream&) = 0;
public:
	friend std::ostream& operator<<(std::ostream& os, Ability& ability) {
		ability.printToOstream(os);
		return os;
	}
	double getCooldown();
};
#endif