#include <Solution.h>

bool Solution::isPowerOfFour(int n) {
	if (n == 1) return true;
	if (n <= 0) return false;
	if ((n & (n-1)) != 0) return false;
	unsigned int mask = 1431655764;
	mask = ~mask;
	return (n & mask) == 0;
}
