#include <Solution.h>

int Solution::mergeStones(vector<int>& stones, int k) {
	int size = stones.size();

	if ((size - 1) % (k - 1)) return -1;

	vector<int> preSum(1, 0);
	for (const auto& v : stones) {
		preSum.emplace_back(preSum.back() + v);
	}
	vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>(k + 1, INT_MAX)));
	for (int i = 0 ; i < size ; ++i) {
		dp[i][i][1] = 0;
	}

	for (int s = 2 ; s <= size ; ++s) {
		for (int l = 0 ; (l + s - 1) < size ; ++l) {
			int r = l + s - 1;
			for (int z = 2 ; z <= k ; ++z) {
				if (z > s) continue;
				for (int m = l ; m < r ; ++m) {
					if (dp[l][m][1] == INT_MAX || dp[m+1][r][z-1] == INT_MAX) continue;
					dp[l][r][z] = min(dp[l][r][z], dp[l][m][1] + dp[m+1][r][z-1]);
				}
			}
			if (dp[l][r][k] != INT_MAX) {
				dp[l][r][1] = (dp[l][r][k] + preSum[r+1] - preSum[l]);
			}
		}
	}

	return dp[0][size-1][1] == INT_MAX ? -1 : dp[0][size-1][1];
}
