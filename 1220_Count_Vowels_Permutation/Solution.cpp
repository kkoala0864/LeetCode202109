#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countVowelPermutation(int n) {
	vector<int> prev(5, 1), dp(5, 0);
	int mod = 1e9 + 7;
	for (int i = 1 ; i < n ; ++i) {
		for (int j = 0 ; j < 5 ; ++j) {
			if (j == 0) {
				dp[j] = ((prev[1] + prev[2]) % mod + prev[4]) % mod;
			} else if (j == 1) {
				dp[j] = (prev[0] + prev[2]) % mod;
			} else if (j == 2) {
				dp[j] = (prev[1] + prev[3]) % mod;
			} else if (j == 3) {
				dp[j] = prev[2] % mod;
			} else if (j == 4) {
				dp[j] = (prev[2] + prev[3]) % mod;
			}
		}
		swap(prev, dp);
	}
	int result = 0;
	for (int i = 0 ; i < 5 ; ++i) {
		result += (prev[i] % mod);
		result %= mod;
	}
	return result;
}
