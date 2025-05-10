#include <Solution.h>

// choose k object form n types which sum of k is target
int Solution::waysToReachTarget(int target, vector<vector<int>>& types) {
	vector<long long> dp(target + 1, 0);
	vector<long long> next(target + 1, 0);

	long long mod = 1e9 + 7;

	dp[0] = next[0] = 1;
	for (const auto& t : types) {
		int num = t[0];
		int val = t[1];

		for (int i = 0 ; i <= target ; ++i) {
			for (int j = 1 ; j <= num && (i + j * val) <= target ; ++j) {
				next[i + j * val] += dp[i];
				next[i + j * val] %= mod;
			}
		}
		dp = next;
	}
	return dp.back();
}
