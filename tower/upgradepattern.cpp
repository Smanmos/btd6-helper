#include "upgradepattern.h"
#include <stdexcept>
UpgradePattern::UpgradePattern(int top, int mid, int bot) :
	top(top), mid(mid), bot(bot) {
	validate();
}

UpgradePattern::UpgradePattern() : UpgradePattern(0, 0, 0) {}

void UpgradePattern::validate() {
	if (top > 0 && mid > 0 && bot > 0) {
		throw std::invalid_argument("Tower cannot be upgraded on all 3 paths");
	}
	if ((top > 2) + (mid > 2) + (bot > 2) > 1) {
		throw std::invalid_argument("Tower can be upgraded past tier 3 on only one path");
	}
	if (top > 5 || mid > 5 || bot > 5) {
		throw std::invalid_argument("Tower can be only upgraded to tier 5");
	}
	if (top < 0 || mid < 0 || bot < 0) {
		throw std::invalid_argument("Number of upgrades must be positive");
	}
}

UpgradePattern UpgradePattern::upgradeTop(int top) {
	return UpgradePattern(this->top + top, this->mid, this->bot);
}

UpgradePattern UpgradePattern::upgradeMid(int mid) {
	return UpgradePattern(this->top, this->mid + mid, this->bot);
}

UpgradePattern UpgradePattern::upgradeBot(int bot) {
	return UpgradePattern(this->top, this->mid, this->bot + bot);
}