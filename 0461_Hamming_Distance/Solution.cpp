#include <Solution.h>
#include <iostream>

int Solution::hammingDistance(int x, int y) {
	int result = 0;
	int val = x ^ y;
	while (val) {
		++result;
		val = val & (val-1);
	}
	return result;
}
