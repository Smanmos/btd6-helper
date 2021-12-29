#ifndef UPGRADE_PATTERN
#define UPGRADE_PATTERN
struct UpgradePattern {
	const int top;
	const int mid;
	const int bot;
	UpgradePattern();
	UpgradePattern(int top, int bot, int mid);
	UpgradePattern upgradeTop(int top);
	UpgradePattern upgradeMid(int mid);
	UpgradePattern upgradeBot(int bot);
private:
	void validate();
};
#endif // !UPGRADE_PATTERN
