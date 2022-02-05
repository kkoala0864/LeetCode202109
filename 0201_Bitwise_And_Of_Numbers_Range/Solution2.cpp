#include <Solution.h>
#include <iostream>

int Solution::rangeBitwiseAnd2(int left, int right) {
	if (left == right) return left;

	int cmp = true;
	int result = 0;
	for (int i = 31 ; i >= 0 ; --i) {
		result = result << 1;
		if (cmp) {
			int lBit = (left >> i) & 1;
			int rBit = (right >> i) & 1;
			if (lBit == rBit) {
				result += lBit;
			} else {
				cmp = false;
			}
		}
	}
	return result;
}
