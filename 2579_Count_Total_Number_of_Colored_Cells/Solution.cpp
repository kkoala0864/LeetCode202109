#include <Solution.h>
#include <iostream>

long long Solution::coloredCells(int n) {
	long long result = ((long long)n * (long long)n) << 1;
	return result - ((n << 1) - 1);
}
