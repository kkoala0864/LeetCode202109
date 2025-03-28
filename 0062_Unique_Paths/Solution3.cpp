#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::uniquePaths3(int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int x = m - 1; x >= 0; --x) {
		for (int y = n - 1; y >= 0; --y) {
			if (x == m - 1 && y == n - 1)
				dp[x][y] = 1;
			else
				dp[x][y] = dp[x + 1][y] + dp[x][y + 1];
		}
	}
	return dp[0][0];
}
