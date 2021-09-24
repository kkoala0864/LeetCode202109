#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

int Solution::maxProfit(vector<int>& prices) {
	int minVal = prices[0];
	int result = INT_MIN;

	for (const auto& iter : prices) {
		minVal = min(minVal, iter);
		result = max(result, iter - minVal);
	}

	return result;
}
