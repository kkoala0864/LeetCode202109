#include <Solution.h>


// S(n,k) = k⋅S(n−1,k) + S(n−1,k−1), S(0,0)=1,S(n,0)=S(0,k)=0
int Solution::waysToDistribute(int n, int k) {
	long long mod = 1e9 + 7;
	if (k > n) return 0;

	vector<long long> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 1 ; i <= n ; ++i) {
		vector<long long> next(k + 1, 0);
		for (int j = 1 ; j <= min(i, k) ; ++j) {
			next[j] = ((j * dp[j]) + dp[j-1]) % mod;
		}
		dp = std::move(next);
	}
	return dp[k];
}
