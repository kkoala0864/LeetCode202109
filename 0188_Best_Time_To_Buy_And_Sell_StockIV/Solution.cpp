#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

/*
dp1Cost = min(dp1Cost, prices[i]);
dp1Profit = max(dp1Profit, prices[i] - dp1Cost);

dp2Cost = min(dp2Cost, prices[i] - dp1Profit);
dp2Profit = max(dp2Profit, prices[i] - dp2Cost);
*/

int Solution::maxProfit(int k, vector<int> &prices) {
	if (0 == k)
		return 0;
	vector<int> cost(k, INT_MAX);
	vector<int> profit(k, 0);

	for (const auto &iter : prices) {
		for (int i = 0; i < k; ++i) {
			cost[i] = min(cost[i], i == 0 ? iter : iter - profit[i - 1]);
			profit[i] = max(profit[i], iter - cost[i]);
		}
	}
	return profit[k - 1];
}
