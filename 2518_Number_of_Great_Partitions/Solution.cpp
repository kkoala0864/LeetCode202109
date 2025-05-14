#include <Solution.h>

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;
	long long v = quickPow(x, n >> 1, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

int Solution::countPartitions(vector<int>& nums, int k) {
	long long sum = 0;
	for (const auto& v : nums) {
		sum += v;
		if (sum >= 2 * k) break;
	}
	if (sum < 2 * k) return 0;

	vector<int> dp(k, 0);
	long long mod = 1e9 + 7;
	dp[0] = 1;

	for (const auto& v : nums) {
		for (int i = k-1 ; i >= v ; --i) {
			dp[i] += dp[i-v];
			dp[i] %= mod;
		}
	}

	long long smallThanK = 0;
	for (const auto& v : dp) {
		smallThanK += v;
		smallThanK %= mod;
	}
	long long total = quickPow(2, nums.size(), mod);
	return (total - (smallThanK * 2 % mod) + mod) % mod;
}
