#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using std::min;
using std::vector;

int Solution::numSquares2(int n) {
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		int local = INT_MAX;
		for (int j = 1; (j * j) <= i; ++j) {
			local = min(local, 1 + dp[i - j * j]);
		}
		dp[i] = local;
	}
	return dp[n];
}
