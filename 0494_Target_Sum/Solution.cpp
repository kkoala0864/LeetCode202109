#include <Solution.h>

int Solution::findTargetSumWays(vector<int> &nums, int target) {
	unordered_map<int, int> dp, next;

	dp[0] = 1;

	for (const auto& v : nums) {
		for (const auto& e : dp) {
			next[e.first + v] += e.second;
			next[e.first - v] += e.second;
		}
		dp = move(next);
	}
	return dp[target];
}
