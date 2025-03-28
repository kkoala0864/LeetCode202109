#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;

int Solution::numTrees(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[0] = 1;

	for (int i = 2; i <= n; ++i) {
		int local = 0;
		for (int j = 0; j < i; ++j) {
			local += (dp[j] * dp[i - j - 1]);
		}
		dp[i] = local;
	}
	return dp[n];
}
