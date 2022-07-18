#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

int Solution::kInversePairs(int n, int k) {
	vector<int> dp(k + 1, 0);
	int mod = 1e9 + 7;

	dp[0] = 1;
	for (int i = 1 ; i <= n ; ++i) {
		for (int j = k ; j >= 1 ; --j) {
			int local = 0;
			for (int z = 0 ; z <= min(i-1, j) ; ++z) {
				local = (local + dp[j - z]) % mod;
			}
			dp[j] = local;
		}
	}
	return dp[k];
}
