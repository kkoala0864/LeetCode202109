#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;
/*
int Solution::maxProfit(vector<int>& prices) {
	vector<int> dp(prices.size() + 1, 0);

	for (int i = 1 ; i <= prices.size() ; ++i) {
		int local = 0;
		for (int j = i-2 ; j >= 0 ; --j) {
			int profit = prices[i-1] - prices[j];
			int beforePart = j-1 >= 0 ? dp[j-1] : 0;
			local = max(local, profit + beforePart);
		}
		dp[i] = max(dp[i-1], local);
		dp[i] = max(dp[i], (i - 2) < 0 ? 0 : dp[i-2]);
	}
	return dp[prices.size()];
}
*/
int Solution::maxProfit(vector<int>& prices) {
	int size = prices.size();
	if (size <= 0) return 0;
	int hold = -prices[0], sell = 0, reset = 0;
	for (int i = 1 ; i < size ; ++i) {
		int tmp = hold;
		hold = max(hold, reset-prices[i]);
		reset = max(reset, sell);
		sell = tmp + prices[i];
	}
	return max(sell, reset);
}
