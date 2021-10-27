#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;

int check(const vector<vector<int>>& dp, int x, int y) {
	if (x >= dp.size() || y >= dp[0].size()) {
		return INT_MAX;
	} else {
		return dp[x][y];
	}
}

int Solution::minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>> dp(m, vector<int>(n, 0));
	for (int i = m - 1 ; i >= 0 ; --i) {
		for (int j = n - 1 ; j >= 0 ; --j) {
			if (i == m-1 && j == n-1) dp[i][j] = grid[i][j];
			else {
				int right = check(dp, i, j+1);
				int down = check(dp, i+1, j);
				dp[i][j] = min(right, down) + grid[i][j];
			}
		}
	}
	return dp[0][0];
}
