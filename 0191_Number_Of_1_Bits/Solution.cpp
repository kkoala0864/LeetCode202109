#include <Solution.h>
#include <iostream>

int Solution::hammingWeight(uint32_t n) {
	int cnt = (n & 1);
	for (int i = 0 ; i < 32 && n != 0; ++i) {
		n = n >> 1;
		cnt += (n & 1);
	}
	return cnt;
}
