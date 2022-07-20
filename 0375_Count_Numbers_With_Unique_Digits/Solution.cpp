#include <Solution.h>
#include <iostream>

void dfs(int size, int n, int bit, int& result) {
	if (size == n) return;
	for (int i = 0 ; i < 10 ; ++i) {
		if (size == 0 && i == 0) continue;
		if (bit >> i & 1) continue;
		++result;
		dfs(size+1, n, bit | (1<<i), result);
	}
}

int Solution::countNumbersWithUniqueDigits(int n) {
	if (n == 0) return 1;
	int result = 0;
	dfs(0, n, 0, result);
	return result + 1;
}
