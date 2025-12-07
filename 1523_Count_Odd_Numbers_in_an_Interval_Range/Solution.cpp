#include <Solution.h>

int Solution::countOdds(int low, int high) {
	int result = (high - low + 1) >> 1;
	return result + ((high & 1) && (low & 1));
}
