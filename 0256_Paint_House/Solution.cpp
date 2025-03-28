#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::swap;

int Solution::minCost(vector<vector<int>> &costs) {
	int size = costs.size();
	vector<int> dp(3, 0), next(3, 0);

	for (int i = 0; i < 3; ++i)
		dp[i] = costs[0][i];
	for (int i = 1; i < size; ++i) {
		next[0] = min(dp[1] + costs[i][0], dp[2] + costs[i][0]);
		next[1] = min(dp[0] + costs[i][1], dp[2] + costs[i][1]);
		next[2] = min(dp[1] + costs[i][2], dp[0] + costs[i][2]);
		swap(dp, next);
	}
	return min({dp[0], dp[1], dp[2]});
}
