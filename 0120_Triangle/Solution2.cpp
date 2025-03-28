#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

int Solution::minimumTotal2(vector<vector<int>> &triangle) {
	vector<int> dp;
	for (const auto &val : triangle[triangle.size() - 1])
		dp.emplace_back(val);
	for (int i = triangle.size() - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
		}
	}
	return dp[0];
}
