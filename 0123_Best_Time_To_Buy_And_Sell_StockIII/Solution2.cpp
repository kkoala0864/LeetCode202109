#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;

int Solution::maxProfit2(vector<int>& prices) {
	int cost1 = INT_MAX;
	int profit1 = 0;
	int cost2 = INT_MAX;
	int profit2 = 0;

	for (int i = 0 ; i < prices.size() ; ++i) {
		cost1 = min(cost1, prices[i]);
		profit1 = max(profit1, prices[i] - cost1);
		cost2 = min(cost2, prices[i] - profit1);
		profit2 = max(profit2, prices[i] - cost2);
	}
	return profit2;
}
