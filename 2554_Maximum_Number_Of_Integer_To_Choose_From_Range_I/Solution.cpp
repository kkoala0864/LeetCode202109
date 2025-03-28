#include <Solution.h>
#include <iostream>

int Solution::maxCount(vector<int> &banned, int n, int maxSum) {
	vector<bool> bl(n + 1, false);
	for (const auto &v : banned) {
		if (v > n)
			continue;
		bl[v] = true;
	}
	int curSum = 0;
	int result = 0;

	for (int i = 1; i <= n; ++i) {
		if (bl[i])
			continue;
		if ((curSum + i) <= maxSum) {
			++result;
			curSum += i;
		} else
			break;
	}
	return result;
}
