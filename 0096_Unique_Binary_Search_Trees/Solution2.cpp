#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::numTrees2(int n) {
	vector<int> dp(2, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2 ; i <= n ; ++i) {
		int val = 0;
		for (int j = 0 ; j < i ; ++j) {
			val += (dp[j] * dp[i - j - 1]);
		}
		dp.emplace_back(val);
	}
	return dp[n];
}
