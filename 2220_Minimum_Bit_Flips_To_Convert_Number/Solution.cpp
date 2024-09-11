#include <Solution.h>
#include <iostream>

int Solution::minBitFlips(int start, int goal) {
	int v = start ^ goal;
	int result = 0;

	while (v) {
		++result;
		v &= (v - 1);
	}
	return result;
}
