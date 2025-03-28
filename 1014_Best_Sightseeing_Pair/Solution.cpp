#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxScoreSightseeingPair(vector<int> &values) {
	vector<int> dp;

	int v = INT_MIN;
	for (int i = 0; i < values.size(); ++i) {
		v = max(v, i + values[i]);
		dp.emplace_back(v);
	}
	int result = INT_MIN;
	for (int i = 1; i < values.size(); ++i) {
		result = max(result, values[i] - i + dp[i - 1]);
	}
	return result;
}
