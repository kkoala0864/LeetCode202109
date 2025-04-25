#include <Solution.h>
#include <iostream>
#include <unordered_map>

// dp[i] = sub sequence number which end with idx i
// dp[i] = dp[i] + sum(nums[i], nums[i-1]);

int Solution::sumOfGoodSubsequences(vector<int>& nums) {
	long long result = 0;
	long long mod = 1e9 + 7;
	unordered_map<int, pair<long long, long long>> dp;

	for (const auto& v : nums) {
		if (dp.count(v-1)) {
			dp[v].first += dp[v-1].first;
			dp[v].first %= mod;
			dp[v].second += (dp[v-1].second + (dp[v-1].first * v));
			dp[v].second %= mod;

		}
		if (dp.count(v+1)) {
			dp[v].first += dp[v+1].first;
			dp[v].first %= mod;
			dp[v].second += (dp[v+1].second + (dp[v+1].first * v));
			dp[v].second %= mod;
		}
		++dp[v].first;
		dp[v].second += v;
	}

	for (const auto& v : dp) {
		result += v.second.second;
		result %= mod;
	}
	return result;
}
