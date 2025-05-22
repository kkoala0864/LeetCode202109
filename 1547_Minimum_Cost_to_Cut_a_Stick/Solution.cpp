#include <Solution.h>

int Solution::minCost(int n, vector<int> &cuts) {
	cuts.emplace_back(0);
	cuts.emplace_back(n);
	sort(cuts.begin(), cuts.end());

	int size = cuts.size();
	vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

	for (int i = 1 ; i <= size ; ++i) {
		for (int l = 0 ; (l + i) <= size ; ++l) {
			int r = l + i - 1;
			if (i < 3) {
				dp[l][r] = 0;
			} else {
				for (int k = l; k < r ; ++k) {
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r]);
				}
				dp[l][r] += (cuts[r] - cuts[l]);
			}
		}
	}
	return dp[0][size - 1];
}

