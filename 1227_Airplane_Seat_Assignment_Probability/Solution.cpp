#include <Solution.h>

// 1/n * (1/n-1 * 1/n-2*...1/n-i)
double Solution::nthPersonGetsNthSeat(int n) {
	if (n == 1) return 1;
	return 0.5;

}
