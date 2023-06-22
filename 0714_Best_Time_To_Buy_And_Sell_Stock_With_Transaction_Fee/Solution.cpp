#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::max;

int Solution::maxProfit(vector<int>& prices, int fee) {
	int size = prices.size();
	vector<int> hold(size,0), free(size, 0);

	hold[0] = -prices[0];
	int result = 0;
	for (int i = 1 ; i < size ; ++i) {
		free[i] = max(free[i-1], hold[i-1] + prices[i] - fee);
		hold[i] = max(hold[i-1], free[i-1] - prices[i]);
	}
	return free.back();
}
