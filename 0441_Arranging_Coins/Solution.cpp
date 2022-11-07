#include <Solution.h>
#include <iostream>
#include <math.h>

int Solution::arrangeCoins(int n) {
	return (int)(sqrt(2 * (long)n +0.25) - 0.5);
}
