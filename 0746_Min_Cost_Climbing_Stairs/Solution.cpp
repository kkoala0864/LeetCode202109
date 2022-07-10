#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minCostClimbingStairs(vector<int>& cost) {
	vector<int> dp(cost.size() + 1, 0);

	for (int i = 1 ; i <= cost.size() ; ++i) {
		dp[i] = min((i-1 < 0 ? 0 : dp[i-1] + cost[i-1]), (i-2 < 0 ? 0 : dp[i-2] + cost[i-2]));
	}
	return dp.back();
}
