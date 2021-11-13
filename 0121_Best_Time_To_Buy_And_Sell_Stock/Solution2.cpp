#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

int Solution::maxProfit2(vector<int>& prices) {
	int cost = INT_MAX;
	int profit = 0;
	for (int i = 0 ; i < prices.size() ; ++i) {
		cost = min(cost, prices[i]);
		profit = max(profit, prices[i] - cost);
	}
	return profit;
}
