#include <Solution.h>

int Solution::stoneGameVII(vector<int>& stones) {
	int size = stones.size();
	vector<int> preSum(1, 0);
	for (int i = 0 ; i < stones.size() ; ++i) {
		preSum.emplace_back(preSum.back() + stones[i]);
	}
	vector<vector<int>> dp(size, vector<int>(size, 0));

	for (int i = 0 ; i < size - 1 ; ++i) {
		dp[i][i+1] = max(stones[i], stones[i+1]);
	}
	for (int i = 3 ; i <= size ; ++i) {
		for (int j = 0 ; (i + j - 1) < size ; ++j) {
			int end = i + j - 1;
			int start = j;
			int lv = (preSum[end + 1] - preSum[j+1]) - dp[j+1][end];
			int rv = (preSum[end] - preSum[j]) - dp[j][end-1];
			dp[j][end] = max(lv, rv);
		}
	}
	return dp[0][size - 1];

}
