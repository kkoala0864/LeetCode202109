#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxProfit2(vector<int>& prices) {
	int hold = -prices[0];
	int sold = 0;

	for (int i = 1 ; i < prices.size() ; ++i) {
		int tmp = hold;
		hold = max(hold, sold - prices[i]);
		sold = max(sold, tmp + prices[i]);
	}
	return sold;
}

