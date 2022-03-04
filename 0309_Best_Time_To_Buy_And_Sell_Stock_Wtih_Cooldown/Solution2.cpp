#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxProfit2(vector<int>& prices) {
	int hold = -prices[0], sell = 0, reset = 0;

	for (int i = 1 ; i < prices.size() ; ++i) {
		int tmp = hold;
		hold = max(hold, reset - prices[i]);
		reset = max(reset, sell);
		sell = hold + prices[i];
	}
	return max(sell, reset);
}
