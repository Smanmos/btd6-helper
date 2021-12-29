#ifndef ABILITY
#define ABILITY
#include <iostream>
#include <string>
class Ability {
	std::string name;
	double cooldown;
	virtual void printToOstream(std::ostream&) = 0;
protected:
	void printDetails(std::ostream&);
public:
	Ability(std::string name, double cooldown);
	friend std::ostream& operator<<(std::ostream& os, Ability& ability) {
		ability.printToOstream(os);
		return os;
	}
	double getCooldown();
};
#endif