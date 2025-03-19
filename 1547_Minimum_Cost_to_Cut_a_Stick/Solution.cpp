#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;
using std::min;
using std::cout;
using std::endl;

int Solution::minCost(int n, vector<int>& cuts) {
	cuts.emplace_back(0);
	cuts.emplace_back(n);
	sort(cuts.begin(), cuts.end());

	int size = cuts.size();
	vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

	for (int sz = 1 ; sz <= size ; ++sz) {
		for (int l = 0 ; (l + sz) <= size ; ++l) {
			int r = l + sz - 1;
			if (sz <= 3) {
				dp[l][r] = 0;
			} else {
				for (int i = l ; i < r ; ++i) {
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r]);
				}
			}
			if (sz >= 3) dp[l][r] += (cuts[r] - cuts[l]);
		}
	}
	return dp[0][size-1];
}
