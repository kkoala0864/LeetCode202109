#include <Solution.h>
#include <iostream>

uint32_t Solution::reverseBits2(uint32_t n) {
	uint32_t result = 0;
	for (int i = 0; i < 32; ++i) {
		result = result << 1;
		result = result | (n & 1);
		n = n >> 1;
	}
	return result;
}
