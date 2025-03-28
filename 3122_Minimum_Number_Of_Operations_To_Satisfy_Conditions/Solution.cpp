#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

int Solution::minimumOperations(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>> colVal(n, vector<int>(10, 0));

	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			++colVal[j][grid[i][j]];
		}
		for (int i = 0; i < 10; ++i) {
			colVal[j][i] = m - colVal[j][i];
		}
	}
	vector<vector<int>> dp(n, vector<int>(10, 0));
	int result = INT_MAX;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (i == 0) {
				dp[i][j] = colVal[i][j];
			} else {
				int minLast = INT_MAX;
				for (int k = 0; k < 10; ++k) {
					if (j == k)
						continue;
					minLast = min(minLast, dp[i - 1][k]);
				}
				dp[i][j] = colVal[i][j] + minLast;
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		result = min(result, dp.back()[i]);
	}
	return result;
}
