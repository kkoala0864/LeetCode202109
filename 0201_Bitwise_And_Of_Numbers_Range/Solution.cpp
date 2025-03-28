#include <Solution.h>
#include <iostream>
int Solution::rangeBitwiseAnd(int left, int right) {
	int result = 0;
	int mask = (1 << 31);
	for (int i = 0; i < 32; ++i) {
		int leftBit = ((unsigned int)left << i) & mask;
		int rightBit = ((unsigned int)right << i) & mask;
		if (leftBit != rightBit)
			break;
		else {
			if (leftBit && rightBit) {
				result += (1 << (31 - i));
			}
		}
	}
	return result;
}
