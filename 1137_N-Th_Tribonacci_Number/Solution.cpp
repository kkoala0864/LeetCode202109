#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::tribonacci(int n) {
	vector<int> dp;
	dp.emplace_back(0);
	dp.emplace_back(1);
	dp.emplace_back(1);
	for (int i = 3 ; i <= n ; ++i) {
		dp.emplace_back(dp[i-1] + dp[i-2] + dp[i-3]);
	}
	return dp[n];
}
