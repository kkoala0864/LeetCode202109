#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

uint32_t Solution::reverseBits(uint32_t n) {
	if (0 == n) return n;
	uint32_t left = 1 << 31;
	uint32_t right = 1;

	while (left > right) {
		uint32_t leftVal = (n & left) > 0 ? 1 : 0;
		uint32_t rightVal = (n & right) > 0 ? 1 : 0;
		uint32_t mask = ~(left | right);
		n = (n & mask);
		if (leftVal) n = n | right;
		if (rightVal) n = n | left;
		left = left >> 1;
		right = right << 1;
	}
	return n;
}
