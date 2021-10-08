#ifndef DIFFICULTY
#define DIFFICULTY
enum Difficulty {
	EASY, MEDIUM, HARD, IMPOPPABLE
};

const double DIFFICULTY_MULTIPLIERS[4] = { 0.85, 1.0, 1.08, 1.2 };
#endif // DIFFICULTY