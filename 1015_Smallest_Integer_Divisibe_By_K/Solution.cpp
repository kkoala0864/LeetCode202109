#include <Solution.h>
#include <iostream>

int Solution::smallestRepunitDivByK(int k) {
	if (((k & 1) == 0) || (k % 5 == 0))
		return -1;
	int result = 1;
	int rest = 1 % k;
	while (rest > 0) {
		rest = rest * 10 + 1;
		rest = rest % k;
		++result;
	}
	return result;
}
