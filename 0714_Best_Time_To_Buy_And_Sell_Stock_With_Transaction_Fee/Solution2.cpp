#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxProfit2(vector<int> &prices, int fee) {
	vector<int> hold(prices.size(), 0);
	vector<int> free(prices.size(), 0);

	hold[0] = -prices[0];
	for (int i = 1; i < prices.size(); ++i) {
		free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
		hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
	}
	return free.back();
}
