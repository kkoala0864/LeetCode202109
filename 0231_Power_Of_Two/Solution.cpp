#include <Solution.h>
#include <iostream>

bool Solution::isPowerOfTwo(int n) {
	if (n == 0)
		return 0;
	long x = n;
	return (x & (x - 1)) == 0;
}
