#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countGoodStrings(int low, int high, int zero, int one) {
	vector<int> dp(high + 1, 0);

	int result = 0;
	int mod = 1e9 + 7;
	dp[0] = 1;

	for (int i = 0 ; i <= high ; ++i) {
		if (i + zero <= high) {
			dp[i + zero] += dp[i];
			dp[i + zero] %= mod;
		}
		if (i + one <= high) {
			dp[i + one] += dp[i];
			dp[i + one] %= mod;
		}
		if (i >= low && i <= high) {
			result += dp[i];
			result %= mod;
		}
	}
	return result;
}
