#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;

int Solution::maxProfit3(int k, vector<int>& prices) {
	if (k == 0) return 0;
	vector<int> profit(k, 0);
	vector<int> cost(k, INT_MAX);

	int result = 0;
	for (const auto& p : prices) {
		for (int i = 0 ; i < k ; ++i) {
			cost[i] = min(cost[i], i == 0 ? p : p - profit[i-1]);
			profit[i] = max(profit[i], p - cost[i]);
			result = max(result, profit[i]);
		}
	}
	return result;
}

