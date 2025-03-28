#include <Solution.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int Solution::checkRecord(int n) {
	vector<int> dp(6, 0), next;
	int mod = 1e9 + 7;
	dp[0] = 1;

	for (int i = 1; i <= n; ++i) {
		next = vector<int>(6, 0);
		for (int j = 0; j < 3; ++j) { // 0: present, 1: late, 2: absent
			if (j == 0) {
				for (int k = 0; k < 3; ++k) {
					next[0] += dp[k];
					next[0] %= mod;
					next[3] += dp[k + 3];
					next[3] %= mod;
				}
			} else if (j == 1) {
				for (int k = 0; k < 2; ++k) {
					next[k + 1] += dp[k];
					next[k + 1] %= mod;
					next[k + 4] += dp[k + 3];
					next[k + 4] %= mod;
				}
			} else if (j == 2) {
				for (int k = 0; k < 3; ++k) {
					next[3] += dp[k];
					next[3] %= mod;
				}
			}
		}
		dp = move(next);
	}
	int result = 0;
	for (const auto &val : dp) {
		result += val;
		result %= mod;
	}
	return result;
}
