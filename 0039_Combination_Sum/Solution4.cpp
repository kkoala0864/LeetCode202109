#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::combinationSum4(vector<int> &candidates, int target) {
	vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
	dp[0].push_back({});
	for (const auto &candidate : candidates) {
		for (int j = candidate; j <= target; ++j) {
			for (auto &ele : dp[j - candidate]) {
				vector<int> tmp = ele;
				tmp.emplace_back(candidate);
				dp[j].emplace_back(tmp);
			}
		}
	}
	return dp[target];
}
