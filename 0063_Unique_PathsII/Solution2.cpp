#include <Solution.h>
#include <iostream>

int Solution::uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (obstacleGrid[i][j] == 1) {
				dp[i][j] = 0;
				continue;
			}
			if (i < m - 1)
				dp[i + 1][j] += dp[i][j];
			if (j < n - 1)
				dp[i][j + 1] += dp[i][j];
		}
	}
	return dp[m - 1][n - 1];
}
