#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxProfit(vector<int> &prices) {
	int sell = 0;
	int hold = -prices[0];

	for (int i = 1; i < prices.size(); ++i) {
		int tmp = hold;
		hold = max(tmp, sell - prices[i]);
		sell = max(sell, tmp + prices[i]);
	}
	return sell;
}
