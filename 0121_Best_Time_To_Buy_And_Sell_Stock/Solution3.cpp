#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

int Solution::maxProfit3(vector<int>& prices) {
	int cost = INT_MAX;
	int result = 0;
	for (int i = 0 ; i < prices.size() ; ++i) {
		cost = min(cost, prices[i]);
		result = max(result, prices[i] - cost);
	}
	return result;
}
