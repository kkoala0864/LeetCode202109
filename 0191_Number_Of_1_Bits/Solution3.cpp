#include <Solution.h>
#include <iostream>

int Solution::hammingWeight3(uint32_t n) {
	int result = 0;
	while (n > 0) {
		++result;
		n &= (n - 1);
	}
	return result;
}
