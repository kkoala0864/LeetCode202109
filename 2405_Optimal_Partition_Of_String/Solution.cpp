#include <Solution.h>
#include <iostream>

int Solution::partitionString(string s) {
	int bitset = 0;
	int result = 1;
	for (const auto& c : s) {
		if (bitset & (1 << (c - 'a'))) {
			++result;
			bitset = 0;
		}
		bitset |= 1 << (c - 'a');
	}
	return result;
}
