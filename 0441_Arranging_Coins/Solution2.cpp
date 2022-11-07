#include <Solution.h>
#include <iostream>
#include <math.h>

int Solution::arrangeCoins2(int n) {
	return sqrt(2 * (long)n + 0.25) - 0.5;
}
