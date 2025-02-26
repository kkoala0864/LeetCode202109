#include <Solution.h>
#include <iostream>

double Solution::myPow(double x, int n) {
	if (n == 0) return 1;
	double one = n < 0 ? 1 / x : x;
	double v = myPow(x, n / 2);
	return n & 1 ? one * v * v : v * v;
}
