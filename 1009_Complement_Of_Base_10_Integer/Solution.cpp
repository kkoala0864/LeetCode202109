#include <Solution.h>
#include <iostream>

int Solution::bitwiseComplement(int n) {
	if (n == 0) return 1;
	int i = 1;
	while (i <= n) i = i << 1;
	return ~n & (i-1);
}
