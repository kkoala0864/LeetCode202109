#include <Solution.h>

int quickPow(int x, int n) {
	if (n == 0) return 1;
	long long v = quickPow(x, n /2);
	long long vv = v * v;
	return n & 1 ? vv * x : vv;
}

int Solution::numberOfWays(int n, int x) {
	vector<int> dp(n + 1, 0);
	int mod = 1e9 + 7;
	dp[0] = 1;

	for (int i = 1 ; quickPow(i, x) <= n ; ++i) {
		auto next = dp;
		int v = quickPow(i, x);
		for (int j = n ; j >= v ; --j) {
			next[j] += dp[j - v];
			next[j] %= mod;
		}
		dp = move(next);
	}
	return dp.back();
}
