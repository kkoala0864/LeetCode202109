#include <Solution.h>

int Solution::numberWays(vector<vector<int>>& hats) {
	vector<vector<int>> hat(41, vector<int>());

	for (int i = 0 ; i < hats.size() ; ++i) {
		for (const auto& p : hats[i]) {
			hat[p].emplace_back(i);
		}
	}
	long long result = 0;
	long long mod = 1e9 + 7;
	int size = hats.size();
	vector<int> dp(1 << size, 0);
	dp[0] = 1;
	auto next = dp;

	for (int i = 1 ; i <= 40 ; ++i) {
		if (hat[i].empty()) continue;
		for (int j = 0 ; j < (1 << size) ; ++j) {
			for (const auto& p : hat[i]) {
				if (j & (1 << p)) continue;
				next[j | (1 << p)] += dp[j];
				next[j | (1 << p)] %= mod;
			}
		}
		dp = next;
	}
	return dp.back();
}
// TC : O(40 * 40 * 1024) ~= (10^6)
// SC : O(1024)
