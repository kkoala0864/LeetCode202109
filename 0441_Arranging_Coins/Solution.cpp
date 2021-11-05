#include <Solution.h>
#include <iostream>

int Solution::arrangeCoins(int n) {
	return (int)(sqrt(2 * (long)n +0.25) - 0.5);
}
