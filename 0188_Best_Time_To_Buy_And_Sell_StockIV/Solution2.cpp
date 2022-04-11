#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;

int Solution::maxProfit2(int k, vector<int>& prices) {
	if (k == 0) return 0;
	vector<int> cost(k, INT_MAX);
	vector<int> profit(k, 0);

	int result = 0;
	for (const auto& iter : prices){
		for (int i = 0 ; i < k ; ++i) {
			cost[i] = min(cost[i], i == 0 ? iter : iter - profit[i-1]);
			profit[i] = max(profit[i], iter - cost[i]);
			result = max(profit[i], result);
		}
	}
	return result;
}
