#include <Solution.h>
#include <iostream>
#include <vector>
// maxValue : 315
// M : 1 3 3 5 7
// n = 5
// how many distinct permutaions with len n with 2 same number (allowing multiple number in same place)
// dp[i][j] = number of distinct permuation with len i to place j same number
// dp[i][j] = dp[i-1][j-t], t = 0, 1, 2 .... j

vector<int> getPrimeFactor(int maxValue) {
	vector<bool> p(maxValue + 1, false);

	for (int i = 2 ; (i * i) <= maxValue ; ++i) {
		if (p[i]) continue;
		for (int j = i ; (i * j) <= maxValue ; ++j) {
			p[i*j] = true;
		}
	}
	vector<int> pf;
	for (int i = 2 ; i <= maxValue ; ++i) {
		if (p[i]) continue;
		pf.emplace_back(i);
	}
	return pf;
}

int Solution::idealArrays(int n, int maxValue) {
	long long mod = 1e9 + 7;
	auto pf = getPrimeFactor(maxValue);

	vector<vector<long long>> dp(n + 1, vector<long long>(15, 0));
	dp[0][0] = 1;
	for (int i = 1 ; i <= n ; ++i) {
		dp[i][0] = 1;
		for (int j = 1 ; j < 15 ; ++j) {
			for (int k = 0 ; k <= j ; ++k) {
				dp[i][j] += dp[i-1][j-k];
				dp[i][j] %= mod;
			}
		}
	}

	long long result = 0;
	for (int i = 1 ; i <= maxValue ; ++i) {
		int cur = i;

		long long local = 1;
		for (const auto& p : pf) {
			int count = 0;
			while (cur > 1 && cur % p == 0) {
				++count;
				cur /= p;;
			}
			local *= dp[n][count];
			local %= mod;
		}
		result += local;
		result %= mod;
	}
	return result;
}
