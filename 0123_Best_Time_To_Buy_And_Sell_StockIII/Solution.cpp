#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;
using std::max;

int Solution::maxProfit(vector<int>& prices) {
	int t1Cost = INT_MAX;
	int t2Cost = INT_MAX;
	int t1Profit = 0;
	int t2Profit = 0;

	for (const auto& iter : prices) {
		t1Cost = min(t1Cost, iter);
		t1Profit = max(t1Profit, iter - t1Cost);
		t2Cost = min(t2Cost, iter - t1Profit);
		t2Profit = max(t2Profit, iter - t2Cost);
	}
	return t2Profit;
}
