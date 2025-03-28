#include <Solution.h>
#include <iostream>

int Solution::hammingWeight2(uint32_t n) {
	int result = 0;
	while (n) {
		n = n & (n - 1);
		++result;
	}
	return result;
}
