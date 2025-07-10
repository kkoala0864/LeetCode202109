#include <Solution.h>
#include <cmath>

int Solution::poorPigs(int buckets, int minutesToDie, int minutesToTest) {
	int round = minutesToTest / minutesToDie;
	int result = 0;
	while (pow(round + 1, result) < buckets) {
		++result;
	}
	return result;
}
