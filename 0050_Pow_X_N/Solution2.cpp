#include <Solution.h>
#include <iostream>

double Solution::myPow2(double x, int n) {
	double result = 1;
	while (n) {
		if (n & 1) result = n > 0 ? result * x : result / x;
		x *= x;
		n /= 2;
	}
	return result;
}
