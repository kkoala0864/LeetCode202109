#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

int Solution::numRollsToTarget(int n, int k, int target) {
	vector<int> dp(target + 1, 0);
	vector<int> last(target + 1, 0);
	int mod = 1e9 + 7;

	dp[0] = 1;
	for (int t = 1 ; t <= n ; ++t) {
		last = dp;
		fill(dp.begin(), dp.end(), 0);
		for (int diceIdx = 1 ; diceIdx <= k ; ++diceIdx) {
			for (int i = 1 ; i <= min(target, t * k) ; ++i) {
				if (i >= diceIdx && last[i-diceIdx] > 0) {
					dp[i] += last[i-diceIdx];
					dp[i] %= mod;
				}
			}
		}
	}
	return dp[target];
}
