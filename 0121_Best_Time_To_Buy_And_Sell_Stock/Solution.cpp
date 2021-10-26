#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

int Solution::maxProfit(vector<int>& prices) {
	int cost = prices[0];
	int profit = 0;
	for (const auto& iter : prices) {
		cost = min(cost, iter);
		profit = max(profit, iter - cost);
	}
	return profit;
}
