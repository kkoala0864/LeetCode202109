#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countGoodStrings(int low, int high, int zero, int one) {
	vector<int> dp(high + 1, 0);

	int mod = 1e9 + 7;
	dp[0] = 1;
	int result = 0;

	for (int i = 1 ; i <= high ; ++i) {
		if (i - zero >= 0) {
			dp[i] += dp[i-zero];
			dp[i] %= mod;
		}
		if (i - one >= 0) {
			dp[i] += dp[i-one];
			dp[i] %= mod;
		}

		if (i >= low) {
			result += dp[i];
			result %= mod;
		}
	}
	return result;
}
