#include <Solution.h>
#include <iostream>

string Solution::kthLuckyNumber(int k) {
	int base = 2;
	int bitSize = 0;

	while (k > base) {
		k -= base;
		++bitSize;
		base = base << 1;
	}

	k -= 1;

	string result(bitSize + 1, '0');

	for (int i = 0; i <= bitSize; ++i) {
		int idx = bitSize - i;
		if ((k & 1) == 1) {
			result[idx] = '7';
		} else {
			result[idx] = '4';
		}
		k = k >> 1;
	}
	return result;
}
