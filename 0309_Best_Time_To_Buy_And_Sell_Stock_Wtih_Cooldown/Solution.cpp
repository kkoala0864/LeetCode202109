#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxProfit(vector<int> &prices) {
	int size = prices.size();
	if (size <= 0)
		return 0;
	int hold = -prices[0], sell = 0, reset = 0;
	for (int i = 1; i < size; ++i) {
		int tmp = hold;
		hold = max(hold, reset - prices[i]);
		reset = max(reset, sell);
		sell = tmp + prices[i];
	}
	return max(sell, reset);
}
