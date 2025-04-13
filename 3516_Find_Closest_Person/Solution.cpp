#include <Solution.h>
#include <iostream>

int Solution::findClosest(int x, int y, int z) {
	int diff1 = abs(z - x);
	int diff2 = abs(z - y);
	return diff1 == diff2 ? 0 : diff1 < diff2 ? 1 : 2;
}
