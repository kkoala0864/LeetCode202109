#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using std::vector;
using std::min;

int Solution::nthUglyNumber2(int n) {
	if (n == 1) return 1;
	vector<int> dp(2, 1);
	vector<int> idx = {1, 1, 1};
	vector<int> multiple = {2, 3, 5};

	for (int i = 2 ; i <= n ; ++i) {
		int minVal = INT_MAX;
		vector<int> increase;
		for (int j = 0 ; j < 3 ; ++j) {
			int val = dp[idx[j]] * multiple[j];
			if (val < minVal) {
				increase.clear();
				increase.emplace_back(j);
				minVal = val;
			} else if (val == minVal) {
				increase.emplace_back(j);
			}
		}
		dp.emplace_back(minVal);
		for (const auto& v : increase) ++idx[v];
	}
	return dp[n];
}
