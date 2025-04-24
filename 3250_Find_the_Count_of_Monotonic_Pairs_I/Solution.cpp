#include <Solution.h>
#include <iostream>
#include <unordered_map>

int Solution::countOfPairs(vector<int>& nums) {
	int maxV = 0;
	for (const auto& v : nums) maxV = max(maxV, v);

	vector<vector<long long>> dp(maxV + 1, vector<long long>(maxV + 1, 0));
	long long mod = 1e9 + 7;

	for (int i = 0 ; i <= nums[0] ; ++i) {
		dp[i][nums[0]-i] = 1;
	}
	for (int ni = 1 ; ni < nums.size() ; ++ni) {
		vector<vector<long long>> next(maxV + 1, vector<long long>(maxV + 1, 0));

		for (int i = 0 ; i <= nums[ni] ; ++i) {
			int c1 = i;
			int c2 = nums[ni] - c1;
			for (int p1 = 0 ; p1 <= min(nums[ni-1],c1) ; ++p1) {
				int p2 = nums[ni-1] - p1;
				if (c2 > p2) continue;
				next[c1][c2] += dp[p1][p2];
				next[c1][c2] %= mod;
			}
		}
		dp = move(next);
	}
	long long result = 0;
	for (int i = 0 ; i <= maxV ; ++i) {
		for (int j = 0 ; j <= maxV ; ++j) {
			result += dp[i][j];
			result %= mod;
		}
	}
	return result;
}
